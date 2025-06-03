/**
 * @file json.hpp
 * @brief JSON parser and serializer implementation
 * @details Features:
 *          - JSON value representation (objects, arrays, primitives)
 *          - Parsing from string and serialization to string
 *          - Type-safe value access
 * @note Third-party library included in project
 */
#pragma once

#include <cstdint>
#include <cmath>
#include <cctype>
#include <string>
#include <deque>
#include <map>
#include <type_traits>
#include <initializer_list>
#include <ostream>
#include <iostream>

/**
 * @namespace json
 * @brief Namespace for JSON-related classes and functions.
 */
namespace json {

using std::map;
using std::deque;
using std::string;
using std::enable_if;
using std::initializer_list;
using std::is_same;
using std::is_convertible;
using std::is_integral;
using std::is_floating_point;

/**
 * @namespace
 * @brief Anonymous namespace for internal JSON utility functions.
 */
namespace {
/**
 * @brief Escapes special characters in a string for JSON formatting.
 * @param str The input string to escape.
 * @return The escaped string suitable for JSON output.
 */
string json_escape(const string &str) {
	string output;
	for (unsigned i = 0; i < str.length(); ++i)
		switch (str[i]) {
		case '\"':
			output += "\\\"";
			break;
		case '\\':
			output += "\\\\";
			break;
		case '\b':
			output += "\\b";
			break;
		case '\f':
			output += "\\f";
			break;
		case '\n':
			output += "\\n";
			break;
		case '\r':
			output += "\\r";
			break;
		case '\t':
			output += "\\t";
			break;
		default:
			output += str[i];
			break;
		}
	return output;
}
}

/**
 * @class JSON
 * @brief Class for representing and manipulating JSON data.
 * @details Supports JSON types including null, object, array, string, floating-point, integer, and boolean.
 */
class JSON {
	/**
	 * @union BackingData
	 * @brief Union to store different JSON data types.
	 */
	union BackingData {
		/**
		 * @brief Constructor for floating-point value.
		 * @param d The double value to store.
		 */
		BackingData(double d) :
				Float(d) {
		}
		/**
		 * @brief Constructor for integer value.
		 * @param l The long value to store.
		 */
		BackingData(long l) :
				Int(l) {
		}
		/**
		 * @brief Constructor for boolean value.
		 * @param b The boolean value to store.
		 */
		BackingData(bool b) :
				Bool(b) {
		}
		/**
		 * @brief Constructor for string value.
		 * @param s The string value to store.
		 */
		BackingData(string s) :
				String(new string(s)) {
		}
		/**
		 * @brief Default constructor initializing to zero.
		 */
		BackingData() :
				Int(0) {
		}

		/// Pointer to a deque of JSON objects for arrays.
		deque<JSON> *List;
		/// Pointer to a map of string-JSON pairs for objects.
		map<string, JSON> *Map;
		/// Pointer to a string for string values.
		string *String;
		/// Floating-point value.
		double Float;
		/// Integer value.
		long Int;
		/// Boolean value.
		bool Bool;
	} Internal;

public:
	/**
	 * @enum Class
	 * @brief Enumerates the possible JSON data types.
	 */
	enum class Class {
		Null,    ///< Null value
		Object,  ///< JSON object
		Array,   ///< JSON array
		String,  ///< String value
		Floating,  ///< Floating-point number
		Integral,  ///< Integer number
		Boolean  ///< Boolean value
	};

	/**
	 * @class JSONWrapper
	 * @brief Wrapper for iterating over JSON containers (map or deque).
	 * @tparam Container The type of container (map or deque).
	 */
	template<typename Container>
	class JSONWrapper {
		/// Pointer to the wrapped container.
		Container *object;

