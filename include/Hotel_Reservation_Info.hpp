/**
 * @file Hotel_Reservation_Info.hpp
 * @brief Defines data structures for hotel reservation information
 * @details Contains:
 *          - FoundRoomInfo: Search result for available rooms
 *          - CustomerInfo: Customer details for hotel bookings
 *          - Smart pointer type definitions
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_HOTEL_RESERVATION_INFO_HPP_
#define HEADERS_HOTEL_RESERVATION_INFO_HPP_

#include <iostream>
#include <memory>

/**
 * @class FoundRoomInfo
 * @brief Stores information about a hotel room available for reservation.
 */
class FoundRoomInfo {
public:
	/// Name of the hotel.
	std::string hotel;
	/// Check-in date for the reservation.
	std::string from_date;
	/// Check-out date for the reservation.
	std::string to_date;
	/// Type of view for the room (e.g., sea view, city view).
	std::string view_type;
	/// Number of rooms available.
	int how_many { };
	/// Price per night for the room.
	double price_for_night { };

	/**
	 * @brief Default constructor for FoundRoomInfo.
	 */
	FoundRoomInfo() = default;

	/**
	 * @brief Parameterized constructor for FoundRoomInfo.
	 * @param hotel Name of the hotel.
	 * @param from_date Check-in date.
	 * @param to_date Check-out date.
	 * @param view_type Type of room view.
	 * @param how_many Number of rooms available.
	 * @param price Price per night for the room.
	 */
	FoundRoomInfo(std::string hotel, std::string from_date, std::string to_date,
			std::string view_type, int how_many, double price);

	/**
	 * @brief Copy constructor for FoundRoomInfo.
	 * @param other Another FoundRoomInfo object to copy from.
	 */
	FoundRoomInfo(const FoundRoomInfo &other);

	/**
	 * @brief Move constructor for FoundRoomInfo.
	 * @param other Another FoundRoomInfo object to move from.
	 */
	FoundRoomInfo(FoundRoomInfo &&other);

	/**
	 * @brief Copy assignment operator for FoundRoomInfo.
	 * @param other Another FoundRoomInfo object to copy from.
	 * @return Reference to this FoundRoomInfo object.
	 */
	FoundRoomInfo& operator=(const FoundRoomInfo &other);

	/**
	 * @brief Move assignment operator for FoundRoomInfo.
	 * @param other Another FoundRoomInfo object to move from.
	 * @return Reference to this FoundRoomInfo object.
	 */
	FoundRoomInfo& operator=(FoundRoomInfo &&other);
};

/**
 * @class CustomerInfo
 * @brief Stores customer information for a hotel reservation.
 */
class CustomerInfo {
public:
	/// Check-in date for the reservation.
	std::string from_date;
	/// Check-out date for the reservation.
	std::string to_date;
	/// Country where the hotel is located.
	std::string country;
	/// City where the hotel is located.
	std::string city;
	/// Number of children in the reservation.
	int children { };
	/// Number of adults in the reservation.
	int adults { };
	/// Number of rooms needed for the reservation.
	int needed_rooms { };
	/// Number of nights for the stay.
	int number_of_nights { };

	/**
	 * @brief Default constructor for CustomerInfo.
	 */
	CustomerInfo() = default;

	/**
	 * @brief Parameterized constructor for CustomerInfo.
	 * @param from_date Check-in date.
	 * @param to_date Check-out date.
	 * @param country Country of the hotel.
	 * @param city City of the hotel.
	 * @param children Number of children.
	 * @param adults Number of adults.
	 * @param needed_rooms Number of rooms needed.
	 * @param number_of_nights Number of nights for the stay.
	 */
	CustomerInfo(std::string from_date, std::string to_date,
			std::string country, std::string city, int children, int adults,
			int needed_rooms, int number_of_nights);

	/**
	 * @brief Copy constructor for CustomerInfo.
	 * @param other Another CustomerInfo object to copy from.
	 */
	CustomerInfo(const CustomerInfo &other);

	/**
	 * @brief Move constructor for CustomerInfo.
	 * @param other Another CustomerInfo object to move from.
	 */
	CustomerInfo(CustomerInfo &&other);

	/**
	 * @brief Copy assignment operator for CustomerInfo.
	 * @param other Another CustomerInfo object to copy from.
	 * @return Reference to this CustomerInfo object.
	 */
	CustomerInfo& operator=(const CustomerInfo &other);

	/**
	 * @brief Move assignment operator for CustomerInfo.
	 * @param other Another CustomerInfo object to move from.
	 * @return Reference to this CustomerInfo object.
	 */
	CustomerInfo& operator=(CustomerInfo &&other);
};

/**
 * @typedef RoomInfo_ptr
 * @brief Smart pointer to a FoundRoomInfo object.
 */
typedef std::unique_ptr<FoundRoomInfo> RoomInfo_ptr;

/**
 * @typedef CustomerInfo_ptr
 * @brief Smart pointer to a CustomerInfo object.
 */
typedef std::unique_ptr<CustomerInfo> CustomerInfo_ptr;

#endif /* HEADERS_HOTEL_RESERVATION_INFO_HPP_ */
