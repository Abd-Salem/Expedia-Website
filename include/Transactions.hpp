/**
 * @file Transaction.hpp
 * @brief Defines payment transaction data structure
 * @details Contains:
 *          - TransactionInfo: Payment method details
 *          - Smart pointer type definition
 *
 * @author Abdallah Salem
 */

#ifndef HEADERS_TRANSACTION_INFO_HPP_
#define HEADERS_TRANSACTION_INFO_HPP_

#include <iostream>
#include <memory>

/**
 * @class TransactionInfo
 * @brief Class for storing payment transaction information.
 * @details Contains details such as payment method, user information, card details, and transaction amount.
 */
class TransactionInfo {
public:
	/// The payment method (e.g., "paypal", "stripe", "square").
	std::string method;
	/// The name of the cardholder or user.
	std::string name;
	/// The address of the cardholder or user.
	std::string address;
	/// The credit card number or identifier.
	std::string id;
	/// The credit card expiration date.
	std::string expire_date;
	/// The card verification value (CCV).
	int ccv { };
	/// The amount of money for the transaction.
	double money { };

	/**
	 * @brief Default constructor for TransactionInfo.
	 */
	TransactionInfo() = default;
};

/**
 * @typedef TransactionInfo_ptr
 * @brief Smart pointer to a TransactionInfo object.
 */
typedef std::unique_ptr<TransactionInfo> TransactionInfo_ptr;

#endif /* HEADERS_TRANSACTION_INFO_HPP_ */
