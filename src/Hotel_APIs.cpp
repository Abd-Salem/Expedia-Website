/**
 * @file hotels_APIs.cpp
 * @brief Implements hotel API operations for Hilton and Marriott
 * @details Provides concrete implementations for:
 *          - Hotel customer info and room data classes
 *          - API interaction methods for room search and reservations
 *          - Dummy data generation for demonstration purposes
 *
 * @author Abdallah Salem
 */
#include"../include/Hotel_APIs.hpp"

HiltonCustomerInfo::HiltonCustomerInfo(std::string country, std::string city,
		std::string date_from, std::string date_to, int needed_rooms,
		int adults, int children, int number_of_nights) :
		country(country), city(city), date_from(date_from), date_to(date_to), needed_rooms(
				needed_rooms), adults(adults), children(children), number_of_nights(
				number_of_nights) {

}

HiltonRoom::HiltonRoom(std::string room_type, int available_number,
		double price, std::string from, std::string to) :
		room_type(room_type), available_number(available_number), price_per_night(
				price), from_date(from), to_date(to) {

}

void HiltonHotelAPI::setCustomerInfo(const HiltonCustomerInfo &customer_info) {
	//suppose API take the data and set it.
}

bool HiltonHotelAPI::reserveRoom(const HiltonCustomerInfo &customer_info,
		const HiltonRoom &room_info) {
	//suppose the API reserve the room successfully.
	return true;
}

bool HiltonHotelAPI::cancelReservation(const HiltonCustomerInfo &customer_info,
		const HiltonRoom &room_info) {
	//suppose the API cancel the reservation successfully.
	return true;
}

std::vector<HiltonRoom> HiltonHotelAPI::searchRooms(
		HiltonCustomerInfo &customer_info) {
	std::vector < HiltonRoom > rooms;
	//dummy data sent by the API
	rooms.push_back(HiltonRoom { "Interior View", 6, 200, "29-01-2022",
			"10-02-2022" });
	rooms.push_back(
			HiltonRoom { "City View", 3, 300, "29-01-2022", "10-02-2022" });
	rooms.push_back(HiltonRoom { "Deluxe View", 8, 500, "29-01-2022",
			"10-02-2022" });
	return rooms;
}

MarriottCustomerInfo::MarriottCustomerInfo(std::string country,
		std::string city, std::string date_from, std::string date_to,
		int needed_rooms, int adults, int children, int number_of_nights) :
		country(country), city(city), date_from(date_from), date_to(date_to), needed_rooms(
				needed_rooms), adults(adults), children(children), number_of_nights(
				number_of_nights) {

}

MarriottFoundRoom::MarriottFoundRoom(std::string type, int available_number,
		double price, std::string from, std::string to) :
		room_type(type), available_number(available_number), price_per_night(
				price), date_from(from), date_to(to) {
}

void MarriottHotelAPI::setCustomerInfo(
		const MarriottCustomerInfo &customer_info) {
	//suppose API set the data.

}

std::vector<MarriottFoundRoom> MarriottHotelAPI::findRooms(
		const MarriottCustomerInfo &customer_info) {
	std::vector < MarriottFoundRoom > rooms;
	//dummy data sent by the API
	rooms.push_back( { "City View", 8, 320, "29-01-2022", "10-02-2022" });
	rooms.push_back( { "Interior View", 8, 220, "29-01-2022", "10-02-2022" });
	rooms.push_back( { "Private View", 5, 600, "29-01-2022", "10-02-2022" });
	return rooms;
}

bool MarriottHotelAPI::cancelReservation(const MarriottFoundRoom &room_info,
		const MarriottCustomerInfo &customer_info) {
	//suppose API cancel the reservation successfully.
	return true;
}

bool MarriottHotelAPI::reserveRoom(const MarriottFoundRoom &room_info,
		const MarriottCustomerInfo &customer_info) {
	//suppose the API reserve the room successfully.
	return true;
}