	public:
		/**
		 * @brief Constructor for JSONWrapper.
		 * @param val Pointer to the container to wrap.
		 */
		JSONWrapper(Container *val) :
				object(val) {
		}
		/**
		 * @brief Constructor for null JSONWrapper.
		 * @param nullptr_t Null pointer.
		 */
		JSONWrapper(std::nullptr_t) :
				object(nullptr) {
		}
		/**
		 * @brief Returns an iterator to the beginning of the container.
		 * @return Iterator to the beginning of the container.
		 */
		typename Container::iterator begin() {
			return object ? object->begin() : typename Container::iterator();
		}
		/**
		 * @brief Returns an iterator to the end of the container.
		 * @return Iterator to the end of the container.
		 */
		typename Container::iterator end() {
			return object ? object->end() : typename Container::iterator();
		}
		/**
		 * @brief Returns a const iterator to the beginning of the container.
		 * @return Const iterator to the beginning of the container.
		 */
		typename Container::const_iterator begin() const {
			return object ? object->begin() : typename Container::iterator();
		}
		/**
		 * @brief Returns a const iterator to the end of the container.
		 * @return Const iterator to the end of the container.
		 */
		typename Container::const_iterator end() const {
			return object ? object->end() : typename Container::iterator();
		}
	};

	/**
	 * @class JSONConstWrapper
	 * @brief Const wrapper for iterating over JSON containers (map or deque).
	 * @tparam Container The type of container (map or deque).
	 */
	template<typename Container>
	class JSONConstWrapper {
		/// Pointer to the wrapped const container.
		const Container *object;

	public:
		/**
		 * @brief Constructor for JSONConstWrapper.
		 * @param val Pointer to the const container to wrap.
		 */
		JSONConstWrapper(const Container *val) :
				object(val) {
		}
		/**
		 * @brief Constructor for null JSONConstWrapper.
		 * @param nullptr_t Null pointer.
		 */
		JSONConstWrapper(std::nullptr_t) :
				object(nullptr) {
		}
		/**
		 * @brief Returns a const iterator to the beginning of the container.
		 * @return Const iterator to the beginning of the container.
		 */
		typename Container::const_iterator begin() const {
			return object ?
					object->begin() : typename Container::const_iterator();
		}
		/**
		 * @brief Returns a const iterator to the end of the container.
		 * @return Const iterator to the end of the container.
		 */
		typename Container::const_iterator end() const {
			return object ? object->end() : typename Container::const_iterator();
		}
	};
	/**
	 * @brief Default constructor for JSON, initializes to null.
	 */
	JSON() :
			Internal(), Type(Class::Null) {
	}

	/**
	 * @brief Constructor for JSON from an initializer list.
	 * @param list Initializer list of JSON objects representing key-value pairs for an object.
	 */
	JSON(initializer_list<JSON> list) :
			JSON() {
		SetType(Class::Object);
		for (auto i = list.begin(), e = list.end(); i != e; ++i, ++i)
			operator[](i->ToString()) = *std::next(i);
	}
	/**
	 * @brief Move constructor for JSON.
	 * @param other Another JSON object to move from.
	 */
	JSON(JSON &&other) :
			Internal(other.Internal), Type(other.Type) {
		other.Type = Class::Null;
		other.Internal.Map = nullptr;
	}

	/**
	 * @brief Move assignment operator for JSON.
	 * @param other Another JSON object to move from.
	 * @return Reference to this JSON object.
	 */
	JSON& operator=(JSON &&other) {
		ClearInternal();
		Internal = other.Internal;
		Type = other.Type;
		other.Internal.Map = nullptr;
		other.Type = Class::Null;
		return *this;
	}

