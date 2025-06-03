/**
 * @file Airport_APIs.hpp
 * @brief Defines airline customer information, flight data, and API interfaces for Air Canada and Turkish Airlines
 * @details Provides classes for:
 *          - Airline customer information (AirCanadaCustomerInfo, TurkishCustomerInfo)
 *          - Flight details (AirCanadaFlight, TurkishFlight)
 *          - API operations (AirCanadaOnlineAPI, TurkishAirlineOnlineAPI)
 * @author Abdallah Salem
 *
 */

#ifndef HEADERS_AIRPORTS_APIS_HPP_
#define HEADERS_AIRPORTS_APIS_HPP_
#include<iostream>
#include<vector>

/**
 * @class AirCanadaCustomerInfo
 * @brief Stores customer information for Air Canada flight bookings.
 *
 * This class encapsulates the travel preferences and passenger details required
 * for booking flights with Air Canada.
 */
class AirCanadaCustomerInfo {
public:
	std::string from;  ///< Origin airport or city.
	std::string to;   ///< Destination airport or city.
	std::string date_time_from;    ///< Departure date and time.
	std::string date_time_to;     ///< Arrival date and time.
	int adults { };             ///< Number of adult passengers.
	int children { };           ///< Number of child passengers.
	int infants { };            ///< Number of infant passengers.

	/*
	 * @brief default constructor.
	 */
	AirCanadaCustomerInfo() = default;

	/**
	 * @brief Parameterized constructor.
	 * @param from Origin airport or city.
	 * @param to Destination airport or city.
	 * @param date_time_from Departure date and time.
	 * @param date_time_to Arrival date and time.
	 * @param adults Number of adult passengers.
	 * @param children Number of child passengers.
	 * @param infants Number of infant passengers.
	 */
	AirCanadaCustomerInfo(std::string from, std::string to,
			std::string date_time_from, std::string date_time_to, int adults,
			int children, int infants);
};

/**
 * @class AirCanadaFlight
 * @brief Represents a flight offered by Air Canada.
 *
 * This class holds flight-specific details such as price and travel dates.
 */

class AirCanadaFlight {
public:
	double price { };           ///< Price of the flight.
	std::string date_time_from; ///< Departure date and time.
	std::string date_time_to;   ///< Arrival date and time.

	/*
	 * @brief default constructor.
	 */
	AirCanadaFlight() = default;

	/**
	 * @brief Parameterized constructor.
	 * @param price Cost of the flight.
	 * @param from Departure date and time.
	 * @param to Arrival date and time.
	 */
	AirCanadaFlight(double price, std::string from, std::string to);
};

/**
 * @class AirCanadaOnlineAPI
 * @brief Interface for interacting with Air Canada's online booking system.
 *
 * Provides static methods to manage flight reservations and retrieve available flights.
 */

class AirCanadaOnlineAPI {
public:
	/**
	 * @brief Sets customer information for a booking session.
	 * @param info Customer information to set.
	 */
	static void setCustomerInfo(const AirCanadaCustomerInfo &info);

	/**
	 * @brief Retrieves a list of available flights.
	 * @return Vector of available AirCanadaFlight objects.
	 */
	static std::vector<AirCanadaFlight> getFlights();

	/**
	 * @brief Attempts to reserve a flight.
	 * @param flight Flight to reserve.
	 * @param info Customer information for the reservation.
	 * @return True if reservation succeeds, false otherwise.
	 */

	static bool reserveFlight(const AirCanadaFlight &flight,
			const AirCanadaCustomerInfo &info);

	/**
	 * @brief Cancels a flight reservation.
	 * @param flight Flight to cancel.
	 * @param info Customer information associated with the reservation.
	 * @return True if cancellation succeeds, false otherwise.
	 */
	static bool cancelReserveFlight(const AirCanadaFlight &flight,
			const AirCanadaCustomerInfo &info);
};

/**
 * @class TurkishCustomerInfo
 * @brief Stores customer information for Turkish Airlines flight bookings.
 *
 * Similar to AirCanadaCustomerInfo, this class holds travel and passenger details
 * specific to Turkish Airlines.
 */
class TurkishCustomerInfo {
public:
	std::string from;          ///< Origin airport or city.
	std::string to;            ///< Destination airport or city.
	std::string datetime_from; ///< Departure date and time.
	std::string datetime_to;   ///< Arrival date and time.
	int adults { };            ///< Number of adult passengers.
	int children { };          ///< Number of child passengers.
	int infants { };           ///< Number of infant passengers.

	/**
	 * @brief Default constructor.
	 */
	TurkishCustomerInfo() = default;

	/**
	 * @brief Parameterized constructor.
	 * @param from Origin airport or city.
	 * @param to Destination airport or city.
	 * @param datetime_from Departure date and time.
	 * @param datetime_to Arrival date and time.
	 * @param adults Number of adult passengers.
	 * @param children Number of child passengers.
	 * @param infants Number of infant passengers.
	 */
	TurkishCustomerInfo(std::string from, std::string to,
			std::string datetime_from, std::string datetime_to, int adults,
			int children, int infants);
};

/**
 * @class TurkishFlight
 * @brief Represents a flight offered by Turkish Airlines.
 */

class TurkishFlight {
public:
	double cost { };           ///< Cost of the flight.
	std::string datetime_from; ///< Departure date and time.
	std::string datetime_to;   ///< Arrival date and time.
	/*
	 * @brief default constructor
	 */
	TurkishFlight() = default;

	/**
	 * @brief Parameterized constructor.
	 * @param cost Cost of the flight.
	 * @param from Departure date and time.
	 * @param to Arrival date and time.
	 */
	TurkishFlight(double cost, std::string from, std::string to);
};

/**
 * @class TurkishAirlineOnlineAPI
 * @brief Interface for interacting with Turkish Airlines' online booking system.
 */
class TurkishAirlineOnlineAPI {
public:
	/**
	 * @brief Sets travel origin and destination information.
	 * @param info Customer information to set.
	 */
	static void setFromToInfo(const TurkishCustomerInfo &info);

	/**
	 * @brief Sets passenger details.
	 * @param info Customer information to set.
	 */
	static void setPassengerInfo(const TurkishCustomerInfo &info);

	/**
	 * @brief Retrieves a list of available flights.
	 * @return Vector of available TurkishFlight objects.
	 */
	static std::vector<TurkishFlight> getAvailableFlights();

	/**
	 * @brief Attempts to reserve a flight.
	 * @param info Customer information for the reservation.
	 * @param flight Flight to reserve.
	 * @return True if reservation succeeds, false otherwise.
	 */
	static bool reserveFlight(const TurkishCustomerInfo &info,
			const TurkishFlight &flight);

	/**
	 * @brief Cancels a flight reservation.
	 * @param info Customer information associated with the reservation.
	 * @param flight Flight to cancel.
	 * @return True if cancellation succeeds, false otherwise.
	 */
	static bool cancelReservedFlight(const TurkishCustomerInfo &info,
			const TurkishFlight &flight);
};

#endif /* HEADERS_AIRPORTS_APIS_HPP_ */

