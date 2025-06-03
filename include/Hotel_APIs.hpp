/**
 * @file Hotel_APIs.hpp
 * @brief Defines hotel customer information, room data, and API interfaces for Hilton and Marriott
 * @details Provides classes for:
 *          - Hotel customer information (HiltonCustomerInfo, MarriottCustomerInfo)
 *          - Room details (HiltonRoom, MarriottFoundRoom)
 *          - API operations (HiltonHotelAPI, MarriottHotelAPI)
 *
 * @author Abdallah Salem
 */

#ifndef HEADERS_HOTEL_APIS_HPP_
#define HEADERS_HOTEL_APIS_HPP_

#include<iostream>
#include<vector>

/**
 * @class HiltonCustomerInfo
 * @brief Stores customer preferences for booking with Hilton hotels.
 */
class HiltonCustomerInfo {
public:
	std::string country; ///< Country of the hotel location
	std::string city;    ///< City of the hotel location
	std::string date_from; ///< Check-in date (e.g., "2025-06-01")
	std::string date_to;   ///< Check-out date (e.g., "2025-06-05")
	int needed_rooms { };  ///< Number of rooms required
	int adults { };        ///< Number of adults
	int children { };      ///< Number of children
	int number_of_nights { }; ///< Duration of stay in nights

	/**
	 * @brief Default constructor.
	 * Initializes an empty customer info object with default values (e.g., empty strings, zeros).
	 */
	HiltonCustomerInfo() = default;

	/**
	 * @brief Parameterized constructor.
	 * Initializes customer info with provided values.
	 * @param country The country of the hotel location.
	 * @param city The city of the hotel location.
	 * @param date_from Check-in date.
	 * @param date_to Check-out date.
	 * @param needed_rooms Number of rooms required.
	 * @param adults Number of adults.
	 * @param children Number of children.
	 * @param number_of_nights Duration of stay in nights.
	 */
	HiltonCustomerInfo(std::string country, std::string city,
			std::string date_from, std::string date_to, int needed_rooms,
			int adults, int children, int number_of_nights);
};

/**
 * @class HiltonRoom
 * @brief Represents a room's details available at a Hilton hotel.
 */
class HiltonRoom {
public:
	std::string room_type; ///< Type of room (e.g., "Single", "Suite")
	int available_number { }; ///< Number of such rooms available
	double price_per_night { }; ///< Price per night for the room
	std::string from_date; ///< Start date of availability
	std::string to_date;   ///< End date of availability

	/**
	 * @brief Default constructor.
	 * Initializes an empty room object with default values (e.g., empty strings, zeros).
	 */
	HiltonRoom() = default;

	/**
	 * @brief Parameterized constructor.
	 * Initializes room details with provided values.
	 * @param room_type The type of the room.
	 * @param available_number The number of rooms available.
	 * @param price The price per night for the room.
	 * @param from The start date of availability.
	 * @param to The end date of availability.
	 */
	HiltonRoom(std::string room_type, int available_number, double price,
			std::string from, std::string to);
};

/**
 * @class HiltonHotelAPI
 * @brief Provides an interface to interact with Hilton hotel services.
 */
class HiltonHotelAPI {
public:
	/**
	 * @brief Sets customer information for use in subsequent API calls.
	 * @param customer_info The customer information to set.
	 */
	static void setCustomerInfo(const HiltonCustomerInfo &customer_info);

	/**
	 * @brief Searches for rooms matching the customer's preferences.
	 * @param customer_info The customer's booking preferences.
	 * @return A vector of available HiltonRoom objects.
	 */
	static std::vector<HiltonRoom> searchRooms(
			HiltonCustomerInfo &customer_info);

	/**
	 * @brief Attempts to reserve a room based on customer and room info.
	 * @param customer_info The customer's information.
	 * @param room_info The room to reserve.
	 * @return True if the reservation is successful, false otherwise.
	 */
	static bool reserveRoom(const HiltonCustomerInfo &customer_info,
			const HiltonRoom &room_info);