	/**
	 * @brief Copy constructor for JSON.
	 * @param other Another JSON object to copy from.
	 */
	JSON(const JSON &other) {
		switch (other.Type) {
		case Class::Object:
			Internal.Map = new map<string, JSON>(other.Internal.Map->begin(),
					other.Internal.Map->end());
			break;
		case Class::Array:
			Internal.List = new deque<JSON>(other.Internal.List->begin(),
					other.Internal.List->end());
			break;
		case Class::String:
			Internal.String = new string(*other.Internal.String);
			break;
		default:
			Internal = other.Internal;
		}
		Type = other.Type;
	}
	/**
	 * @brief Copy assignment operator for JSON.
	 * @param other Another JSON object to copy from.
	 * @return Reference to this JSON object.
	 */
	JSON& operator=(const JSON &other) {
		ClearInternal();
		switch (other.Type) {
		case Class::Object:
			Internal.Map = new map<string, JSON>(other.Internal.Map->begin(),
					other.Internal.Map->end());
			break;
		case Class::Array:
			Internal.List = new deque<JSON>(other.Internal.List->begin(),
					other.Internal.List->end());
			break;
		case Class::String:
			Internal.String = new string(*other.Internal.String);
			break;
		default:
			Internal = other.Internal;
		}
		Type = other.Type;
		return *this;
	}

	/**
	 * @brief Destructor for JSON.
	 * @details Frees allocated memory based on the JSON type.
	 */
	~JSON() {
		switch (Type) {
		case Class::Array:
			delete Internal.List;
			break;
		case Class::Object:
			delete Internal.Map;
			break;
		case Class::String:
			delete Internal.String;
			break;
		default:
			;
		}
	}

	/**
	 * @brief Constructor for JSON from a boolean value.
	 * @tparam T Type of the value (must be bool).
	 * @param b The boolean value.
	 */
	template<typename T>
	JSON(T b, typename enable_if<is_same<T, bool>::value>::type* = 0) :
			Internal(b), Type(Class::Boolean) {
	}

	/**
	 * @brief Constructor for JSON from an integral value.
	 * @tparam T Type of the value (must be integral and not bool).
	 * @param i The integral value.
	 */
	template<typename T>
	JSON(T i,
			typename enable_if<is_integral<T>::value && !is_same<T, bool>::value>::type* =
					0) :
			Internal((long) i), Type(Class::Integral) {
	}

	/**
	 * @brief Constructor for JSON from a floating-point value.
	 * @tparam T Type of the value (must be floating-point).
	 * @param f The floating-point value.
	 */
	template<typename T>
	JSON(T f, typename enable_if<is_floating_point<T>::value>::type* = 0) :
			Internal((double) f), Type(Class::Floating) {
	}

	/**
	 * @brief Constructor for JSON from a string-convertible value.
	 * @tparam T Type of the value (must be convertible to string).
	 * @param s The string value.
	 */
	template<typename T>
	JSON(T s, typename enable_if<is_convertible<T, string>::value>::type* = 0) :
			Internal(string(s)), Type(Class::String) {
	}

	/**
	 * @brief Constructor for JSON null value.
	 * @param nullptr_t Null pointer.
	 */
	JSON(std::nullptr_t) :
			Internal(), Type(Class::Null) {
	}

	/**
	 * @brief Creates a JSON object of the specified type.
	 * @param type The JSON type to create.
	 * @return A JSON object of the specified type.
	 */
	static JSON Make(Class type) {
		JSON ret;
		ret.SetType(type);
		return ret;
	}

	/**
	 * @brief Loads a JSON object from a string.
	 * @param str The JSON string to parse.
	 * @return The parsed JSON object.
	 */
	static JSON Load(const string&);

	/**
	 * @brief Appends a value to a JSON array.
	 * @tparam T Type of the value to append.
	 * @param arg The value to append.
	 */
	template<typename T>
	void append(T arg) {
		SetType(Class::Array);
		Internal.List->emplace_back(arg);
	}

	/**
	 * @brief Appends multiple values to a JSON array.
	 * @tparam T Type of the first value.
	 * @tparam U Types of the remaining values.
	 * @param arg The first value to append.
	 * @param args The remaining values to append.
	 */
	template<typename T, typename ... U>
	void append(T arg, U ... args) {
		append(arg);
		append(args...);
	}

