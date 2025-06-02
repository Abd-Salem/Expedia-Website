/**
 * @file Airports.cpp
 * @brief Implements flight reservation adapters for airlines
 * @details Contains:
 *          - CanadaFlightReservation: Adapter for Air Canada flights
 *          - TurkishFlightReservation: Adapter for Turkish Airlines flights
 *          - Handles data conversion between system and airline APIs
 *
 * @author Abdallah Salem
 */

#include"../include/Airports.hpp"

CanadaFlightReservation::CanadaFlightReservation() :
		canada_customer_info(std::make_unique<AirCanadaCustomerInfo>()), canada_chosen_flight(
				std::make_unique<AirCanadaFlight>()) {

}

CanadaFlightReservation::CanadaFlightReservation(
		PassengerInfo_ptr &&customer_info, FlightInfo_ptr &&chosen_flight) :
		CanadaFlightReservation() {
	CanadaFlightReservation::setCustomerInfo(std::move(customer_info));
	CanadaFlightReservation::setChosenFlight(std::move(chosen_flight));
}

CanadaFlightReservation::CanadaFlightReservation(
		const CanadaFlightReservation &other) :
		CanadaFlightReservation() {
	//handling ownership of unique pointers.
	*(canada_customer_info) = *(other.canada_customer_info);
	*(canada_chosen_flight) = *(other.canada_chosen_flight);
}

CanadaFlightReservation::CanadaFlightReservation(
		CanadaFlightReservation &&other) :
		canada_customer_info(std::move(canada_customer_info)), canada_chosen_flight(
				std::move(canada_chosen_flight)) {

}

CanadaFlightReservation& CanadaFlightReservation::operator=(
		const CanadaFlightReservation &other) {
	if (this != &other) {
		//handling ownership of unique pointers.
		*(canada_customer_info) = *(other.canada_customer_info);
		*(canada_chosen_flight) = *(other.canada_chosen_flight);
	}
	return *this;
}

CanadaFlightReservation& CanadaFlightReservation::operator=(
		CanadaFlightReservation &&other) {
	if (this != &other) {
		//move ownership semantically
		canada_customer_info = std::move(canada_customer_info);
		canada_chosen_flight = std::move(canada_chosen_flight);
	}
	return *this;
}

void CanadaFlightReservation::setCustomerInfo(PassengerInfo_ptr &&info) {
	canada_customer_info->from = info->from;
	canada_customer_info->to = info->to;
	canada_customer_info->date_time_from = info->from_date;
	canada_customer_info->date_time_to = info->to_date;
	canada_customer_info->adults = info->adults;
	canada_customer_info->children = info->children;
	canada_customer_info->infants = info->infants;
}

void CanadaFlightReservation::setChosenFlight(FlightInfo_ptr &&info) {
	canada_chosen_flight->date_time_from = info->from_date;
	canada_chosen_flight->date_time_to = info->to_date;
	canada_chosen_flight->price = info->price;
}

void CanadaFlightReservation::getAvailableFlights(
		std::vector<FoundFlightInfo> &&flights) {
	//get information from API
	std::vector < AirCanadaFlight > available_flights =
			AirCanadaOnlineAPI::getFlights();
	//Adding brand name to information
	for (int i = 0; i < (int) available_flights.size(); i++)
		flights.push_back(
				{ "Canada", available_flights[i].price,
						available_flights[i].date_time_from,
						available_flights[i].date_time_to });
}

void CanadaFlightReservation::getDetails(std::ostream &&get) const {
	//collect data in one string
	get << "Airline Reservation/ AirCanada Airline: \n" << "From: "
			<< canada_customer_info->from << "  on: "
			<< canada_customer_info->date_time_from << "  To: "
			<< canada_customer_info->to << "  on: "
			<< canada_customer_info->date_time_to << "\n" << "\t\tAdults: "
			<< canada_customer_info->adults << "  -  Children: "
			<< canada_customer_info->children << "  -  Infants: "
			<< canada_customer_info->infants << "\n" << "\t\tFlight Cost: "
			<< CanadaFlightReservation::getCost();
}
Reservation_ptr CanadaFlightReservation::clone() const {
	return std::make_unique < CanadaFlightReservation > (*this);
}

double CanadaFlightReservation::getCost() const {
	return canada_chosen_flight->price
			* (canada_customer_info->adults + canada_customer_info->children
					+ canada_customer_info->infants);
}

bool CanadaFlightReservation::makeReservation() {
	//calling API
	return AirCanadaOnlineAPI::reserveFlight(*canada_chosen_flight,
			*canada_customer_info);
}

