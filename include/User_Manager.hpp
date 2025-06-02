/**
 * @file User_Manager.hpp
 * @brief User account management system
 * @details Handles:
 *          - User registration and authentication
 *          - Profile management
 *          - Itinerary storage and retrieval
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_USER_MANAGER_HPP_
#define HEADERS_USER_MANAGER_HPP_

#include "User.hpp"

/**
 * @class UserManager
 * @brief Class for managing user accounts and their associated itineraries.
 * @details Handles user registration, authentication, profile management, and itinerary operations.
 * @note Copy and move operations are explicitly deleted to prevent unintended copying or moving of the UserManager.
 */
class UserManager {
private:
	/// Shared pointer to the currently logged-in user.
	User_Shared_ptr logged_user;
	/// Vector of shared pointers to all registered users.
	std::vector<User_Shared_ptr> Users;

public:
	/**
	 * @brief Default constructor for UserManager.
	 */
	UserManager();

	/**
	 * @brief Copy constructor (deleted).
	 * @param other Another UserManager object.
	 */
	UserManager(const UserManager &other) = delete;

	/**
	 * @brief Move constructor (deleted).
	 * @param other Another UserManager object.
	 */
	UserManager(UserManager &&other) = delete;

	/**
	 * @brief Copy assignment operator (deleted).
	 * @param other Another UserManager object.
	 * @return Reference to this UserManager object.
	 */
	UserManager& operator=(const UserManager &other) = delete;

	/**
	 * @brief Move assignment operator (deleted).
	 * @param other Another UserManager object.
	 * @return Reference to this UserManager object.
	 */
	UserManager& operator=(UserManager &&other) = delete;

	/**
	 * @brief Registers a new user in the system.
	 */
	void signUpUser();

	/**
	 * @brief Authenticates a user and logs them in.
	 */
	void signInUser();

	/**
	 * @brief Logs out the currently logged-in user.
	 */
	void logoutUser();

	/**
	 * @brief Checks the currently logged-in user.
	 * @return Shared pointer to the logged-in User object, or null if no user is logged in.
	 */
	User_Shared_ptr checkLoggedUser();

	/**
	 * @brief Checks if a username already exists in the system.
	 * @param _username The username to check.
	 * @return True if the username exists, false otherwise.
	 */
	bool checkUsernameExistence(const std::string &&_username) const;

	/**
	 * @brief Checks if an email already exists in the system.
	 * @param _email The email to check.
	 * @return True if the email exists, false otherwise.
	 */
	bool checkUserEmailExistence(const std::string &&_email) const;

	/**
	 * @brief Displays the profile of the currently logged-in user.
	 */
	void viewUserProfile() const;

	/**
	 * @brief Displays the itineraries of the currently logged-in user.
	 */
	void viewUserItineraries() const;

	/**
	 * @brief Adds an itinerary to the currently logged-in user's list.
	 * @param it Smart pointer to the Itinerary object to add.
	 */
	void addItineraryToUser(const Itinerary_ptr &it);

	/**
	 * @brief Removes an itinerary from the currently logged-in user's list.
	 * @param it Smart pointer to the Itinerary object to remove.
	 */
	void removeItineraryFromUser(Itinerary_ptr &it);
};

/**
 * @typedef UserManager_ptr
 * @brief Smart pointer to a UserManager object.
 */
typedef std::unique_ptr<UserManager> UserManager_ptr;

#endif /* HEADERS_USER_MANAGER_HPP_ */