	/**
	 * @brief Assigns a boolean value to the JSON object.
	 * @tparam T Type of the value (must be bool).
	 * @param b The boolean value.
	 * @return Reference to this JSON object.
	 */
	template<typename T>
	typename enable_if<is_same<T, bool>::value, JSON&>::type operator=(T b) {
		SetType(Class::Boolean);
		Internal.Bool = b;
		return *this;
	}

	/**
	 * @brief Assigns an integral value to the JSON object.
	 * @tparam T Type of the value (must be integral and not bool).
	 * @param i The integral value.
	 * @return Reference to this JSON object.
	 */
	template<typename T>
	typename enable_if<is_integral<T>::value && !is_same<T, bool>::value, JSON&>::type operator=(
			T i) {
		SetType(Class::Integral);
		Internal.Int = i;
		return *this;
	}

	/**
	 * @brief Assigns a floating-point value to the JSON object.
	 * @tparam T Type of the value (must be floating-point).
	 * @param f The floating-point value.
	 * @return Reference to this JSON object.
	 */
	template<typename T>
	typename enable_if<is_floating_point<T>::value, JSON&>::type operator=(
			T f) {
		SetType(Class::Floating);
		Internal.Float = f;
		return *this;
	}

	/**
	 * @brief Assigns a string value to the JSON object.
	 * @tparam T Type of the value (must be convertible to string).
	 * @param s The string value.
	 * @return Reference to this JSON object.
	 */
	template<typename T>
	typename enable_if<is_convertible<T, string>::value, JSON&>::type operator=(
			T s) {
		SetType(Class::String);
		*Internal.String = string(s);
		return *this;
	}

	/**
	 * @brief Accesses or creates a JSON object by key.
	 * @param key The key for the JSON object.
	 * @return Reference to the JSON object associated with the key.
	 */
	JSON& operator[](const string &key) {
		SetType(Class::Object);
		return Internal.Map->operator[](key);
	}

	/**
	 * @brief Accesses or creates a JSON array element by index.
	 * @param index The index of the array element.
	 * @return Reference to the JSON object at the specified index.
	 */
	JSON& operator[](unsigned index) {
		SetType(Class::Array);
		if (index >= Internal.List->size())
			Internal.List->resize(index + 1);
		return Internal.List->operator[](index);
	}

	/**
	 * @brief Accesses a JSON object by key.
	 * @param key The key for the JSON object.
	 * @return Reference to the JSON object associated with the key.
	 */
	JSON& at(const string &key) {
		return operator[](key);
	}

	/**
	 * @brief Accesses a JSON object by key (const version).
	 * @param key The key for the JSON object.
	 * @return Const reference to the JSON object associated with the key.
	 */
	const JSON& at(const string &key) const {
		return Internal.Map->at(key);
	}

	/**
	 *  @brief Accesses a JSON array element by index.
	 * @param index The index of the array element.
	 * @return Reference to the JSON object at the specified index.
	 */
	JSON& at(unsigned index) {
		return operator[](index);
	}

	/**
	 * @brief Accesses a JSON array element by index (const version).
	 * @param index The index of the array element.
	 * @return Const reference to the JSON object at the specified index.
	 */
	const JSON& at(unsigned index) const {
		return Internal.List->at(index);
	}

	/**
	 * @brief Returns the length of a JSON array.
	 * @return The number of elements in the array, or -1 if not an array.
	 */
	int length() const {
		if (Type == Class::Array)
			return Internal.List->size();
		else
			return -1;
	}

	/**
	 * @brief Checks if a key exists in a JSON object.
	 * @param key The key to check.
	 * @return True if the key exists, false otherwise.
	 */
	bool hasKey(const string &key) const {
		if (Type == Class::Object)
			return Internal.Map->find(key) != Internal.Map->end();
		return false;
	}