bool CanadaFlightReservation::cancelReservation() {
	//Calling API
	return AirCanadaOnlineAPI::cancelReserveFlight(*canada_chosen_flight,
			*canada_customer_info);
}

TurkishFlightReservation::TurkishFlightReservation() :
		turkish_customer_info(std::make_unique<TurkishCustomerInfo>()), turkish_chosen_flight(
				std::make_unique<TurkishFlight>()) {

}

TurkishFlightReservation::TurkishFlightReservation(
		PassengerInfo_ptr &&customer_info, FlightInfo_ptr &&chosen_flight) :
		TurkishFlightReservation() {
	TurkishFlightReservation::setCustomerInfo(std::move(customer_info));
	TurkishFlightReservation::setChosenFlight(std::move(chosen_flight));
}

TurkishFlightReservation::TurkishFlightReservation(
		const TurkishFlightReservation &other) :
		TurkishFlightReservation() {
	//handling ownership of unique pointers.
	if (other.turkish_customer_info)
		*(turkish_customer_info) = *(other.turkish_customer_info);
	if (other.turkish_chosen_flight)
		*(turkish_chosen_flight) = *(other.turkish_chosen_flight);
}

TurkishFlightReservation::TurkishFlightReservation(
		TurkishFlightReservation &&other) :
		turkish_customer_info(std::move(turkish_customer_info)), turkish_chosen_flight(
				std::move(turkish_chosen_flight)) {

}

TurkishFlightReservation& TurkishFlightReservation::operator =(
		const TurkishFlightReservation &other) {
	if (this != &other) {
		//handling ownership of unique pointers.
		if (other.turkish_customer_info)
			*(turkish_customer_info) = *(other.turkish_customer_info);
		if (other.turkish_chosen_flight)
			*(turkish_chosen_flight) = *(other.turkish_chosen_flight);
	}
	return *this;
}

TurkishFlightReservation& TurkishFlightReservation::operator =(
		TurkishFlightReservation &&other) {
	if (this != &other) {
		turkish_customer_info = std::move(other.turkish_customer_info);
		turkish_chosen_flight = std::move(other.turkish_chosen_flight);
	}
	return *this;
}

void TurkishFlightReservation::setCustomerInfo(PassengerInfo_ptr &&info) {
	turkish_customer_info->from = info->from;
	turkish_customer_info->to = info->to;
	turkish_customer_info->datetime_from = info->from_date;
	turkish_customer_info->datetime_to = info->to_date;
	turkish_customer_info->adults = info->adults;
	turkish_customer_info->children = info->children;
	turkish_customer_info->infants = info->infants;
}

void TurkishFlightReservation::setChosenFlight(FlightInfo_ptr &&info) {
	turkish_chosen_flight->datetime_from = info->from_date;
	turkish_chosen_flight->datetime_to = info->to_date;
	turkish_chosen_flight->cost = info->price;
}

void TurkishFlightReservation::getAvailableFlights(
		std::vector<FoundFlightInfo> &&flights) {
	//get information from API
	std::vector < TurkishFlight > available_flights =
			TurkishAirlineOnlineAPI::getAvailableFlights();
	//add brand name to information
	for (int i = 0; i < (int) available_flights.size(); i++)
		flights.push_back(
				{ "Turkish", available_flights[i].cost,
						available_flights[i].datetime_from,
						available_flights[i].datetime_to });
}

void TurkishFlightReservation::getDetails(std::ostream &&get) const {
	//collect data in one string.
	get << "Airline Reservation/ Turkish Airline: \n" << "From: "
			<< turkish_customer_info->from << "  on: "
			<< turkish_customer_info->datetime_from << "  To: "
			<< turkish_customer_info->to << "  on: "
			<< turkish_customer_info->datetime_to << "\n" << "\t\tAdults: "
			<< turkish_customer_info->adults << "  -  Children: "
			<< turkish_customer_info->children << "  -  "
			<< turkish_customer_info->infants << "\n" << "\t\tFlight Cost: "
			<< TurkishFlightReservation::getCost();
}

double TurkishFlightReservation::getCost() const {
	return turkish_chosen_flight->cost
			* (turkish_customer_info->adults + turkish_customer_info->children
					+ turkish_customer_info->infants);
}

Reservation_ptr TurkishFlightReservation::clone() const {
	return std::make_unique < TurkishFlightReservation > (*this);
}

bool TurkishFlightReservation::makeReservation() {
	//calling API
	return TurkishAirlineOnlineAPI::reserveFlight(*turkish_customer_info,
			*turkish_chosen_flight);
}

bool TurkishFlightReservation::cancelReservation() {
	//calling API
	return TurkishAirlineOnlineAPI::cancelReservedFlight(*turkish_customer_info,
			*turkish_chosen_flight);
}

