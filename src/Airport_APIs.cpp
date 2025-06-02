/**
 * @file Airport_APIs.cpp
 * @brief Implements airline API operations for Air Canada and Turkish Airlines
 * @details Provides concrete implementations for:
 *          - Customer info and flight classes
 *          - API interaction methods
 *          - Flight retrieval and reservation handling
 *
 * @author Abdallah Salem
 */

#include"../include/Airport_APIs.hpp"

AirCanadaCustomerInfo::AirCanadaCustomerInfo(std::string from, std::string to,
		std::string date_time_from, std::string date_time_to, int adults,
		int children, int infants) :
		from(from), to(to), date_time_from(date_time_from), date_time_to(
				date_time_to), adults(adults), children(children), infants(
				infants) {

}

AirCanadaFlight::AirCanadaFlight(double price, std::string from, std::string to) :
		price(price), date_time_from(from), date_time_to(to) {
}

void AirCanadaOnlineAPI::setCustomerInfo(const AirCanadaCustomerInfo &info) {
	//API operations to set information
}

std::vector<AirCanadaFlight> AirCanadaOnlineAPI::getFlights() {
	//dummy data for available flights returned from API
	std::vector < AirCanadaFlight > flights;
	flights.push_back(AirCanadaFlight { 200, "25-01-2022", "10-02-2022" });
	flights.push_back(AirCanadaFlight { 250, "29-01-2022", "10-02-2022" });
	return flights;
}

bool AirCanadaOnlineAPI::reserveFlight(const AirCanadaFlight &flight,
		const AirCanadaCustomerInfo &info) {
	//API makes the reservation and return true.
	return true;
}

bool AirCanadaOnlineAPI::cancelReserveFlight(const AirCanadaFlight &flight,
		const AirCanadaCustomerInfo &info) {
	//API cancel the reservation and return true.
	return false;
}

TurkishCustomerInfo::TurkishCustomerInfo(std::string from, std::string to,
		std::string datetime_from, std::string datetime_to, int adults,
		int children, int infants) :
		from(from), to(to), datetime_from(datetime_from), datetime_to(
				datetime_to), adults(adults), children(children), infants(
				infants) {
}

TurkishFlight::TurkishFlight(double cost, std::string from, std::string to) :
		cost(cost), datetime_from(from), datetime_to(to) {

}

void TurkishAirlineOnlineAPI::setFromToInfo(const TurkishCustomerInfo &info) {
	//API operations to set information about flight
}
void TurkishAirlineOnlineAPI::setPassengerInfo(
		const TurkishCustomerInfo &info) {
	//API operations to set information about passenger

}

std::vector<TurkishFlight> TurkishAirlineOnlineAPI::getAvailableFlights() {
	//dummy data returned form API.
	std::vector < TurkishFlight > flights;
	flights.push_back(TurkishFlight { 200, "25-01-2022", "10-02-2022" });
	flights.push_back(TurkishFlight { 250, "29-01-2022", "10-02-2022" });
	return flights;
}

bool TurkishAirlineOnlineAPI::reserveFlight(const TurkishCustomerInfo &info,
		const TurkishFlight &flight) {
	//API makes the reservation and return true.
	return true;
}

bool TurkishAirlineOnlineAPI::cancelReservedFlight(
		const TurkishCustomerInfo &info, const TurkishFlight &flight) {
	//API cancels the reservation and return true.
	return false;
}
