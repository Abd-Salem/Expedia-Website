/**
 * @file Payment_Handler.hpp
 * @brief Payment processing coordinator
 * @details Manages:
 *          - Transaction information collection
 *          - Payment execution flow
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_PAYMENT_HANDLER_HPP_
#define HEADERS_PAYMENT_HANDLER_HPP_

#include "Make_Payment.hpp"

/**
 * @class PaymentHandler
 * @brief Class for managing payment transactions.
 * @details Handles the setup and execution of payment transactions using a transaction info object and a payment processor.
 * @note Copy and move operations are explicitly deleted to prevent unintended copying or moving of the PaymentHandler.
 */
class PaymentHandler {
private:
	/// Smart pointer to transaction information.
	TransactionInfo_ptr Trans_Info;
	/// Smart pointer to the payment processor.
	MakePayment_ptr Pay;

public:
	/**
	 * @brief Default constructor for PaymentHandler.
	 */
	PaymentHandler();

	/**
	 * @brief Copy constructor (deleted).
	 * @param other Another PaymentHandler object.
	 */
	PaymentHandler(const PaymentHandler &other) = delete;

	/**
	 * @brief Move constructor (deleted).
	 * @param other Another PaymentHandler object.
	 */
	PaymentHandler(PaymentHandler &&other) = delete;

	/**
	 * @brief Copy assignment operator (deleted).
	 * @param other Another PaymentHandler object.
	 * @return Reference to this PaymentHandler object.
	 */
	PaymentHandler& operator=(const PaymentHandler &other) = delete;

	/**
	 * @brief Move assignment operator (deleted).
	 * @param other Another PaymentHandler object.
	 * @return Reference to this PaymentHandler object.
	 */
	PaymentHandler& operator=(PaymentHandler &&other) = delete;

	/**
	 * @brief Sets the transaction information for the payment.
	 * @return True if the transaction information is set successfully, false otherwise.
	 */
	bool setTransactionInfo();

	/**
	 * @brief Executes the payment transaction.
	 * @return True if the payment is successful, false otherwise.
	 */
	bool makeThePayment();
};

/**
 * @typedef PaymentHandler_ptr
 * @brief Smart pointer to a PaymentHandler object.
 */
typedef std::unique_ptr<PaymentHandler> PaymentHandler_ptr;

#endif /* HEADERS_PAYMENT_HANDLER_HPP_ */
