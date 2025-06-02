/**
 * @file Expedia_Manager.hpp
 * @brief Central system manager for Expedia travel booking system
 * @details Implements:
 *          - Singleton pattern for system management
 *          - User flow control (signup/login/reservations)
 *          - Coordination between UserManager, PaymentHandler and ItineraryBuilder
 * @author Abdallah Salem
 */

#ifndef HEADERS_EXPEDIA_MANAGER_HPP_
#define HEADERS_EXPEDIA_MANAGER_HPP_

#include "User_Manager.hpp"
#include "Itinerary_Builder.hpp"
#include "Payment_Handler.hpp"

/**
 * @class Manager
 * @brief Manages the overall flow of the travel booking system.
 *
 * Acts as a singleton class that coordinates user interactions, itinerary creation,
 * and payment transactions.
 */
class Manager {
private:
	UserManager_ptr User_Manager;     ///< Pointer to the user manager instance.
	PaymentHandler_ptr Payment_Handler; ///< Pointer to the payment handler instance.
	ItineraryBuilder_ptr Itinerary_Builder; ///< Pointer to the itinerary builder instance.

	inline static std::shared_ptr<Manager> OnlyOneInstance; ///< Singleton instance.

	/**
	 * @brief Displays the initial set of user options (e.g., sign up, sign in).
	 */
	void firtOptions(); // Note: Typo in original code ("firt" instead of "first").

	/**
	 * @brief Displays options available to a logged-in user.
	 */
	void secondOptions();

	/**
	 * @brief Displays options for building an itinerary.
	 */
	void thirdOptions();

	/**
	 * @brief Adds an itinerary based on user input.
	 * @param input User input specifying the action to take.
	 */
	void addItinerary(std::string input);

	/**
	 * @brief Saves the current itinerary after payment processing.
	 */
	void save();

	/**
	 * @brief Retrieves or creates the singleton instance of Manager.
	 * @return Shared pointer to the Manager instance.
	 */
	static std::shared_ptr<Manager> getInstance();

	/**
	 * @brief Runs the main loop of the manager.
	 */
	void runManager();

public:
	/**
	 * @brief Default constructor.
	 */
	Manager();

	/**
	 * @brief Starts the system by initializing and running the manager.
	 */
	static void startSystem();
};

/**
 * @typedef Manager_shared_ptr
 * @brief Type definition for a shared pointer to Manager.
 */
typedef std::shared_ptr<Manager> Manager_shared_ptr;

#endif /* HEADERS_EXPEDIA_MANAGER_HPP_ */
