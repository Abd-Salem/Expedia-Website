/**
 * @file Payment_Methods.hpp
 * @brief Implements payment method adapters
 * @details Concrete implementations:
 *          - PaypalPayment: PayPal API adapter
 *          - StripePayment: Stripe API adapter
 *          - SquarePayment: Square API adapter
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_PAYMENT_METHODS_HPP_
#define HEADERS_PAYMENT_METHODS_HPP_

#include "Payment_APIs.hpp"
#include "Payment.hpp"
#include "json.hpp"

/**
 * @class PaypalPayment
 * @brief Implementation of the IPayment interface for PayPal payment processing.
 * @details Provides methods to set user and card information and process payments using the PayPal API.
 */
class PaypalPayment: public IPayment {
private:
	/// Smart pointer to the PayPal online payment API.
	PayPalOnlinePaymentAPI_ptr paypal;
	/// Smart pointer to the PayPal credit card information.
	PayPalCreditCard_ptr info;

public:
	/**
	 * @brief Default constructor for PaypalPayment.
	 */
	PaypalPayment();
	/**
	 * @brief Move assignment operator for PaypalPayment.
	 * @param other Another PaypalPayment object to move from.
	 * @return Reference to this PaypalPayment object.
	 */
	PaypalPayment& operator=(PaypalPayment &&other);

	/**
	 * @brief Copy assignment operator for PaypalPayment.
	 * @param other Another PaypalPayment object to copy from.
	 * @return Reference to this PaypalPayment object.
	 */
	PaypalPayment& operator=(const PaypalPayment &other);

	/**
	 * @brief Sets user information for the PayPal payment.
	 * @param trans_info Smart pointer to TransactionInfo containing user details.
	 */
	void setUserInfo(const TransactionInfo_ptr &trans_info) override;

	/**
	 * @brief Sets card information for the PayPal payment.
	 * @param trans_info Smart pointer to TransactionInfo containing card details.
	 */
	void setCardInfo(const TransactionInfo_ptr &trans_info) override;

	/**
	 * @brief Processes a payment through PayPal.
	 * @param money The amount to be paid.
	 * @return True if the payment is successful, false otherwise.
	 */
	bool makePayment(double money) override;
};

/**
 * @class StripePayment
 * @brief Implementation of the IPayment interface for Stripe payment processing.
 * @details Provides methods to set user and card information and process payments using the Stripe API.
 */
class StripePayment: public IPayment {
private:
	/// Smart pointer to the Stripe user information.
	StripeUserInfo_ptr user;
	/// Smart pointer to the Stripe card information.
	StripeCardInfo_ptr card;

public:
	/**
	 * @brief Default constructor for StripePayment.
	 */
	StripePayment();

	/**
	 * @brief Copy assignment operator for StripePayment.
	 * @param other Another StripePayment object to copy from.
	 * @return Reference to this StripePayment object.
	 */
	StripePayment& operator=(const StripePayment &other);

	/**
	 * @brief Move assignment operator for StripePayment.
	 * @param other Another StripePayment object to move from.
	 * @return Reference to this StripePayment object.
	 */
	StripePayment& operator=(StripePayment &&other);

	/**
	 * @brief Sets user information for the Stripe payment.
	 * @param trans_info Smart pointer to TransactionInfo containing user details.
	 */
	void setUserInfo(const TransactionInfo_ptr &trans_info) override;

	/**
	 * @brief Sets card information for the Stripe payment.
	 * @param trans_info Smart pointer to TransactionInfo containing card details.
	 */
	void setCardInfo(const TransactionInfo_ptr &trans_info) override;

	/**
	 * @brief Processes a payment through Stripe.
	 * @param money The amount to be paid.
	 * @return True if the payment is successful, false otherwise.
	 */
	bool makePayment(double money) override;
};

/**
 * @class SquarePayment
 * @brief Implementation of the IPayment interface for Square payment processing.
 * @details Provides methods to set user and card information and process payments using a JSON query for the Square API.
 */
class SquarePayment: public IPayment {
private:
	/// JSON object containing payment query details for Square.
	json::JSON query;

public:
	/**
	 * @brief Default constructor for SquarePayment.
	 */
	SquarePayment() = default;

	/**
	 * @brief Sets user information for the Square payment.
	 * @param trans_info Smart pointer to TransactionInfo containing user details.
	 */
	void setUserInfo(const TransactionInfo_ptr &trans_info) override;

	/**
	 * @brief Sets card information for the Square payment.
	 * @param trans_info Smart pointer to TransactionInfo containing card details.
	 */
	void setCardInfo(const TransactionInfo_ptr &trans_info) override;

	/**
	 * @brief Processes a payment through Square.
	 * @param money The amount to be paid.
	 * @return True if the payment is successful, false otherwise.
	 */
	bool makePayment(double money) override;
};

#endif /* HEADERS_PAYMENT_METHODS_HPP_ */
