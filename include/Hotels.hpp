/**
 * @file Hotels.hpp
 * @brief Implements hotel reservation adapters for Hilton and Marriott
 * @details Contains:
 *          - HiltonHotelReservation: Adapter for Hilton API
 *          - MarriottHotelReservation: Adapter for Marriott API
 *          - Defines smart pointer types for hotel-specific objects
 * @author Abdallah Salem
 * @date Created: Apr 13, 2025
 */

#ifndef HEADERS_HOTELS_HPP_
#define HEADERS_HOTELS_HPP_

#include "Hotel_APIs.hpp"
#include "Hotel_Reservation.hpp"

/**
 * @typedef HiltonCustomerInfo_ptr
 * @brief Smart pointer to a HiltonCustomerInfo object.
 */
typedef std::unique_ptr<HiltonCustomerInfo> HiltonCustomerInfo_ptr;

/**
 * @typedef HiltonRoom_ptr
 * @brief Smart pointer to a HiltonRoom object.
 */
typedef std::unique_ptr<HiltonRoom> HiltonRoom_ptr;

/**
 * @typedef MarriottCustomerInfo_ptr
 * @brief Smart pointer to a MarriottCustomerInfo object.
 */
typedef std::unique_ptr<MarriottCustomerInfo> MarriottCustomerInfo_ptr;

/**
 * @typedef MarriottFoundRoom_ptr
 * @brief Smart pointer to a MarriottFoundRoom object.
 */
typedef std::unique_ptr<MarriottFoundRoom> MarriottFoundRoom_ptr;

/**
 * @class HiltonHotelReservation
 * @brief Class for managing Hilton hotel reservations.
 * @details Inherits from HotelReservation and implements functionality specific to Hilton hotels.
 */
class HiltonHotelReservation: public HotelReservation {
private:
	/// Smart pointer to Hilton-specific customer information.
	HiltonCustomerInfo_ptr hilton_customer_info;
	/// Smart pointer to the chosen Hilton room.
	HiltonRoom_ptr hilton_chosen_room;

public:
	/**
	 * @brief Default constructor for HiltonHotelReservation.
	 */
	HiltonHotelReservation();

	/**
	 * @brief Parameterized constructor for HiltonHotelReservation.
	 * @param customer_info Smart pointer to customer information.
	 * @param chosen_room Smart pointer to the chosen room information.
	 */
	HiltonHotelReservation(CustomerInfo_ptr &&customer_info,
			RoomInfo_ptr &&chosen_room);

	/**
	 * @brief Copy constructor for HiltonHotelReservation.
	 * @param other Another HiltonHotelReservation object to copy from.
	 */
	HiltonHotelReservation(const HiltonHotelReservation &other);

	/**
	 * @brief Move constructor for HiltonHotelReservation.
	 * @param other Another HiltonHotelReservation object to move from.
	 */
	HiltonHotelReservation(HiltonHotelReservation &&other);

	/**
	 * @brief Copy assignment operator for HiltonHotelReservation.
	 * @param other Another HiltonHotelReservation object to copy from.
	 * @return Reference to this HiltonHotelReservation object.
	 */
	HiltonHotelReservation& operator=(const HiltonHotelReservation &other);

	/**
	 * @brief Move assignment operator for HiltonHotelReservation.
	 * @param other Another HiltonHotelReservation object to move from.
	 * @return Reference to this HiltonHotelReservation object.
	 */
	HiltonHotelReservation& operator=(HiltonHotelReservation &&other);

	/**
	 * @brief Sets the customer information for the Hilton reservation.
	 * @param customer_info Smart pointer to customer information.
	 */
	void setCustomerInfo(CustomerInfo_ptr &&customer_info) override;

	/**
	 * @brief Retrieves available rooms for the Hilton reservation.
	 * @param rooms A vector of FoundRoomInfo objects representing available rooms.
	 */
	void getAvailableRooms(std::vector<FoundRoomInfo> &&rooms) override;

	/**
	 * @brief Sets the chosen room information for the Hilton reservation.
	 * @param room_info Smart pointer to the chosen room information.
	 */
	void setChosenRoomInfo(RoomInfo_ptr &&room_info) override;

	/**
	 * @brief Makes a Hilton hotel reservation.
	 * @return True if the reservation is successful, false otherwise.
	 */
	bool makeReservation() override;

