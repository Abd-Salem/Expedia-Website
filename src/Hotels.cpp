/**
 * @file Hotels.cpp
 * @brief Implements hotel reservation adapters
 * @details Contains:
 *          - HiltonHotelReservation: Adapter for Hilton hotels
 *          - MarriottHotelReservation: Adapter for Marriott hotels
 *          - Handles data conversion between system and hotel APIs
 *
 * @author Abdallah Salem
 */
#include"../include/Hotels.hpp"

HiltonHotelReservation::HiltonHotelReservation() :
		hilton_customer_info(std::make_unique<HiltonCustomerInfo>()), hilton_chosen_room(
				std::make_unique<HiltonRoom>()) {
}

HiltonHotelReservation::HiltonHotelReservation(CustomerInfo_ptr &&customer_info,
		RoomInfo_ptr &&chosen_room) :
		HiltonHotelReservation() {
	HiltonHotelReservation::setCustomerInfo(std::move(customer_info));
	HiltonHotelReservation::setChosenRoomInfo(std::move(chosen_room));
}

HiltonHotelReservation::HiltonHotelReservation(
		const HiltonHotelReservation &other) :
		HiltonHotelReservation() {
	*(hilton_customer_info) = *(other.hilton_customer_info);
	*(hilton_chosen_room) = *(other.hilton_chosen_room);
}

HiltonHotelReservation::HiltonHotelReservation(HiltonHotelReservation &&other) :
		hilton_customer_info(std::move(other.hilton_customer_info)), hilton_chosen_room(
				std::move(other.hilton_chosen_room)) {

}

HiltonHotelReservation& HiltonHotelReservation::operator =(
		const HiltonHotelReservation &other) {
	if (this != &other) {
		*(hilton_customer_info) = *(other.hilton_customer_info);
		*(hilton_chosen_room) = *(other.hilton_chosen_room);
	}
	return *this;
}

HiltonHotelReservation& HiltonHotelReservation::operator =(
		HiltonHotelReservation &&other) {
	if (this != &other) {
		hilton_customer_info = std::move(other.hilton_customer_info);
		hilton_chosen_room = std::move(other.hilton_chosen_room);
	}
	return *this;
}

void HiltonHotelReservation::setCustomerInfo(CustomerInfo_ptr &&info) {
	hilton_customer_info->country = info->country;
	hilton_customer_info->city = info->city;
	hilton_customer_info->date_from = info->from_date;
	hilton_customer_info->date_to = info->to_date;
	hilton_customer_info->adults = info->adults;
	hilton_customer_info->children = info->children;
	hilton_customer_info->needed_rooms = info->needed_rooms;
	hilton_customer_info->number_of_nights = info->number_of_nights;
}

void HiltonHotelReservation::getAvailableRooms(
		std::vector<FoundRoomInfo> &&rooms) {
	//dummy data sent by API
	std::vector < HiltonRoom > available_rooms = HiltonHotelAPI::searchRooms(
			*hilton_customer_info);
	for (int i = 0; i < (int) available_rooms.size(); i++)
		rooms.push_back(
				{ "Hilton", available_rooms[i].from_date,
						available_rooms[i].to_date,
						available_rooms[i].room_type,
						available_rooms[i].available_number,
						available_rooms[i].price_per_night });
}

void HiltonHotelReservation::setChosenRoomInfo(RoomInfo_ptr &&room_info) {
	hilton_chosen_room->price_per_night = room_info->price_for_night;
	hilton_chosen_room->room_type = room_info->view_type;
	hilton_chosen_room->from_date = room_info->from_date;
	hilton_chosen_room->to_date = room_info->to_date;
}
void HiltonHotelReservation::getDetails(std::ostream &&get) const {
	//collect data in one string.
	get << "Hotel Reservation / Hilton Hotel: " << hilton_customer_info->country
			<< " @ " << hilton_customer_info->city << "  from "
			<< hilton_customer_info->date_from << "  to "
			<< hilton_customer_info->date_to << " ("
			<< hilton_customer_info->number_of_nights << ")\n" << "\t\tAdults: "
			<< hilton_customer_info->adults << "\n\t\tChildren: "
			<< hilton_customer_info->children
			<< "\n\t\tRoom Cost For All Nights: "
			<< HiltonHotelReservation::getCost() << "\n";
}

Reservation_ptr HiltonHotelReservation::clone() const {
	return std::make_unique < HiltonHotelReservation > (*this);
}

bool HiltonHotelReservation::makeReservation() {
	return HiltonHotelAPI::reserveRoom(*hilton_customer_info,
			*hilton_chosen_room);
}

bool HiltonHotelReservation::cancelReservation() {
	return HiltonHotelAPI::cancelReservation(*hilton_customer_info,
			*hilton_chosen_room);
}

