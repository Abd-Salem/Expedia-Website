/**
 * @file Airports.hpp
 * @brief Implements flight reservation adapters for Air Canada and Turkish Airlines
 * @details Contains:
 *          - CanadaFlightReservation: Adapter for Air Canada API
 *          - TurkishFlightReservation: Adapter for Turkish Airlines API
 *          - Defines smart pointer types for airline-specific objects
 * @author Abdallah Salem
 *
 */

#ifndef HEADERS_AIRPORTS_HPP_
#define HEADERS_AIRPORTS_HPP_

#include "Airport_APIs.hpp"
#include "Flight_Reservation.hpp"

/**
 * @brief Typedefs for unique pointers to airline-specific customer info and flight objects.
 *
 * These aliases simplify the use of smart pointers for managing airline data objects,
 * ensuring proper resource management and ownership semantics.
 */
typedef std::unique_ptr<AirCanadaCustomerInfo> AirCanadaCustomerInfo_ptr;
typedef std::unique_ptr<AirCanadaFlight> AirCanadaFlight_ptr;
typedef std::unique_ptr<TurkishCustomerInfo> TurkishCustomerInfo_ptr;
typedef std::unique_ptr<TurkishFlight> TurkishFlight_ptr;

/**
 * @class CanadaFlightReservation
 * @brief Manages flight reservations for Air Canada.
 *
 * This class inherits from FlightReservation and implements airline-specific logic
 * for Air Canada, including setting customer information, selecting flights, retrieving
 * available flights, calculating costs, and handling reservation operations.
 */
class CanadaFlightReservation: public FlightReservation {
private:
	AirCanadaCustomerInfo_ptr canada_customer_info; ///< Unique pointer to Air Canada's customer info.
	AirCanadaFlight_ptr canada_chosen_flight; ///< Unique pointer to the chosen Air Canada flight.

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes a CanadaFlightReservation object with default values.
	 */
	CanadaFlightReservation();

	/**
	 * @brief Constructs a reservation with provided customer and flight information.
	 *
	 * This constructor initializes the object by moving the ownership of the provided
	 * customer and flight information pointers.
	 *
	 * @param customer_info Unique pointer to passenger information.
	 * @param chosen_flight Unique pointer to the selected flight details.
	 */
	CanadaFlightReservation(PassengerInfo_ptr &&customer_info,
			FlightInfo_ptr &&chosen_flight);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new object as a copy of the provided CanadaFlightReservation instance.
	 *
	 * @param other The object to copy from.
	 */
	CanadaFlightReservation(const CanadaFlightReservation &other);

	/**
	 * @brief Move constructor.
	 *
	 * Transfers ownership of resources from the provided object to the new instance.
	 *
	 * @param other The object to move from.
	 */
	CanadaFlightReservation(CanadaFlightReservation &&other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Assigns the data from the provided object to this instance.
	 *
	 * @param other The object to copy from.
	 * @return Reference to this object.
	 */
	CanadaFlightReservation& operator=(const CanadaFlightReservation &other);

	/**
	 * @brief Move assignment operator.
	 *
	 * Moves the resources from the provided object to this instance.
	 *
	 * @param other The object to move from.
	 * @return Reference to this object.
	 */
	CanadaFlightReservation& operator=(CanadaFlightReservation &&other);

	/**
	 * @brief Sets the customer information for the reservation.
	 *
	 * This method updates the customer details by moving the ownership of the provided
	 * passenger information pointer and interacts with the Air Canada API to set the data.
	 *
	 * @param customer_info Unique pointer to passenger information.
	 */
	void setCustomerInfo(PassengerInfo_ptr &&customer_info) override;

	/**
	 * @brief Sets the chosen flight for the reservation.
	 *
	 * This method updates the selected flight details by moving the ownership of the provided
	 * flight information pointer and interacts with the Air Canada API to set the data.
	 *
	 * @param info Unique pointer to the selected flight details.
	 */
	void setChosenFlight(FlightInfo_ptr &&info) override;

	/**
	 * @brief Retrieves available flights from the Air Canada API.
	 *
	 * This method fetches the list of available flights based on the set customer information
	 * and populates the provided vector with flight details.
	 *
	 * @param flights Vector to store the available flight information.
	 */
	void getAvailableFlights(std::vector<FoundFlightInfo> &&flights) override;

	/**
	 * @brief Calculates and returns the cost of the chosen flight.
	 *
	 * @return The total cost of the flight reservation.
	 */
	double getCost() const override;

	/**
	 * @brief Creates a clone of this reservation object.
	 *
	 * @return A unique pointer to the cloned Reservation object.
	 */
	Reservation_ptr clone() const override;

	/**
	 * @brief Makes the flight reservation using the Air Canada API.
	 *
	 * @return True if the reservation is successfully made, false otherwise.
	 */
	bool makeReservation() override;

	/**
	 * @brief Cancels the flight reservation using the Air Canada API.
	 *
	 * @return True if the reservation is successfully canceled, false otherwise.
	 */
	bool cancelReservation() override;

	/**
	 * @brief Outputs flight reservation details to the provided ostream.
	 *
	 * This method is used to print or display the reservation information by overloading
	 * the streaming operator for ostream.
	 *
	 * @param get The ostream object to which the details will be written.
	 */
	void getDetails(std::ostream &&get) const override;
};

/**
 * @class TurkishFlightReservation
 * @brief Manages flight reservations for Turkish Airlines.
 *
 * This class inherits from FlightReservation and implements airline-specific logic
 * for Turkish Airlines, including setting customer information, selecting flights,
 * retrieving available flights, calculating costs, and handling reservation operations.
 */
class TurkishFlightReservation: public FlightReservation {
private:
	TurkishCustomerInfo_ptr turkish_customer_info; ///< Unique pointer to Turkish Airlines' customer info.
	TurkishFlight_ptr turkish_chosen_flight; ///< Unique pointer to the chosen Turkish Airlines flight.

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes a TurkishFlightReservation object with default values.
	 */
	TurkishFlightReservation();

