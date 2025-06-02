/**
 * @file Expedia_Manager.cpp
 * @brief Implements the core system manager for Expedia
 * @details Handles:
 *          - Singleton instance management
 *          - User navigation flow
 *          - Coordination between system components
 *          - Itinerary creation and payment processing
 *
 * @author Abdallah Salem
 */
#include "../include/Expedia_Manager.hpp"

Manager::Manager() :
		User_Manager(std::make_unique<UserManager>()), Payment_Handler(
				std::make_unique<PaymentHandler>()), Itinerary_Builder(
				std::make_unique<ItineraryBuilder>()) {
}

void Manager::firtOptions() {
	std::cout << "1- Sign Up.\n2- Sign In.\n3- Exit.";
}

void Manager::secondOptions() {
	std::cout
			<< "1- View Profile.\n2- Make Itinerary.\n3- List My Itineraries.\n4- Logout.\n";
}

void Manager::thirdOptions() {
	std::cout << "1- Add Flight.\n2- Add Hotel.\n3- Save.\n4- Cancel.\n";
}

void Manager::save() {
	if (Itinerary_Builder->checkItinerary()) { //make sure that there is an itinerary.
		std::cout << "Empty Itinerary.\n";
		return;
	}
	if (!Payment_Handler->setTransactionInfo())    //be sure that info is set.
		return;
	if (!Payment_Handler->makeThePayment())     //be sure that payment is made.
		return;
	User_Manager->addItineraryToUser(Itinerary_Builder->getItinerary());
	Itinerary_Builder->clearItinerary();
}

void Manager::addItinerary(std::string input) {
	while (true) {
		Manager::thirdOptions();
		std::cin >> input;
		if (input == "1")
			Itinerary_Builder->addFlight();
		else if (input == "2")
			Itinerary_Builder->addHotel();
		else if (input == "3") {
			Manager::save();
			return;
		} else if (input == "4") {
			Itinerary_Builder->clearItinerary();    //call it off
			return;
		}
	}
}

Manager_shared_ptr Manager::getInstance() {
	if (!OnlyOneInstance)
		OnlyOneInstance = std::make_shared<Manager>();   //only one instance.
	return OnlyOneInstance;
}

void Manager::runManager() {
	std::string input;
	//program logic
	while (true) {
		Manager::firtOptions();
		std::cin >> input;
		if (input == "1")
			User_Manager->signUpUser();
		else if (input == "2")
			User_Manager->signInUser();
		else if (input == "3")
			return;
		while (User_Manager->checkLoggedUser()) {
			Manager::secondOptions();
			std::cin >> input;
			if (input == "1")
				User_Manager->viewUserProfile();
			else if (input == "2")
				Manager::addItinerary(input);
			else if (input == "3")
				User_Manager->viewUserItineraries();
			else if (input == "4") {
				User_Manager->logoutUser();
				Itinerary_Builder->clearItinerary();
			}
		}
	}
}

void Manager::startSystem() {
	Manager_shared_ptr Manager = Manager::getInstance();
	Manager->runManager();   //run the program
}

