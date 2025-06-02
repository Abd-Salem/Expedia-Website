/**
 * @file Make_payment.hpp
 * @brief Payment processing interface and factory
 * @details Provides:
 *          - PaymentFactory: Creates payment method instances
 *          - MakePayment: Handles payment execution
 *
 * @author Abdallah Salem
 */

#ifndef HEADERS_MAKE_PAYMENT_HPP_
#define HEADERS_MAKE_PAYMENT_HPP_

#include "Payment_Methods.hpp"

/**
 * @class PaymentFactory
 * @brief Factory class for creating payment method instances.
 * @details Provides a static method to create payment method objects based on the specified method.
 */
class PaymentFactory {
public:
	/**
	 * @brief Creates a payment method instance based on the specified method.
	 * @param method The name of the payment method (e.g., "credit_card", "paypal").
	 * @return A smart pointer to an IPayment object representing the payment method.
	 */
	static IPayment_ptr getPaymentMethod(const std::string &method);
};

/**
 * @class MakePayment
 * @brief Class for processing payments using a specified payment method.
 * @details Manages the payment process by selecting a payment method and executing transactions.
 */
class MakePayment {
private:
	/// Smart pointer to the selected payment method.
	IPayment_ptr payment;

	/**
	 * @brief Sets the payment method to be used for transactions.
	 * @param method The name of the payment method (e.g., "credit_card", "paypal").
	 */
	void setMethod(const std::string &method);

public:
	/**
	 * @brief Default constructor for MakePayment.
	 */
	MakePayment();

	/**
	 * @brief Processes a payment transaction.
	 * @param info Smart pointer to TransactionInfo containing payment details.
	 * @return True if the payment is successful, false otherwise.
	 */
	bool pay(const TransactionInfo_ptr &info);
};

/**
 * @typedef MakePayment_ptr
 * @brief Smart pointer to a MakePayment object.
 */
typedef std::unique_ptr<MakePayment> MakePayment_ptr;

#endif /* HEADERS_MAKE_PAYMENT_HPP_ */
