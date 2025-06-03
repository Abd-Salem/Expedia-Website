/**
 * @file Hotel_Reservation_Info.cpp
 * @brief Implements hotel reservation information data structures
 * @details Contains method definitions for:
 *          - FoundRoomInfo: Available room details
 *          - CustomerInfo: Hotel booking customer details
 *          - Move and copy operations for data transfer
 *
 * @author Abdallah Salem
 */
#include"../include/Hotel_Reservation_Info.hpp"

FoundRoomInfo::FoundRoomInfo(FoundRoomInfo &&other) :
		hotel(std::move(other.hotel)), from_date(std::move(other.from_date)), to_date(
				std::move(other.to_date)), view_type(
				std::move(other.view_type)), how_many(
				std::move(other.how_many)), price_for_night(
				std::move(other.price_for_night)) {

}

FoundRoomInfo::FoundRoomInfo(const FoundRoomInfo &other) :
		hotel(other.hotel), from_date(other.from_date), to_date(other.to_date), view_type(
				other.view_type), how_many(other.how_many), price_for_night(
				other.price_for_night) {

}

FoundRoomInfo::FoundRoomInfo(std::string hotel, std::string from_date,
		std::string to_date, std::string view_type, int how_many, double price) :
		hotel(hotel), from_date(from_date), to_date(to_date), view_type(
				view_type), how_many(how_many), price_for_night(price) {

}
FoundRoomInfo& FoundRoomInfo::operator=(const FoundRoomInfo &other) {
	if (this != &other) {
		hotel = other.hotel;
		to_date = other.to_date;
		from_date = other.from_date;
		view_type = other.view_type;
		how_many = other.how_many;
		price_for_night = other.price_for_night;
	}
	return *this;
}

FoundRoomInfo& FoundRoomInfo::operator=(FoundRoomInfo &&other) {
	if (this != &other) {
		hotel = std::move(other.hotel);
		to_date = std::move(other.to_date);
		from_date = std::move(other.from_date);
		view_type = std::move(other.view_type);
		how_many = std::move(other.how_many);
		price_for_night = std::move(other.price_for_night);
	}
	return *this;
}

CustomerInfo::CustomerInfo(std::string from_date, std::string to_date,
		std::string country, std::string city, int children, int adults,
		int needed_rooms, int number_of_nights) :
		from_date(from_date), to_date(to_date), country(country), city(city), children(
				children), adults(adults), needed_rooms(needed_rooms), number_of_nights(
				number_of_nights) {

}

CustomerInfo::CustomerInfo(const CustomerInfo &other) :
		from_date(other.from_date), to_date(other.to_date), country(
				other.country), city(other.city), children(other.children), adults(
				other.adults), needed_rooms(other.needed_rooms), number_of_nights(
				other.number_of_nights) {

}

CustomerInfo::CustomerInfo(CustomerInfo &&other) :
		from_date(std::move(other.from_date)), to_date(
				std::move(other.to_date)), country(std::move(other.country)), city(
				std::move(other.city)), children(std::move(other.children)), adults(
				std::move(other.adults)), needed_rooms(
				std::move(other.needed_rooms)), number_of_nights(
				std::move(other.number_of_nights)) {

}

CustomerInfo& CustomerInfo::operator =(const CustomerInfo &other) {
	if (this != &other) {
		from_date = other.from_date;
		to_date = other.to_date;
		country = other.country;
		city = other.city;
		children = other.children;
		adults = other.adults;
		needed_rooms = other.needed_rooms;
		number_of_nights = other.number_of_nights;
	}
	return *this;
}

CustomerInfo& CustomerInfo::operator =(CustomerInfo &&other) {
	if (this != &other) {
		from_date = std::move(other.from_date);
		to_date = std::move(other.to_date);
		country = std::move(other.country);
		city = std::move(other.city);
		children = std::move(other.children);
		adults = std::move(other.adults);
		needed_rooms = std::move(other.needed_rooms);
		number_of_nights = std::move(other.number_of_nights);
	}
	return *this;
}

