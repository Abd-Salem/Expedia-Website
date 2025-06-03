/**
 * @file User.cpp
 * @brief Implements user entity functionality
 * @details Provides methods for:
 *          - User profile management
 *          - Itinerary storage and viewing
 *          - User information handling
 *
 * @author Abdallah Salem
 */
#include "../include/user.hpp"

Itinerary_ptr User::dynamicCast(Reservation_ptr &&reservation) {
	if (Itinerary *it = dynamic_cast<Itinerary*>(reservation.get())) {
		reservation.release();
		return std::make_unique < Itinerary > (*it);
	} else
		return nullptr;
}

User::User(std::string username, std::string password, std::string email) :
		username(username), password(password), email(email) {

}

User::User(const User &other) :
		username(other.username), password(other.password), email(other.email) {
	for (const auto &it : other.Itineraries)
		User::addItinerary(it);
}

User::User(User &&other) :
		username(std::move(other.username)), password(
				std::move(other.password)), email(std::move(other.email)), Itineraries(
				std::move(other.Itineraries)) {

}

User& User::operator=(const User &other) {
	if (this != &other) {
		username = other.username;
		password = other.password;
		email = other.email;
		for (const auto &it : other.Itineraries)
			User::addItinerary(it);
	}
	return *this;
}

User& User::operator=(User &&other) {
	if (this != &other) {
		username = std::move(other.username);
		password = std::move(other.password);
		email = std::move(other.email);
		Itineraries = std::move(other.Itineraries);
	}
	return *this;
}

const std::string& User::getUsername() const {
	return username;
}
const std::string& User::getPassword() const {
	return password;
}
const std::string& User::getEmail() const {
	return email;
}

void User::viewMyProfile() const {
	std::cout << "\nUser's Profile: \n";
	std::cout << "----------------------\n\n";
	std::cout << "Name: " << username;
	std::cout << "\nEmail: " << email << "\n\n";
}
void User::viewMyItineraries() const {
	double total { };
	for (const auto &it : Itineraries) {
		std::cout << (*it);
		total += it->getCost();
	}
	std::cout << "\nTotal Cost for All Itineraries: " << total << "\n\n";
}
void User::addItinerary(const Itinerary_ptr &it) {
	Itineraries.push_back(User::dynamicCast(std::move(it->clone())));
}
void User::removeItinerary(Itinerary_ptr &it) {
	it.reset();
	Itineraries.erase(
			std::remove(Itineraries.begin(), Itineraries.end(), nullptr),
			Itineraries.end());
}