	/**
	 * @brief Returns the size of a JSON object or array.
	 * @return The number of elements in the object or array, or -1 if neither.
	 */
	int size() const {
		if (Type == Class::Object)
			return Internal.Map->size();
		else if (Type == Class::Array)
			return Internal.List->size();
		else
			return -1;
	}

	/**
	 * @brief Returns the type of the JSON object.
	 * @return The JSON type as a Class enum value.
	 */
	Class JSONType() const {
		return Type;
	}

	/**
	 * @brief Checks if the JSON object is null.
	 * @return True if the JSON object is null, false otherwise.
	 */
	bool IsNull() const {
		return Type == Class::Null;
	}

	/**
	 * @brief Converts the JSON object to a string.
	 * @return The string value, or empty string if not a string type.
	 */
	string ToString() const {
		bool b;
		return std::move(ToString(b));
	}

	/**
	 * @brief Converts the JSON object to a string with success indicator.
	 * @param ok Set to true if the JSON object is a string, false otherwise.
	 * @return The string value, or empty string if not a string type.
	 */
	string ToString(bool &ok) const {
		ok = (Type == Class::String);
		return ok ? std::move(json_escape(*Internal.String)) : string("");
	}

	/**
	 * @brief Converts the JSON object to a floating-point number.
	 * @return The floating-point value, or 0.0 if not a floating-point type.
	 */
	double ToFloat() const {
		bool b;
		return ToFloat(b);
	}

	/**
	 * @brief Converts the JSON object to a floating-point number with success indicator.
	 * @param ok Set to true if the JSON object is a floating-point number, false otherwise.
	 * @return The floating-point value, or 0.0 if not a floating-point type.
	 */
	double ToFloat(bool &ok) const {
		ok = (Type == Class::Floating);
		return ok ? Internal.Float : 0.0;
	}

	/**
	 * @brief Converts the JSON object to an integer.
	 * @return The integer value, or 0 if not an integer type.
	 */
	long ToInt() const {
		bool b;
		return ToInt(b);
	}

	/**
	 * @brief Converts the JSON object to an integer with success indicator.
	 * @param ok Set to true if the JSON object is an integer, false otherwise.
	 * @return The integer value, or 0 if not an integer type.
	 */
	long ToInt(bool &ok) const {
		ok = (Type == Class::Integral);
		return ok ? Internal.Int : 0;
	}

	/**
	 * @brief Converts the JSON object to a boolean.
	 * @return The boolean value, or false if not a boolean type.
	 */
	bool ToBool() const {
		bool b;
		return ToBool(b);
	}

	/**
	 * @brief Converts the JSON object to a boolean with success indicator.
	 * @param ok Set to true if the JSON object is a boolean, false otherwise.
	 * @return The boolean value, or false if not a boolean type.
	 */
	bool ToBool(bool &ok) const {
		ok = (Type == Class::Boolean);
		return ok ? Internal.Bool : false;
	}

	/**
	 * @brief Returns a wrapper for iterating over a JSON object.
	 * @return JSONWrapper for the object, or null wrapper if not an object.
	 */
	JSONWrapper<map<string, JSON>> ObjectRange() {
		if (Type == Class::Object)
			return JSONWrapper<map<string, JSON>>(Internal.Map);
		return JSONWrapper<map<string, JSON>>(nullptr);
	}

	/**
	 * @brief Returns a wrapper for iterating over a JSON array.
	 * @return JSONWrapper for the array, or null wrapper if not an array.
	 */
	JSONWrapper<deque<JSON>> ArrayRange() {
		if (Type == Class::Array)
			return JSONWrapper<deque<JSON>>(Internal.List);
		return JSONWrapper<deque<JSON>>(nullptr);
	}

	/**
	 * @brief Returns a const wrapper for iterating over a JSON object.
	 * @return JSONConstWrapper for the object, or null wrapper if not an object.
	 */
	JSONConstWrapper<map<string, JSON>> ObjectRange() const {
		if (Type == Class::Object)
			return JSONConstWrapper<map<string, JSON>>(Internal.Map);
		return JSONConstWrapper<map<string, JSON>>(nullptr);
	}