	/**
	 * @brief Cancels a Hilton hotel reservation.
	 * @return True if the cancellation is successful, false otherwise.
	 */
	bool cancelReservation() override;

	/**
	 * @brief Creates a clone of the Hilton hotel reservation.
	 * @return Smart pointer to a cloned Reservation object.
	 */
	Reservation_ptr clone() const;

	/**
	 * @brief Calculates the total cost of the Hilton reservation.
	 * @return The total cost as a double.
	 */
	double getCost() const override;

	/**
	 * @brief Outputs the details of the Hilton reservation.
	 * @param get Output stream to write the reservation details to.
	 */
	void getDetails(std::ostream &&get) const override;
};

/**
 * @class MarriottHotelReservation
 * @brief Class for managing Marriott hotel reservations.
 * @details Inherits from HotelReservation and implements functionality specific to Marriott hotels.
 */
class MarriottHotelReservation: public HotelReservation {
private:
	/// Smart pointer to Marriott-specific customer information.
	MarriottCustomerInfo_ptr marriott_customer_info;
	/// Smart pointer to the chosen Marriott room.
	MarriottFoundRoom_ptr marriott_chosen_room;

public:
	/**
	 * @brief Default constructor for MarriottHotelReservation.
	 */
	MarriottHotelReservation();

	/**
	 * @brief Parameterized constructor for MarriottHotelReservation.
	 * @param customer_info Smart pointer to customer information.
	 * @param chosen_room Smart pointer to the chosen room information.
	 */
	MarriottHotelReservation(CustomerInfo_ptr &&customer_info,
			RoomInfo_ptr &&chosen_room);

	/**
	 * @brief Copy constructor for MarriottHotelReservation.
	 * @param other Another MarriottHotelReservation object to copy from.
	 */
	MarriottHotelReservation(const MarriottHotelReservation &other);

	/**
	 * @brief Move constructor for MarriottHotelReservation.
	 * @param other Another MarriottHotelReservation object to move from.
	 */
	MarriottHotelReservation(MarriottHotelReservation &&other);

	/**
	 * @brief Copy assignment operator for MarriottHotelReservation.
	 * @param other Another MarriottHotelReservation object to copy from.
	 * @return Reference to this MarriottHotelReservation object.
	 */
	MarriottHotelReservation& operator=(const MarriottHotelReservation &other);

	/**
	 * @brief Move assignment operator for MarriottHotelReservation.
	 * @param other Another MarriottHotelReservation object to move from.
	 * @return Reference to this MarriottHotelReservation object.
	 */
	MarriottHotelReservation& operator=(MarriottHotelReservation &&other);

	/**
	 * @brief Sets the customer information for the Marriott reservation.
	 * @param customer_info Smart pointer to customer information.
	 */
	void setCustomerInfo(CustomerInfo_ptr &&customer_info) override;

	/**
	 * @brief Retrieves available rooms for the Marriott reservation.
	 * @param rooms A vector of FoundRoomInfo objects representing available rooms.
	 */
	void getAvailableRooms(std::vector<FoundRoomInfo> &&rooms) override;

	/**
	 * @brief Sets the chosen room information for the Marriott reservation.
	 * @param room_info Smart pointer to the chosen room information.
	 */
	void setChosenRoomInfo(RoomInfo_ptr &&room_info) override;

	/**
	 * @brief Makes a Marriott hotel reservation.
	 * @return True if the reservation is successful, false otherwise.
	 */
	bool makeReservation() override;

	/**
	 * @brief Cancels a Marriott hotel reservation.
	 * @return True if the cancellation is successful, false otherwise.
	 */
	bool cancelReservation() override;

	/**
	 * @brief Creates a clone of the Marriott hotel reservation.
	 * @return Smart pointer to a cloned Reservation object.
	 */
	Reservation_ptr clone() const override;

	/**
	 * @brief Calculates the total cost of the Marriott reservation.
	 * @return The total cost as a double.
	 */
	double getCost() const override;

	/**
	 * @brief Outputs the details of the Marriott reservation.
	 * @param get Output stream to write the reservation details to.
	 */
	void getDetails(std::ostream &&get) const override;
};

#endif /* HEADERS_HOTELS_HPP_ */
