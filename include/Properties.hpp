/**
 * @file Properties.hpp
 * @brief Defines interface properties for system objects
 * @details Interfaces:
 *          - Printable: Supports formatted output
 *          - Priced: Supports cost calculation
 *          - Comparable: Supports comparison operations
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_PROPERTIES_HPP_
#define HEADERS_PROPERTIES_HPP_

#include <iostream>

/**
 * @class Printable
 * @brief Abstract base class for objects that can be printed to an output stream.
 * @details Defines an interface for objects that provide a method to output their details.
 */
class Printable {
public:
	/**
	 * @brief Outputs the object's details to an output stream.
	 * @param get The output stream to write the details to.
	 */
	virtual void getDetails(std::ostream &&get) const = 0;

	/**
	 * @brief Virtual destructor for Printable.
	 * @details Ensures proper cleanup of derived classes.
	 */
	virtual ~Printable() = default;
};

/**
 * @class Priced
 * @brief Abstract base class for objects that have a cost.
 * @details Defines an interface for objects that provide a method to retrieve their cost.
 */
class Priced {
public:
	/**
	 * @brief Retrieves the cost of the object.
	 * @return The cost as a double.
	 */
	virtual double getCost() const = 0;

	/**
	 * @brief Virtual destructor for Priced.
	 * @details Ensures proper cleanup of derived classes.
	 */
	virtual ~Priced() = default;
};

/**
 * @class Comparable
 * @brief Abstract base class for objects that can be compared.
 * @details Defines an interface for objects that provide a method to perform comparisons.
 */
class Comparable {
public:
	/**
	 * @brief Performs a comparison of the object.
	 * @details The specific comparison logic is defined by derived classes.
	 */
	virtual void compare() const = 0;

	/**
	 * @brief Virtual destructor for Comparable.
	 * @details Ensures proper cleanup of derived classes.
	 */
	virtual ~Comparable() = default;
};

#endif /* HEADERS_PROPERTIES_HPP_ */
