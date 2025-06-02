/**
 * @file Flight_Reservation.hpp
 * @brief Abstract base class for flight reservations
 * @details Declares interface for:
 *          - Setting passenger information
 *          - Retrieving available flights
 *          - Making/canceling reservations
 *
 * @author Abdallah Salem
 */

#ifndef HEADERS_FLIGHT_RESERVATION_HPP_
#define HEADERS_FLIGHT_RESERVATION_HPP_

#include "Reservation.hpp"            ///< Includes the base Reservation class.
#include "Flight_Reservation_Info.hpp" ///< Includes definitions for PassengerInfo and FlightInfo.

/**
 * @class FlightReservation
 * @brief Abstract base class for managing flight reservations.
 *
 * This class inherits from Reservation and defines the interface for flight-specific
 * reservation operations. Concrete implementations (e.g., for different airlines)
 * must provide definitions for the pure virtual functions declared here.
 */
class FlightReservation: public Reservation {
public:
	/**
	 * @brief Sets the customer information for the flight reservation.
	 *
	 * This method is responsible for storing the customer's travel preferences
	 * and passenger details, taking ownership of the provided PassengerInfo object.
	 *
	 * @param customer_info Unique pointer to the customer's travel information.
	 */
	virtual void setCustomerInfo(PassengerInfo_ptr &&customer_info) = 0;

	/**
	 * @brief Retrieves available flights based on the customer's information.
	 *
	 * This method populates the provided vector with available flight options.
	 * Note: The use of an rvalue reference for the vector is unconventional for
	 * an output parameter; typically, an lvalue reference would be used.
	 *
	 * @param flights Vector to store the available flight information.
	 */
	virtual void getAvailableFlights(
			std::vector<FoundFlightInfo> &&flights) = 0;

	/**
	 * @brief Sets the chosen flight for the reservation.
	 *
	 * This method selects the specific flight the customer wishes to book,
	 * taking ownership of the provided FlightInfo object.
	 *
	 * @param info Unique pointer to the selected flight details.
	 */
	virtual void setChosenFlight(FlightInfo_ptr &&info) = 0;

	/**
	 * @brief Attempts to make the flight reservation.
	 *
	 * This method interacts with the external airline system to book the selected flight.
	 *
	 * @return True if the reservation is successfully made, false otherwise.
	 */
	virtual bool makeReservation() = 0;

	/**
	 * @brief Cancels an existing flight reservation.
	 *
	 * This method interacts with the external airline system to cancel the booking.
	 *
	 * @return True if the reservation is successfully canceled, false otherwise.
	 */
	virtual bool cancelReservation() = 0;

	/**
	 * @brief Virtual destructor.
	 *
	 * Ensures proper cleanup of resources in derived classes.
	 */
	virtual ~FlightReservation() = default;
};

/**
 * @typedef FlightReservation_ptr
 * @brief Unique pointer to FlightReservation for managing polymorphic objects.
 *
 * This typedef simplifies the use of smart pointers for FlightReservation instances,
 * ensuring proper resource management and ownership semantics.
 */
typedef std::unique_ptr<FlightReservation> FlightReservation_ptr;

#endif /* HEADERS_FLIGHT_RESERVATION_HPP_ */
