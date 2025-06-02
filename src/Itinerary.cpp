/**
 * @file Itinerary.cpp
 * @brief Implements composite itinerary functionality
 * @details Features:
 *          - Reservation collection management
 *          - Cost calculation for multi-reservation trips
 *          - Detailed output generation
 *
 * @author Abdallah Salem
 */

#include "../inlcude/Itinerary.hpp"

Itinerary::~Itinerary() {
	Reservations.clear();
}

Itinerary::Itinerary(const Itinerary &other) {
	for (const auto &reservation : other.Reservations)
		addReservation(reservation);
}

Itinerary::Itinerary(Itinerary &&other) :
		Reservations(std::move(other.Reservations)) {
}

Itinerary& Itinerary::operator=(Itinerary &other) {
	if (this != &other) {
		for (const auto &reservation : other.Reservations)
			addReservation(reservation);
	}
	return *this;
}

Itinerary& Itinerary::operator=(Itinerary &&other) {
	if (this != &other)
		Reservations = std::move(other.Reservations);
	return *this;
}

void Itinerary::addReservation(const Reservation_ptr &reservation) {
	Reservations.push_back(reservation->clone());
}

void Itinerary::clear() {
	Reservations.clear();
}

bool Itinerary::isEmpty() {
	//return true if empty
	if (Reservations.empty())
		return true;
	return false;
}

double Itinerary::getCost() const {
	return (std::for_each(Reservations.begin(), Reservations.end(),
			Sum<double>())).sum;
}

Reservation_ptr Itinerary::clone() const {
	return std::make_unique < Itinerary > (*this);
}

void Itinerary::getDetails(std::ostream &&get) const {
	//collect data
	get << "Itinerary of " << Itinerary::Reservations.size()
			<< " sub-reservations: \n";
	for (const auto &reservation : Itinerary::Reservations) {
		reservation->getDetails(std::move(get));
		std::cout << "\n";
	}
	get << "\nItinerary Cost: " << Itinerary::getCost();
	get << "\n----------------------------------\n";
}

std::ostream& operator<<(std::ostream &out, const Itinerary &it) {
	it.getDetails(std::move(out));
	return out;
}