	/**
	 * @brief Cancels an existing reservation based on customer and room info.
	 * @param customer_info The customer's information.
	 * @param room_info The room to cancel the reservation for.
	 * @return True if the cancellation is successful, false otherwise.
	 */
	static bool cancelReservation(const HiltonCustomerInfo &customer_info,
			const HiltonRoom &room_info);
};

/**
 * @class MarriottFoundRoom
 * @brief Represents a room's details available at a Marriott hotel.
 */
class MarriottFoundRoom {
public:
	std::string room_type; ///< Type of room (e.g., "Double", "Deluxe")
	int available_number { }; ///< Number of such rooms available
	double price_per_night { }; ///< Price per night for the room
	std::string date_from { }; ///< Start date of availability
	std::string date_to { };   ///< End date of availability

	/**
	 * @brief Default constructor.
	 * Initializes an empty room object with default values (e.g., empty strings, zeros).
	 */
	MarriottFoundRoom() = default;

	/**
	 * @brief Parameterized constructor.
	 * Initializes room details with provided values.
	 * @param type The type of the room.
	 * @param available_number The number of rooms available.
	 * @param price The price per night for the room.
	 * @param from The start date of availability.
	 * @param to The end date of availability.
	 */
	MarriottFoundRoom(std::string type, int available_number, double price,
			std::string from, std::string to);
};

/**
 * @class MarriottCustomerInfo
 * @brief Stores customer preferences for booking with Marriott hotels.
 */
class MarriottCustomerInfo {
public:
	std::string country; ///< Country of the hotel location
	std::string city;    ///< City of the hotel location
	std::string date_from; ///< Check-in date (e.g., "2025-06-01")
	std::string date_to;   ///< Check-out date (e.g., "2025-06-05")
	int needed_rooms { };  ///< Number of rooms required
	int adults { };        ///< Number of adults
	int children { };      ///< Number of children
	int number_of_nights { }; ///< Duration of stay in nights

	/**
	 * @brief Default constructor.
	 * Initializes an empty customer info object with default values (e.g., empty strings, zeros).
	 */
	MarriottCustomerInfo() = default;

	/**
	 * @brief Parameterized constructor.
	 * Initializes customer info with provided values.
	 * @param country The country of the hotel location.
	 * @param city The city of the hotel location.
	 * @param date_from Check-in date.
	 * @param date_to Check-out date.
	 * @param needed_rooms Number of rooms required.
	 * @param adults Number of adults.
	 * @param children Number of children.
	 * @param number_of_nights Duration of stay in nights.
	 */
	MarriottCustomerInfo(std::string country, std::string city,
			std::string date_from, std::string date_to, int needed_rooms,
			int adults, int children, int number_of_nights);
};

/**
 * @class MarriottHotelAPI
 * @brief Provides an interface to interact with Marriott hotel services.
 */
class MarriottHotelAPI {
public:
	/**
	 * @brief Sets customer information for use in subsequent API calls.
	 * @param customer_info The customer information to set.
	 */
	static void setCustomerInfo(const MarriottCustomerInfo &customer_info);

	/**
	 * @brief Finds rooms matching the customer's preferences.
	 * @param customer_info The customer's booking preferences.
	 * @return A vector of available MarriottFoundRoom objects.
	 */
	static std::vector<MarriottFoundRoom> findRooms(
			const MarriottCustomerInfo &customer_info);

	/**
	 * @brief Attempts to reserve a room based on room and customer info.
	 * @param room_info The room to reserve.
	 * @param customer_info The customer's information.
	 * @return True if the reservation is successful, false otherwise.
	 */
	static bool reserveRoom(const MarriottFoundRoom &room_info,
			const MarriottCustomerInfo &customer_info);

	/**
	 * @brief Cancels an existing reservation based on room and customer info.
	 * @param room_info The room to cancel the reservation for.
	 * @param customer_info The customer's information.
	 * @return True if the cancellation is successful, false otherwise.
	 */
	static bool cancelReservation(const MarriottFoundRoom &room_info,
			const MarriottCustomerInfo &customer_info);
};

#endif /* HEADERS_HOTEL_APIS_HPP_ */