	/**
	 * @brief Returns a const wrapper for iterating over a JSON array.
	 * @return JSONConstWrapper for the array, or null wrapper if not an array.
	 */
	JSONConstWrapper<deque<JSON>> ArrayRange() const {
		if (Type == Class::Array)
			return JSONConstWrapper<deque<JSON>>(Internal.List);
		return JSONConstWrapper<deque<JSON>>(nullptr);
	}

	/**
	 * @brief Dumps the JSON object to a string with formatting.
	 * @param depth The indentation level for nested structures (default: 1).
	 * @param tab The string used for indentation (default: two spaces).
	 * @return The formatted JSON string.
	 */
	string dump(int depth = 1, string tab = "  ") const {
		string pad = "";
		for (int i = 0; i < depth; ++i, pad += tab)
			;

		switch (Type) {
		case Class::Null:
			return "null";
		case Class::Object: {
			string s = "{\n";
			bool skip = true;
			for (auto &p : *Internal.Map) {
				if (!skip)
					s += ",\n";
				s += (pad + "\"" + p.first + "\" : "
						+ p.second.dump(depth + 1, tab));
				skip = false;
			}
			s += ("\n" + pad.erase(0, 2) + "}");
			return s;
		}
		case Class::Array: {
			string s = "[";
			bool skip = true;
			for (auto &p : *Internal.List) {
				if (!skip)
					s += ", ";
				s += p.dump(depth + 1, tab);
				skip = false;
			}
			s += "]";
			return s;
		}
		case Class::String:
			return "\"" + json_escape(*Internal.String) + "\"";
		case Class::Floating:
			return std::to_string(Internal.Float);
		case Class::Integral:
			return std::to_string(Internal.Int);
		case Class::Boolean:
			return Internal.Bool ? "true" : "false";
		default:
			return "";
		}
		return "";
	}

	/**
	 * @brief Friend function to output the JSON object to a stream.
	 * @param os The output stream.
	 * @param json The JSON object to output.
	 * @return Reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream&, const JSON&);

private:
	/**
	 * @brief Sets the type of the JSON object and initializes its storage.
	 * @param type The JSON type to set.
	 */
	void SetType(Class type) {
		if (type == Type)
			return;

		ClearInternal();

		switch (type) {
		case Class::Null:
			Internal.Map = nullptr;
			break;
		case Class::Object:
			Internal.Map = new map<string, JSON>();
			break;
		case Class::Array:
			Internal.List = new deque<JSON>();
			break;
		case Class::String:
			Internal.String = new string();
			break;
		case Class::Floating:
			Internal.Float = 0.0;
			break;
		case Class::Integral:
			Internal.Int = 0;
			break;
		case Class::Boolean:
			Internal.Bool = false;
			break;
		}

		Type = type;
	}

private:
	/**
	 * @brief Clears the internal storage of the JSON object.
	 * @details Frees allocated memory based on the current type. Must be called with caution.
	 */
	void ClearInternal() {
		switch (Type) {
		case Class::Object:
			delete Internal.Map;
			break;
		case Class::Array:
			delete Internal.List;
			break;
		case Class::String:
			delete Internal.String;
			break;
		default:
			;
		}
	}

private:

