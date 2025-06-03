/**
 * @file Hotel_Reservation.hpp
 * @brief Abstract base class for hotel reservations
 * @details Declares interface for:
 *          - Setting customer information
 *          - Retrieving available rooms
 *          - Making/canceling reservations
 *
 * @author Abdallah Salem
 */

#ifndef HEADERS_HOTEL_RESERVATION_HPP_
#define HEADERS_HOTEL_RESERVATION_HPP_

#include "Reservation.hpp"
#include "Hotel_Reservation_Info.hpp"

/**
 * @class HotelReservation
 * @brief Abstract base class for handling hotel reservation operations.
 * @details Inherits from Reservation and defines pure virtual functions for managing customer information,
 *          available rooms, and reservation operations.
 */
class HotelReservation: public Reservation {
public:
	/**
	 * @brief Sets the customer information for the reservation.
	 * @param info A unique pointer to a CustomerInfo object containing customer details.
	 */
	virtual void setCustomerInfo(CustomerInfo_ptr &&info) = 0;

	/**
	 * @brief Retrieves available rooms for the reservation.
	 * @param rooms A vector of FoundRoomInfo objects representing available rooms.
	 */
	virtual void getAvailableRooms(std::vector<FoundRoomInfo> &&rooms) = 0;

	/**
	 * @brief Sets the chosen room information for the reservation.
	 * @param room_info A unique pointer to a FoundRoomInfo object containing room details.
	 */
	virtual void setChosenRoomInfo(RoomInfo_ptr &&room_info) = 0;

	/**
	 * @brief Makes a hotel reservation based on the provided information.
	 * @return True if the reservation is successful, false otherwise.
	 */
	virtual bool makeReservation() = 0;

	/**
	 * @brief Cancels an existing hotel reservation.
	 * @return True if the cancellation is successful, false otherwise.
	 */
	virtual bool cancelReservation() = 0;

	/**
	 * @brief Virtual destructor for HotelReservation.
	 * @details Ensures proper cleanup of derived classes.
	 */
	virtual ~HotelReservation() = default;
};

/**
 * @typedef HotelReservation_ptr
 * @brief Smart pointer to a HotelReservation object.
 */
typedef std::unique_ptr<HotelReservation> HotelReservation_ptr;

#endif /* HEADERS_HOTEL_RESERVATION_HPP_ */
