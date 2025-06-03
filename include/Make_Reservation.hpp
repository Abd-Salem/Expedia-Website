/**
 * @file Make_Reservation.hpp
 * @brief Reservation creation interface
 * @details Provides:
 *          - Unified interface for flight/hotel reservations
 *          - Reservation factory for creating concrete reservation objects
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_MAKE_RESERVATION_HPP_
#define HEADERS_MAKE_RESERVATION_HPP_

#include "Hotels.hpp"
#include "Airports.hpp"

/**
 * @class MakeReservation
 * @brief Class for creating and managing flight and hotel reservations.
 * @details Handles the creation of flight and hotel reservations using passenger and customer information,
 *          storing available options and selected choices.
 */
class MakeReservation {
private:
	/// Vector of smart pointers to flight reservations.
	std::vector<FlightReservation_ptr> Airports;
	/// Vector of smart pointers to hotel reservations.
	std::vector<HotelReservation_ptr> Hotels;
	/// Smart pointer to passenger information for flight reservations.
	PassengerInfo_ptr passenger_info;
	/// Smart pointer to customer information for hotel reservations.
	CustomerInfo_ptr customer_info;
	/// Smart pointer to the chosen flight information.
	FlightInfo_ptr chosen_flight;
	/// Smart pointer to the chosen room information.
	RoomInfo_ptr chosen_room;

	/**
	 * @brief Creates a reservation based on the specified brand.
	 * @param brand The brand name for the reservation (e.g., hotel or airline brand).
	 * @return A smart pointer to a Reservation object.
	 */
	Reservation_ptr ReservationFactory(std::string &brand);

public:
	/**
	 * @brief Default constructor for MakeReservation.
	 */
	MakeReservation();

	/**
	 * @brief Creates a flight reservation.
	 * @return A smart pointer to a Reservation object representing the flight reservation.
	 */
	Reservation_ptr reservingFlight();

	/**
	 * @brief Creates a hotel room reservation.
	 * @return A smart pointer to a Reservation object representing the hotel reservation.
	 */
	Reservation_ptr reservingRoom();
};

/**
 * @typedef MakeReservation_ptr
 * @brief Smart pointer to a MakeReservation object.
 */
typedef std::unique_ptr<MakeReservation> MakeReservation_ptr;

#endif /* HEADERS_MAKE_RESERVATION_HPP_ */
