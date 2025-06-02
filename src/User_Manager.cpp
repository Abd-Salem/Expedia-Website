/**
 * @file User_Manager.cpp
 * @brief Implements user account management system
 * @details Handles:
 *          - User registration and authentication
 *          - Profile management
 *          - Itinerary storage and retrieval
 * @author Abdallah Salem
 * @date Created: May 31, 2025
 */
#include"../include/User_Manager.hpp"

UserManager::UserManager() :
		logged_user(nullptr) {

}

void UserManager::signUpUser() {
	//suppose the operation is secured and support error handling.
	std::string username, pass, email;
	std::cout << "\nEnter User's name: ";
	std::cin >> username;
	std::cout << "\nEnter Password: ";
	std::cin >> pass;
	std::cout << "\nEnter Email: ";
	std::cin >> email;
	if (UserManager::checkUsernameExistence(std::move(username))
			|| UserManager::checkUserEmailExistence(std::move(email)))
		return;

	Users.emplace_back(std::make_shared < User > (username, pass, email));
}

void UserManager::signInUser() {
	std::string user_input;
	std::cout << "Enter User's name: \n";
	std::cin >> user_input;
	for (const auto &user : Users)
		if (user->getUsername() == user_input) {
			std::cout << "Enter Password: \n";
			std::cin >> user_input;
			if (user->getPassword() == user_input)
				logged_user = user;
			else
				return;
		}
}

void UserManager::logoutUser() {
	logged_user = nullptr;  //reset
}

User_Shared_ptr UserManager::checkLoggedUser() {
	return logged_user;
}

bool UserManager::checkUsernameExistence(const std::string &&_username) const {
	for (auto const &user : Users)
		if (_username == user->getUsername())
			return true;
	return false;
}

bool UserManager::checkUserEmailExistence(const std::string &&_email) const {
	for (auto const &user : Users)
		if (_email == user->getEmail())
			return true;
	return false;
}

void UserManager::viewUserProfile() const {
	if (!logged_user)
		return;
	logged_user->viewMyProfile();
}
void UserManager::viewUserItineraries() const {
	if (!logged_user)
		return;
	logged_user->viewMyItineraries();
}
void UserManager::addItineraryToUser(const Itinerary_ptr &it) {
	if (!logged_user)
		return;
	logged_user->addItinerary(it);
}
void UserManager::removeItineraryFromUser(Itinerary_ptr &it) {
	if (!logged_user)
		return;
	logged_user->removeItinerary(it);
}