	/**
	 * @brief Constructs a reservation with provided customer and flight information.
	 *
	 * This constructor initializes the object by moving the ownership of the provided
	 * customer and flight information pointers.
	 *
	 * @param customer_info Unique pointer to passenger information.
	 * @param chosen_flight Unique pointer to the selected flight details.
	 */
	TurkishFlightReservation(PassengerInfo_ptr &&customer_info,
			FlightInfo_ptr &&chosen_flight);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new object as a copy of the provided TurkishFlightReservation instance.
	 *
	 * @param other The object to copy from.
	 */
	TurkishFlightReservation(const TurkishFlightReservation &other);

	/**
	 * @brief Move constructor.
	 *
	 * Transfers ownership of resources from the provided object to the new instance.
	 *
	 * @param other The object to move from.
	 */
	TurkishFlightReservation(TurkishFlightReservation &&other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Assigns the data from the provided object to this instance.
	 *
	 * @param other The object to copy from.
	 * @return Reference to this object.
	 */
	TurkishFlightReservation& operator=(const TurkishFlightReservation &other);

	/**
	 * @brief Move assignment operator.
	 *
	 * Moves the resources from the provided object to this instance.
	 *
	 * @param other The object to move from.
	 * @return Reference to this object.
	 */
	TurkishFlightReservation& operator=(TurkishFlightReservation &&other);

	/**
	 * @brief Sets the customer information for the reservation.
	 *
	 * This method updates the customer details by moving the ownership of the provided
	 * passenger information pointer and interacts with the Turkish Airlines API to set the data.
	 *
	 * @param customer_info Unique pointer to passenger information.
	 */
	void setCustomerInfo(PassengerInfo_ptr &&customer_info) override;

	/**
	 * @brief Sets the chosen flight for the reservation.
	 *
	 * This method updates the selected flight details by moving the ownership of the provided
	 * flight information pointer and interacts with the Turkish Airlines API to set the data.
	 *
	 * @param info Unique pointer to the selected flight details.
	 */
	void setChosenFlight(FlightInfo_ptr &&info) override;

	/**
	 * @brief Retrieves available flights from the Turkish Airlines API.
	 *
	 * This method fetches the list of available flights based on the set customer information
	 * and populates the provided vector with flight details.
	 *
	 * @param flights Vector to store the available flight information.
	 */
	void getAvailableFlights(std::vector<FoundFlightInfo> &&flights) override;

	/**
	 * @brief Calculates and returns the cost of the chosen flight.
	 *
	 * @return The total cost of the flight reservation.
	 */
	double getCost() const override;

	/**
	 * @brief Creates a clone of this reservation object.
	 *
	 * @return A unique pointer to the cloned Reservation object.
	 */
	Reservation_ptr clone() const override;

	/**
	 * @brief Makes the flight reservation using the Turkish Airlines API.
	 *
	 * @return True if the reservation is successfully made, false otherwise.
	 */
	bool makeReservation() override;

	/**
	 * @brief Cancels the flight reservation using the Turkish Airlines API.
	 *
	 * @return True if the reservation is successfully canceled, false otherwise.
	 */
	bool cancelReservation() override;

	/**
	 * @brief Outputs flight reservation details to the provided ostream.
	 *
	 * This method is used to print or display the reservation information by overloading
	 * the streaming operator for ostream.
	 *
	 * @param get The ostream object to which the details will be written.
	 */
	void getDetails(std::ostream &&get) const override;
};

#endif /* HEADERS_AIRPORTS_HPP_ */
