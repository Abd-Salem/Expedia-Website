/**
 * @file Itinerary_Builder.cpp
 * @brief Implements itinerary construction and management
 * @details Provides methods for:
 *          - Adding flight/hotel reservations to itineraries
 *          - Validating and clearing itineraries
 *          - Retrieving completed itineraries
 *
 * @author Abdallah Salem
 */
#include"../include/Itinerary_Builder.hpp"

ItineraryBuilder::ItineraryBuilder() :
		it(std::make_unique<Itinerary>()), reserve(
				std::make_unique<MakeReservation>()) {

}

void ItineraryBuilder::addFlight() {
	auto reservation = reserve->reservingFlight();
	if (!reservation)
		return;
	it->addReservation(reservation);
}

void ItineraryBuilder::addHotel() {
	auto reservation = reserve->reservingRoom();
	if (!reservation)
		return;
	it->addReservation(reservation);
}

void ItineraryBuilder::clearItinerary() {
	it->clear();   //reset the bag.
}

bool ItineraryBuilder::checkItinerary() {
	//if empty return true
	if (it->isEmpty())
		return true;
	return false;
}

const Itinerary_ptr& ItineraryBuilder::getItinerary() {
	return it;
}
