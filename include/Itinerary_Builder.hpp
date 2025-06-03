/**
 * @file Itinerary_Builder.hpp
 * @brief Itinerary composition and management
 * @details Provides:
 *          - Itinerary construction from flight/hotel reservations
 *          - Itinerary validation and clearing
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_ITINERARY_BUILDER_HPP_
#define HEADERS_ITINERARY_BUILDER_HPP_

#include "Make_Reservation.hpp"
#include "Itinerary.hpp"

/**
 * @class ItineraryBuilder
 * @brief Builds and manages a travel itinerary.
 *
 * Provides methods to add flights and hotels to an itinerary, check its state,
 * and retrieve the completed itinerary.
 */
class ItineraryBuilder {
private:
	Itinerary_ptr it;         ///< Pointer to the current itinerary being built.
	MakeReservation_ptr reserve; ///< Pointer to the reservation factory.

public:
	/**
	 * @brief Default constructor.
	 */
	ItineraryBuilder();

	/**
	 * @brief Deleted copy constructor to prevent copying.
	 */
	ItineraryBuilder(const ItineraryBuilder &other) = delete;

	/**
	 * @brief Deleted move constructor to prevent moving.
	 */
	ItineraryBuilder(ItineraryBuilder &&other) = delete;

	/**
	 * @brief Deleted copy assignment operator.
	 * @return Reference to the current object (not implemented).
	 */
	const ItineraryBuilder& operator=(const ItineraryBuilder &other) = delete;

	/**
	 * @brief Deleted move assignment operator.
	 * @return Reference to the current object (not implemented).
	 */
	const ItineraryBuilder& operator=(ItineraryBuilder &&other) = delete;

	/**
	 * @brief Adds a flight reservation to the itinerary.
	 */
	void addFlight();

	/**
	 * @brief Adds a hotel reservation to the itinerary.
	 */
	void addHotel();

	/**
	 * @brief Clears the current itinerary.
	 */
	void clearItinerary();

	/**
	 * @brief Checks if the itinerary is empty.
	 * @return True if the itinerary is empty, false otherwise.
	 */
	bool checkItinerary();

	/**
	 * @brief Retrieves the current itinerary.
	 * @return Constant reference to the itinerary pointer.
	 */
	const Itinerary_ptr& getItinerary();
};

/**
 * @typedef ItineraryBuilder_ptr
 * @brief Type definition for a unique pointer to ItineraryBuilder.
 */
typedef std::unique_ptr<ItineraryBuilder> ItineraryBuilder_ptr;

#endif /* HEADERS_ITINERARY_BUILDER_HPP_ */
