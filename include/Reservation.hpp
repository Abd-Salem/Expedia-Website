/**
 * @file Reservation.hpp
 * @brief Base interface for all reservation types
 * @details Combines:
 *          - Printable interface for output
 *          - Priced interface for cost calculation
 *          - Clone capability for polymorphic copying
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_RESERVATION_HPP_
#define HEADERS_RESERVATION_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Properties.hpp"

/**
 * @class Reservation
 * @brief Abstract base class for managing reservations.
 * @details Inherits from Priced and Printable to provide cost and output functionality for reservations.
 */
class Reservation: public Priced, public Printable {
public:
	/**
	 * @brief Creates a clone of the reservation.
	 * @return A smart pointer to a cloned Reservation object.
	 */
	virtual std::unique_ptr<Reservation> clone() const = 0;

	/**
	 * @brief Virtual destructor for Reservation.
	 * @details Ensures proper cleanup of derived classes.
	 */
	virtual ~Reservation() = default;
};

/**
 * @typedef Reservation_ptr
 * @brief Smart pointer to a Reservation object.
 */
typedef std::unique_ptr<Reservation> Reservation_ptr;

#endif /* HEADERS_RESERVATION_HPP_ */
