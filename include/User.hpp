/**
 * @file User.hpp
 * @brief User entity representation
 * @details Models:
 *          - User credentials and profile information
 *          - Collection of user itineraries
 *          - Itinerary management operations
 * @author Abdallah Salem
 * @date Created: Apr 15, 2025
 */

#ifndef HEADERS_USER_HPP_
#define HEADERS_USER_HPP_

#include <iostream>
#include <memory>
#include <algorithm>
#include "Itinerary.hpp"

/**
 * @class User
 * @brief Class representing a user account with associated itineraries.
 * @details Manages user information such as username, password, email, and a collection of itineraries.
 */
class User {
private:
	/// User's username.
	std::string username;
	/// User's password.
	std::string password;
	/// User's email address.
	std::string email;
	/// Vector of smart pointers to the user's itineraries.
	std::vector<Itinerary_ptr> Itineraries;

	/**
	 * @brief Dynamically casts a Reservation to an Itinerary.
	 * @param reservation Smart pointer to a Reservation object to be cast.
	 * @return Smart pointer to an Itinerary object.
	 */
	Itinerary_ptr dynamicCast(Reservation_ptr &&reservation);

public:
	/**
	 * @brief Constructor for User.
	 * @param username The user's username.
	 * @param password The user's password.
	 * @param email The user's email address.
	 */
	User(std::string username, std::string password, std::string email);

	/**
	 * @brief Copy constructor for User.
	 * @param other Another User object to copy from.
	 */
	User(const User &other);

	/**
	 * @brief Move constructor for User.
	 * @param other Another User object to move from.
	 */
	User(User &&other);

	/**
	 * @brief Copy assignment operator for User.
	 * @param other Another User object to copy from.
	 * @return Reference to this User object.
	 */
	User& operator=(const User &other);

	/**
	 * @brief Move assignment operator for User.
	 * @param other Another User object to move from.
	 * @return Reference to this User object.
	 */
	User& operator=(User &&other);

	/**
	 * @brief Gets the user's username.
	 * @return Const reference to the username.
	 */
	const std::string& getUsername() const;

	/**
	 * @brief Gets the user's password.
	 * @return Const reference to the password.
	 */
	const std::string& getPassword() const;

	/**
	 * @brief Gets the user's email.
	 * @return Const reference to the email.
	 */
	const std::string& getEmail() const;

	/**
	 * @brief Displays the user's profile information.
	 */
	void viewMyProfile() const;

	/**
	 * @brief Displays the user's itineraries.
	 */
	void viewMyItineraries() const;

	/**
	 * @brief Adds an itinerary to the user's collection.
	 * @param it Smart pointer to the Itinerary object to add.
	 */
	void addItinerary(const Itinerary_ptr &it);

	/**
	 * @brief Removes an itinerary from the user's collection.
	 * @param it Smart pointer to the Itinerary object to remove.
	 */
	void removeItinerary(Itinerary_ptr &it);
};

/**
 * @typedef User_ptr
 * @brief Unique smart pointer to a User object.
 */
typedef std::unique_ptr<User> User_ptr;

/**
 * @typedef User_Shared_ptr
 * @brief Shared smart pointer to a User object.
 */
typedef std::shared_ptr<User> User_Shared_ptr;

#endif /* HEADERS_USER_HPP_ */
