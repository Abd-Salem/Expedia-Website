/**
 * @file Make_Reservation.cpp
 * @brief Implements reservation creation system
 * @details Provides:
 *          - Flight/hotel reservation workflows
 *          - User input collection for reservations
 *          - Brand-specific reservation object creation
 *
 * @author Abdallah Salem
 */

#include "../include/Make_Reservation.hpp"

MakeReservation::MakeReservation() :
		passenger_info(nullptr), customer_info(nullptr), chosen_flight(nullptr), chosen_room(
				nullptr) {
	//reload APIs of brands
	Airports.emplace_back(std::make_unique<CanadaFlightReservation>());
	Airports.emplace_back(std::make_unique<TurkishFlightReservation>());
	Hotels.emplace_back(std::make_unique<HiltonHotelReservation>());
	Hotels.emplace_back(std::make_unique<MarriottHotelReservation>());

}

Reservation_ptr MakeReservation::ReservationFactory(std::string &brand) {
	//set the API according to the brand name.
	if (brand == "Canada")
		return std::make_unique < CanadaFlightReservation
				> (std::move(passenger_info), std::move(chosen_flight));
	else if (brand == "Turkish")
		return std::make_unique < TurkishFlightReservation
				> (std::move(passenger_info), std::move(chosen_flight));
	else if (brand == "Hilton")
		return std::make_unique < HiltonHotelReservation
				> (std::move(customer_info), std::move(chosen_room));
	else if (brand == "Marriott")
		return std::make_unique < MarriottHotelReservation
				> (std::move(customer_info), std::move(chosen_room));
	return nullptr;
}

Reservation_ptr MakeReservation::reservingFlight() {
	passenger_info = std::make_unique<PassengerInfo>();
	chosen_flight = std::make_unique<FoundFlightInfo>();
	//get data from user
	std::cout << "\nFrom Which Country: ";
	std::cin >> passenger_info->from;
	std::cout << "\nDisired Departure Date from  " << passenger_info->from
			<< " : ";
	std::cin >> passenger_info->from_date;
	std::cout << "\nTo Which Country: ";
	std::cin >> passenger_info->to;
	std::cout << "\nDate to " << passenger_info->to << " : ";
	std::cin >> passenger_info->to_date;
	std::cout << "\nEnter number of adults - children (5 - 16) and infants: ";
	std::cin >> passenger_info->adults >> passenger_info->children
			>> passenger_info->infants;
	//get available flights from API
	std::vector < FoundFlightInfo > available_flights;
	for (const auto &airport : Airports)
		airport->getAvailableFlights(std::move(available_flights));
	for (const auto &flight : available_flights)
		std::cout << "Airline: " + flight.airline << " - Price: "
				<< std::to_string(flight.price) << " - Departure Date: "
				<< flight.from_date + " - Arrival Date: "
				<< flight.to_date + "\n";
	int choice { };
	//print choices to the user.
	std::cout << "Choose what suits you (-1 to cancel): \n";
	std::cin >> choice;
	if ((choice == -1) || (choice > (int) available_flights.size()))
		return nullptr;
	*chosen_flight = std::move(available_flights[choice - 1]);
	return MakeReservation::ReservationFactory(chosen_flight->airline);
}

Reservation_ptr MakeReservation::reservingRoom() {
	customer_info = std::make_unique<CustomerInfo>();
	chosen_room = std::make_unique<FoundRoomInfo>();
	//get data from user.
	std::cout << "\nCountry: ";
	std::cin >> customer_info->country;
	std::cout << "\nCity: ";
	std::cin >> customer_info->city;
	std::cout << "\nDate From: ";
	std::cin >> customer_info->from_date;
	std::cout << "\nDate to: ";
	std::cin >> customer_info->to_date;
	std::cout << "\nEnter Number of adults - children (5): ";
	std::cin >> customer_info->adults >> customer_info->children;
	std::cout << "\nEnter Number Of desired Nights: ";
	std::cin >> customer_info->number_of_nights;
	std::vector < FoundRoomInfo > available_rooms;
	//get available rooms from API.
	for (const auto &hotel : Hotels)
		hotel->getAvailableRooms(std::move(available_rooms));
	for (const auto &room : available_rooms)
		std::cout << "Hotel: " << room.hotel << " - Price: "
				<< std::to_string(room.price_for_night) << " - Departure Date: "
				<< room.from_date << " - Arrival Date: " << room.to_date + "\n";
	//print data to the user.
	int choice { };
	std::cout << "Choose the suits you (-1 to cancel): \n";
	std::cin >> choice;
	if ((choice == -1) || (choice > (int) available_rooms.size()))
		return nullptr;
	*chosen_room = std::move(available_rooms[choice - 1]);
	return MakeReservation::ReservationFactory(chosen_room->hotel);
}