	Class Type = Class::Null;
};

/**
 * @brief Creates an empty JSON array.
 * @return A JSON object representing an empty array.
 */
inline JSON Array() {
	return std::move(JSON::Make(JSON::Class::Array));
}

/**
 * @brief Creates a JSON array with the specified elements.
 * @tparam T Types of the elements to append.
 * @param args The elements to append to the array.
 * @return A JSON object representing the array.
 */
template<typename ... T>
JSON Array(T ... args) {
	JSON arr = JSON::Make(JSON::Class::Array);
	arr.append(args...);
	return arr;
}

/**
 * @brief Creates an empty JSON object.
 * @return A JSON object representing an empty object.
 */
inline JSON Object() {
	return std::move(JSON::Make(JSON::Class::Object));
}

/**
 * @brief Outputs a JSON object to an output stream.
 * @param os The output stream.
 * @param json The JSON object to output.
 * @return Reference to the output stream.
 */
inline std::ostream& operator<<(std::ostream &os, const JSON &json) {
	os << json.dump();
	return os;
}

/**
 * @namespace
 * @brief Anonymous namespace for JSON parsing utility functions.
 */
namespace {
/**
 * @brief Parses the next JSON value from a string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated during parsing).
 * @return The parsed JSON value.
 */
JSON parse_next(const string&, size_t&);

/**
 * @brief Consumes whitespace characters in the input string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated to skip whitespace).
 */
void consume_ws(const string &str, size_t &offset) {
	while (isspace(str[offset]))
		++offset;
}

/**
 * @brief Parses a JSON object from a string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated during parsing).
 * @return The parsed JSON object.
 */
JSON parse_object(const string &str, size_t &offset) {
	JSON Object = JSON::Make(JSON::Class::Object);

	++offset;
	consume_ws(str, offset);
	if (str[offset] == '}') {
		++offset;
		return Object;
	}

	while (true) {
		JSON Key = parse_next(str, offset);
		consume_ws(str, offset);
		if (str[offset] != ':') {
			std::cerr << "Error: Object: Expected colon, found '" << str[offset]
					<< "'\n";
			break;
		}
		consume_ws(str, ++offset);
		JSON Value = parse_next(str, offset);
		Object[Key.ToString()] = Value;

		consume_ws(str, offset);
		if (str[offset] == ',') {
			++offset;
			continue;
		} else if (str[offset] == '}') {
			++offset;
			break;
		} else {
			std::cerr << "ERROR: Object: Expected comma, found '" << str[offset]
					<< "'\n";
			break;
		}
	}

	return Object;
}

/**
 * @brief Parses a JSON array from a string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated during parsing).
 * @return The parsed JSON array.
 */
JSON parse_array(const string &str, size_t &offset) {
	JSON Array = JSON::Make(JSON::Class::Array);
	unsigned index = 0;

	++offset;
	consume_ws(str, offset);
	if (str[offset] == ']') {
		++offset;
		return Array;
	}

	while (true) {
		Array[index++] = parse_next(str, offset);
		consume_ws(str, offset);

		if (str[offset] == ',') {
			++offset;
			continue;
		} else if (str[offset] == ']') {
			++offset;
			break;
		} else {
			std::cerr << "ERROR: Array: Expected ',' or ']', found '"
					<< str[offset] << "'\n";
			return std::move(JSON::Make(JSON::Class::Array));
		}
	}

	return Array;
}

/**
 * @brief Parses a JSON string from a string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated during parsing).
 * @return The parsed JSON string.
 */
JSON parse_string(const string &str, size_t &offset) {
	JSON String;
	string val;
	for (char c = str[++offset]; c != '\"'; c = str[++offset]) {
		if (c == '\\') {
			switch (str[++offset]) {
			case '\"':
				val += '\"';
				break;
			case '\\':
				val += '\\';
				break;
			case '/':
				val += '/';
				break;
			case 'b':
				val += '\b';
				break;
			case 'f':
				val += '\f';
				break;
			case 'n':
				val += '\n';
				break;
			case 'r':
				val += '\r';
				break;
			case 't':
				val += '\t';
				break;
			case 'u': {
				val += "\\u";
				for (unsigned i = 1; i <= 4; ++i) {
					c = str[offset + i];
					if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f')
							|| (c >= 'A' && c <= 'F'))
						val += c;
					else {
						std::cerr
								<< "ERROR: String: Expected hex character in unicode escape, found '"
								<< c << "'\n";
						return std::move(JSON::Make(JSON::Class::String));
					}
				}
				offset += 4;
			}
				break;
			default:
				val += '\\';
				break;
			}
		} else
			val += c;
	}
	++offset;
	String = val;
	return String;
}

/**
 * @brief Parses a JSON number from a string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated during parsing).
 * @return The parsed JSON number.
 */
JSON parse_number(const string &str, size_t &offset) {
	JSON Number;
	string val, exp_str;
	char c;
	bool isDouble = false;
	long exp = 0;
	while (true) {
		c = str[offset++];
		if ((c == '-') || (c >= '0' && c <= '9'))
			val += c;
		else if (c == '.') {
			val += c;
			isDouble = true;
		} else
			break;
	}
	if (c == 'E' || c == 'e') {
		c = str[offset++];
		if (c == '-') {
			++offset;
			exp_str += '-';
		}
		while (true) {
			c = str[offset++];
			if (c >= '0' && c <= '9')
				exp_str += c;
			else if (!isspace(c) && c != ',' && c != ']' && c != '}') {
				std::cerr
						<< "ERROR: Number: Expected a number for exponent, found '"
						<< c << "'\n";
				return std::move(JSON::Make(JSON::Class::Null));
			} else
				break;
		}
		exp = std::stol(exp_str);
	} else if (!isspace(c) && c != ',' && c != ']' && c != '}') {
		std::cerr << "ERROR: Number: unexpected character '" << c << "'\n";
		return std::move(JSON::Make(JSON::Class::Null));
	}
	--offset;

	if (isDouble)
		Number = std::stod(val) * std::pow(10, exp);
	else {
		if (!exp_str.empty())
			Number = std::stol(val) * std::pow(10, exp);
		else
			Number = std::stol(val);
	}
	return Number;
}

/**
 * @brief Parses a JSON boolean from a string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated during parsing).
 * @return The parsed JSON boolean.
 */
JSON parse_bool(const string &str, size_t &offset) {
	JSON Bool;
	if (str.substr(offset, 4) == "true")
		Bool = true;
	else if (str.substr(offset, 5) == "false")
		Bool = false;
	else {
		std::cerr << "ERROR: Bool: Expected 'true' or 'false', found '"
				<< str.substr(offset, 5) << "'\n";
		return std::move(JSON::Make(JSON::Class::Null));
	}
	offset += (Bool.ToBool() ? 4 : 5);
	return Bool;
}

/**
 * @brief Parses a JSON null value from a string.
 * @param str The input JSON string.
 * @param offset The current position in the string (updated during parsing).
 * @return The parsed JSON null value.
 */
JSON parse_null(const string &str, size_t &offset) {
	JSON Null;
	if (str.substr(offset, 4) != "null") {
		std::cerr << "ERROR: Null: Expected 'null', found '"
				<< str.substr(offset, 4) << "'\n";
		return std::move(JSON::Make(JSON::Class::Null));
	}
	offset += 4;
	return Null;
}

JSON parse_next(const string &str, size_t &offset) {
	char value;
	consume_ws(str, offset);
	value = str[offset];
	switch (value) {
	case '[':
		return std::move(parse_array(str, offset));
	case '{':
		return std::move(parse_object(str, offset));
	case '\"':
		return std::move(parse_string(str, offset));
	case 't':
	case 'f':
		return std::move(parse_bool(str, offset));
	case 'n':
		return std::move(parse_null(str, offset));
	default:
		if ((value <= '9' && value >= '0') || value == '-')
			return std::move(parse_number(str, offset));
	}
	std::cerr << "ERROR: Parse: Unknown starting character '" << value << "'\n";
	return JSON();
}
}

/**
 * @brief Loads a JSON object from a string.
 * @param str The JSON string to parse.
 * @return The parsed JSON object.
 */
inline JSON JSON::Load(const string &str) {
	size_t offset = 0;
	return std::move(parse_next(str, offset));
}

} // End Namespace json
