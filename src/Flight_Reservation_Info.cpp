/**
 * @file Flight_Reservation_Info.cpp
 * @brief Implements flight information data structures
 * @details Contains method definitions for:
 *          - FoundFlightInfo: Available flight details
 *          - PassengerInfo: Passenger booking details
 *
 * @author Abdallah Salem
 */

#include"../include/Flight_Reservation_Info.hpp"

FoundFlightInfo::FoundFlightInfo(std::string airline, double price,
		std::string from_date, std::string to_date) :
		airline(airline), price(price), from_date(from_date), to_date(to_date) {

}

FoundFlightInfo::FoundFlightInfo(const FoundFlightInfo &other) :
		airline(other.airline), price(other.price), from_date(other.from_date), to_date(
				other.to_date) {

}

FoundFlightInfo::FoundFlightInfo(FoundFlightInfo &&other) :
		airline(std::move(other.airline)), price(std::move(other.price)), from_date(
				std::move(other.from_date)), to_date(std::move(other.to_date)) {

}

FoundFlightInfo& FoundFlightInfo::operator=(const FoundFlightInfo &other) {
	if (this != &other) {
		airline = other.airline;
		price = other.price;
		from_date = other.from_date;
		to_date = other.to_date;
	}
	return *this;
}

FoundFlightInfo& FoundFlightInfo::operator=(FoundFlightInfo &&other) {
	if (this != &other) {
		airline = std::move(other.airline);
		price = std::move(other.price);
		from_date = std::move(other.from_date);
		to_date = std::move(other.to_date);
	}
	return *this;
}

PassengerInfo::PassengerInfo(std::string from_date, std::string to_date,
		std::string from, std::string to, int children, int adults, int infants) :
		from_date(from_date), to_date(to_date), from(from), to(to), children(
				children), adults(adults), infants(infants) {
}

PassengerInfo::PassengerInfo(const PassengerInfo &other) :
		from_date(other.from_date), to_date(other.to_date), from(other.from), to(
				other.to), children(other.children), adults(other.adults), infants(
				other.infants) {
}

PassengerInfo::PassengerInfo(PassengerInfo &&other) :
		from_date(std::move(other.from_date)), to_date(
				std::move(other.to_date)), from(std::move(other.from)), to(
				std::move(other.to)), children(std::move(other.children)), adults(
				std::move(other.adults)), infants(std::move(other.infants)) {

}

PassengerInfo& PassengerInfo::operator=(const PassengerInfo &other) {
	if (this != &other) {
		from_date = other.from_date;
		to_date = other.to_date;
		from = other.from;
		to = other.to;
		children = other.children;
		adults = other.adults;
		infants = other.infants;
	}
	return *this;
}

PassengerInfo& PassengerInfo::operator=(PassengerInfo &&other) {
	if (this != &other) {
		from_date = std::move(other.from_date);
		to_date = std::move(other.to_date);
		from = std::move(other.from);
		to = std::move(other.to);
		children = std::move(other.children);
		adults = std::move(other.adults);
		infants = std::move(other.infants);
	}
	return *this;
}

