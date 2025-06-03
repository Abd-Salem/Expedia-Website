/**
 * @file Payment.hpp
 * @brief Payment processing interface
 * @details Declares:
 *          - IPayment: Interface for payment operations
 *          - Smart pointer type definition
 *
 * @author Abdallah Salem
 */

#ifndef HEADERS_PAYMENT_INTERFACE_HPP_
#define HEADERS_PAYMENT_INTERFACE_HPP_

#include <iostream>
#include <memory>
#include "Transactions.hpp"

/**
 * @class IPayment
 * @brief Abstract base class for payment processing implementations.
 * @details Defines the interface for setting user and card information and processing payments.
 */
class IPayment {
public:
	/**
	 * @brief Sets the user information for the payment.
	 * @param user_info Smart pointer to TransactionInfo containing user details.
	 */
	virtual void setUserInfo(const TransactionInfo_ptr &user_info) = 0;

	/**
	 * @brief Sets the card information for the payment.
	 * @param card_info Smart pointer to TransactionInfo containing card details.
	 */
	virtual void setCardInfo(const TransactionInfo_ptr &card_info) = 0;

	/**
	 * @brief Processes a payment for the specified amount.
	 * @param money The amount to be paid.
	 * @return True if the payment is successful, false otherwise.
	 */
	virtual bool makePayment(double money) = 0;

	/**
	 * @brief Virtual destructor for IPayment.
	 * @details Ensures proper cleanup of derived classes.
	 */
	virtual ~IPayment() = default;
};

/**
 * @typedef IPayment_ptr
 * @brief Smart pointer to an IPayment object.
 */
typedef std::unique_ptr<IPayment> IPayment_ptr;

#endif /* HEADERS_PAYMENT_INTERFACE_HPP_ */
