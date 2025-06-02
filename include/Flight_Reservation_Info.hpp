/**
 * @file Flight_Reservation_Info.hpp
 * @brief Defines data structures for flight reservation information
 * @details Contains:
 *          - FoundFlightInfo: Search result for available flights
 *          - PassengerInfo: Passenger details for flight bookings
 *          - Smart pointer type definitions
 * @author Abdallah Salem
 *
 */

#ifndef HEADERS_FLIGHT_RESERVATION_INFO_HPP_
#define HEADERS_FLIGHT_RESERVATION_INFO_HPP_

#include <iostream>
#include <memory>

/**
 * @class FoundFlightInfo
 * @brief Represents flight details returned from airline APIs.
 *
 * This class holds information about a specific flight, including the airline,
 * price, and travel dates. It is used to store and manage flight data retrieved
 * from external airline services.
 */
class FoundFlightInfo {
public:
	std::string airline;        ///< Name of the airline offering the flight.
	double price { };           ///< Cost of the flight ticket.
	std::string from_date;      ///< Departure date and time.
	std::string to_date;        ///< Arrival date and time.

	/**
	 * @brief Default constructor.
	 *
	 * Initializes a FoundFlightInfo object with default (empty) values.
	 */
	FoundFlightInfo() = default;

	/**
	 * @brief Parameterized constructor.
	 *
	 * Creates a FoundFlightInfo object with the provided flight details.
	 *
	 * @param airline Name of the airline.
	 * @param price Cost of the flight.
	 * @param from_date Departure date and time.
	 * @param to_date Arrival date and time.
	 */
	FoundFlightInfo(std::string airline, double price, std::string from_date,
			std::string to_date);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new object as a copy of the provided FoundFlightInfo instance.
	 *
	 * @param other The object to copy from.
	 */
	FoundFlightInfo(const FoundFlightInfo &other);

	/**
	 * @brief Move constructor.
	 *
	 * Transfers ownership of resources from the provided object to the new instance.
	 *
	 * @param other The object to move from.
	 */
	FoundFlightInfo(FoundFlightInfo &&other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Assigns the data from the provided object to this instance.
	 *
	 * @param other The object to copy from.
	 * @return Reference to this object.
	 */
	FoundFlightInfo& operator=(const FoundFlightInfo &other);

	/**
	 * @brief Move assignment operator.
	 *
	 * Moves the resources from the provided object to this instance.
	 *
	 * @param other The object to move from.
	 * @return Reference to this object.
	 */
	FoundFlightInfo& operator=(FoundFlightInfo &&other);
};

/**
 * @class PassengerInfo
 * @brief Represents customer travel preferences and passenger details.
 *
 * This class encapsulates the information required to book a flight, including
 * travel dates, origin, destination, and the number of passengers (adults, children, infants).
 */
class PassengerInfo {
public:
	std::string from_date;      ///< Desired departure date.
	std::string to_date;        ///< Desired return date (if applicable).
	std::string from;           ///< Origin airport or city.
	std::string to;             ///< Destination airport or city.
	int children { };           ///< Number of child passengers.
	int adults { };             ///< Number of adult passengers.
	int infants { };            ///< Number of infant passengers.

	/**
	 * @brief Default constructor.
	 *
	 * Initializes a PassengerInfo object with default (empty) values.
	 */
	PassengerInfo() = default;

	/**
	 * @brief Parameterized constructor.
	 *
	 * Creates a PassengerInfo object with the provided travel and passenger details.
	 *
	 * @param from_date Desired departure date.
	 * @param to_date Desired return date (if applicable).
	 * @param from Origin airport or city.
	 * @param to Destination airport or city.
	 * @param children Number of child passengers.
	 * @param adults Number of adult passengers.
	 * @param infants Number of infant passengers.
	 */
	PassengerInfo(std::string from_date, std::string to_date, std::string from,
			std::string to, int children, int adults, int infants);

	/**
	 * @brief Copy constructor.
	 *
	 * Creates a new object as a copy of the provided PassengerInfo instance.
	 *
	 * @param other The object to copy from.
	 */
	PassengerInfo(const PassengerInfo &other);

	/**
	 * @brief Move constructor.
	 *
	 * Transfers ownership of resources from the provided object to the new instance.
	 *
	 * @param other The object to move from.
	 */
	PassengerInfo(PassengerInfo &&other);

	/**
	 * @brief Copy assignment operator.
	 *
	 * Assigns the data from the provided object to this instance.
	 *
	 * @param other The object to copy from.
	 * @return Reference to this object.
	 */
	PassengerInfo& operator=(const PassengerInfo &other);

	/**
	 * @brief Move assignment operator.
	 *
	 * Moves the resources from the provided object to this instance.
	 *
	 * @param other The object to move from.
	 * @return Reference to this object.
	 */
	PassengerInfo& operator=(PassengerInfo &&other);
};

/**
 * @typedef FlightInfo_ptr
 * @brief Unique pointer to FoundFlightInfo for managing flight data ownership.
 */
typedef std::unique_ptr<FoundFlightInfo> FlightInfo_ptr;

/**
 * @typedef PassengerInfo_ptr
 * @brief Unique pointer to PassengerInfo for managing passenger data ownership.
 */
typedef std::unique_ptr<PassengerInfo> PassengerInfo_ptr;

#endif /* HEADERS_FLIGHT_RESERVATION_INFO_HPP_ */
