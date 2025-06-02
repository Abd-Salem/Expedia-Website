/**
 * @file Itinerary.hpp
 * @brief Implements composite pattern for travel itineraries
 * @details Features:
 *          - Composite reservation container
 *          - Cost calculation for multi-reservation trips
 *          - Output formatting for itinerary details
 *
 * @author Abdallah Salem
 */

#ifndef HEADERS_ITINERARY_HPP_
#define HEADERS_ITINERARY_HPP_

#include <vector>
#include <sstream>
#include "Reservation.hpp"

/**
 * @class Itinerary
 * @brief Class for managing a collection of reservations as an itinerary.
 * @details Inherits from Reservation and stores a vector of Reservation_ptr objects, providing methods to manage and query the itinerary.
 */
class Itinerary: public Reservation {
private:
	/// Vector of smart pointers to Reservation objects.
	std::vector<Reservation_ptr> Reservations;

public:
	/**
	 * @brief Default constructor for Itinerary.
	 */
	Itinerary() = default;

	/**
	 * @brief Copy constructor for Itinerary.
	 * @param other Another Itinerary object to copy from.
	 */
	Itinerary(const Itinerary &other);

	/**
	 * @brief Move constructor for Itinerary.
	 * @param other Another Itinerary object to move from.
	 */
	Itinerary(Itinerary &&other);

	/**
	 * @brief Copy assignment operator for Itinerary.
	 * @param other Another Itinerary object to copy from.
	 * @return Reference to this Itinerary object.
	 */
	Itinerary& operator=(Itinerary &other);

	/**
	 * @brief Move assignment operator for Itinerary.
	 * @param other Another Itinerary object to move from.
	 * @return Reference to this Itinerary object.
	 */
	Itinerary& operator=(Itinerary &&other);

	/**
	 * @brief Adds a reservation to the itinerary.
	 * @param reservation Smart pointer to a Reservation object to add.
	 */
	void addReservation(const Reservation_ptr &reservation);

	/**
	 * @brief Clears all reservations from the itinerary.
	 */
	void clear();

	/**
	 * @brief Checks if the itinerary is empty.
	 * @return True if the itinerary has no reservations, false otherwise.
	 */
	bool isEmpty();

	/**
	 * @brief Outputs the details of the itinerary.
	 * @param get Output stream to write the itinerary details to.
	 */
	void getDetails(std::ostream &&get) const override;

	/**
	 * @brief Calculates the total cost of all reservations in the itinerary.
	 * @return The total cost as a double.
	 */
	double getCost() const;

	/**
	 * @brief Creates a clone of the itinerary.
	 * @return Smart pointer to a cloned Reservation object.
	 */
	Reservation_ptr clone() const override;

	/**
	 * @brief Destructor for Itinerary.
	 * @details Ensures proper cleanup of the itinerary and its reservations.
	 */
	~Itinerary();

	/**
	 * @brief Friend function to output the itinerary to an output stream.
	 * @param out Output stream to write to.
	 * @param it The Itinerary object to output.
	 * @return Reference to the output stream.
	 */
	friend std::ostream& operator<<(std::ostream &out, const Itinerary &it);
};

/**
 * @typedef Itinerary_ptr
 * @brief Smart pointer to an Itinerary object.
 */
typedef std::unique_ptr<Itinerary> Itinerary_ptr;

/**
 * @class Sum
 * @brief Functor for accumulating the total cost of reservations.
 * @tparam T The type used for summing costs (e.g., double).
 */
template<typename T>
struct Sum {
	/// Accumulated sum of reservation costs.
	T sum { };

	/**
	 * @brief Function call operator to add a reservation's cost to the sum.
	 * @param reservation Smart pointer to a Reservation object whose cost is added.
	 */
	void operator()(const Reservation_ptr &reservation) {
		sum += reservation->getCost();
	}
};

#endif /* HEADERS_ITINERARY_HPP_ */