double HiltonHotelReservation::getCost() const {
	return hilton_chosen_room->price_per_night
			* hilton_customer_info->number_of_nights
			* hilton_customer_info->needed_rooms;
}

MarriottHotelReservation::MarriottHotelReservation() :
		marriott_customer_info(std::make_unique<MarriottCustomerInfo>()), marriott_chosen_room(
				std::make_unique<MarriottFoundRoom>()) {

}

MarriottHotelReservation::MarriottHotelReservation(
		CustomerInfo_ptr &&customer_info, RoomInfo_ptr &&chosen_room) :
		MarriottHotelReservation() {
	MarriottHotelReservation::setCustomerInfo(std::move(customer_info));
	MarriottHotelReservation::setChosenRoomInfo(std::move(chosen_room));
}

MarriottHotelReservation::MarriottHotelReservation(
		const MarriottHotelReservation &other) :
		MarriottHotelReservation() {
	//handle ownership of unique pointers.
	if (other.marriott_customer_info)
		*(marriott_customer_info) = *(other.marriott_customer_info);
	if (other.marriott_chosen_room)
		*(marriott_chosen_room) = *(other.marriott_chosen_room);
}

MarriottHotelReservation::MarriottHotelReservation(
		MarriottHotelReservation &&other) :
		marriott_customer_info(std::move(other.marriott_customer_info)), marriott_chosen_room(
				std::move(other.marriott_chosen_room)) {

}

MarriottHotelReservation& MarriottHotelReservation::operator =(
		const MarriottHotelReservation &other) {
	if (this != &other) {
		//handle ownership of unique pointer.
		if (other.marriott_customer_info)
			*(marriott_customer_info) = *(other.marriott_customer_info);
		if (other.marriott_chosen_room)
			*(marriott_chosen_room) = *(other.marriott_chosen_room);
	}
	return *this;
}

MarriottHotelReservation& MarriottHotelReservation::operator =(
		MarriottHotelReservation &&other) {
	if (this != &other) {
		marriott_customer_info = std::move(other.marriott_customer_info);
		marriott_chosen_room = std::move(other.marriott_chosen_room);
	}
	return *this;
}

void MarriottHotelReservation::setCustomerInfo(CustomerInfo_ptr &&info) {
	marriott_customer_info->country = info->country;
	marriott_customer_info->city = info->city;
	marriott_customer_info->date_from = info->from_date;
	marriott_customer_info->date_to = info->to_date;
	marriott_customer_info->adults = info->adults;
	marriott_customer_info->children = info->children;
	marriott_customer_info->needed_rooms = info->needed_rooms;
	marriott_customer_info->number_of_nights = info->number_of_nights;
}

void MarriottHotelReservation::getAvailableRooms(
		std::vector<FoundRoomInfo> &&rooms) {
	//dummy data sent by API
	std::vector < MarriottFoundRoom > available_rooms =
			MarriottHotelAPI::findRooms(*marriott_customer_info);
	for (int i = 0; i < (int) available_rooms.size(); i++)
		rooms.push_back(
				{ "Marriott", available_rooms[i].date_from,
						available_rooms[i].date_to,
						available_rooms[i].room_type,
						available_rooms[i].available_number,
						available_rooms[i].price_per_night });
}

void MarriottHotelReservation::setChosenRoomInfo(RoomInfo_ptr &&room_info) {
	marriott_chosen_room->price_per_night = room_info->price_for_night;
	marriott_chosen_room->room_type = room_info->view_type;
	marriott_chosen_room->date_from = room_info->from_date;
	marriott_chosen_room->date_to = room_info->to_date;
}
void MarriottHotelReservation::getDetails(std::ostream &&get) const {
	//collect all data in one string
	get << "Hotel Reservation / Marriott Hotel: "
			<< marriott_customer_info->country << " @ "
			<< marriott_customer_info->city << "  from "
			<< marriott_customer_info->date_from << "  to "
			<< marriott_customer_info->date_to << " ("
			<< marriott_customer_info->number_of_nights << ")\n"
			<< "\t\tAdults: " << marriott_customer_info->adults
			<< "\n\t\tChildren: " << marriott_customer_info->children
			<< "\n\t\tRoom Cost For ALl Nights: "
			<< MarriottHotelReservation::getCost() << "\n";
}

Reservation_ptr MarriottHotelReservation::clone() const {
	return std::make_unique < MarriottHotelReservation > (*this);
}

bool MarriottHotelReservation::makeReservation() {
	return MarriottHotelAPI::reserveRoom(*marriott_chosen_room,
			*marriott_customer_info);
}

bool MarriottHotelReservation::cancelReservation() {
	return MarriottHotelAPI::cancelReservation(*marriott_chosen_room,
			*marriott_customer_info);
}

double MarriottHotelReservation::getCost() const {
	return marriott_chosen_room->price_per_night
			* marriott_customer_info->number_of_nights
			* marriott_customer_info->needed_rooms;
}

