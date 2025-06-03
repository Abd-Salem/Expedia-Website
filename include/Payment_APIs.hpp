/**
 * @file Payment_APIs.hpp
 * @brief Defines third-party payment service interfaces
 * @details Interfaces for:
 *          - PayPal (PayPalOnlinePaymentAPI)
 *          - Stripe (StripePaymentAPI)
 *          - Square (SquarePaymentAPI)
 *
 * @author Abdallah Salem
 */
#ifndef HEADERS_PAYMENT_APIS_HPP_
#define HEADERS_PAYMENT_APIS_HPP_

#include <iostream>
#include <memory>

/**
 * @class PayPalCreditCard
 * @brief Stores credit card and user information for PayPal payments.
 */
class PayPalCreditCard {
public:
	/// Cardholder's name.
	std::string name;
	/// Cardholder's address.
	std::string address;
	/// Credit card number or identifier.
	std::string id;
	/// Credit card expiration date.
	std::string expire_date;
	/// Card verification value (CCV).
	int ccv;
};

/**
 * @class PayPalOnlinePaymentAPI
 * @brief Interface for processing payments via PayPal.
 */
class PayPalOnlinePaymentAPI {
public:
	/**
	 * @brief Sets the credit card information for the PayPal payment.
	 * @param card Smart pointer to a PayPalCreditCard object containing card details.
	 */
	void setCardInfo(std::unique_ptr<PayPalCreditCard> &card);

	/**
	 * @brief Sets the user information for the PayPal payment.
	 * @param user Smart pointer to a PayPalCreditCard object containing user details.
	 */
	void setUserInfo(std::unique_ptr<PayPalCreditCard> &user);

	/**
	 * @brief Processes a payment through PayPal.
	 * @param money The amount to be paid.
	 * @return True if the payment is successful, false otherwise.
	 */
	bool makePayment(double money);
};

/**
 * @class StripeUserInfo
 * @brief Stores user information for Stripe payments.
 */
class StripeUserInfo {
public:
	/// User's name.
	std::string name;
	/// User's address.
	std::string address;
};

/**
 * @class StripeCardInfo
 * @brief Stores credit card information for Stripe payments.
 */
class StripeCardInfo {
public:
	/// Credit card number or identifier.
	std::string id;
	/// Credit card expiration date.
	std::string expire_date;
	/// Card verification value (CCV).
	int ccv { };

	/**
	 * @brief Default constructor for StripeCardInfo.
	 */
	StripeCardInfo() = default;
};

/**
 * @class StripePaymentAPI
 * @brief Interface for processing payments via Stripe.
 */
class StripePaymentAPI {
public:
	/**
	 * @brief Processes a payment through Stripe.
	 * @param user Smart pointer to a StripeUserInfo object containing user details.
	 * @param card Smart pointer to a StripeCardInfo object containing card details.
	 * @param money The amount to be paid.
	 * @return True if the payment is successful, false otherwise.
	 */
	static bool WithDrawMoney(std::unique_ptr<StripeUserInfo> &user,
			std::unique_ptr<StripeCardInfo> &card, double money);
};

/**
 * @class SquarePaymentAPI
 * @brief Interface for processing payments via Square.
 */
class SquarePaymentAPI {
public:
	/**
	 * @brief Processes a payment through Square using a JSON query.
	 * @param jsonQuery A JSON string containing payment details.
	 * @return True if the payment is successful, false otherwise.
	 */
	static bool WithDrawMoney(std::string jsonQuery);
};

/**
 * @typedef PayPalOnlinePaymentAPI_ptr
 * @brief Smart pointer to a PayPalOnlinePaymentAPI object.
 */
typedef std::unique_ptr<PayPalOnlinePaymentAPI> PayPalOnlinePaymentAPI_ptr;

/**
 * @typedef StripePaymentAPI_ptr
 * @brief Smart pointer to a StripePaymentAPI object.
 * @note This typedef appears twice in the original code, which is redundant.
 */
typedef std::unique_ptr<StripePaymentAPI> StripePaymentAPI_ptr;

/**
 * @typedef PayPalCreditCard_ptr
 * @brief Smart pointer to a PayPalCreditCard object.
 */
typedef std::unique_ptr<PayPalCreditCard> PayPalCreditCard_ptr;

/**
 * @typedef StripeUserInfo_ptr
 * @brief Smart pointer to a StripeUserInfo object.
 */
typedef std::unique_ptr<StripeUserInfo> StripeUserInfo_ptr;

/**
 * @typedef StripeCardInfo_ptr
 * @brief Smart pointer to a StripeCardInfo object.
 */
typedef std::unique_ptr<StripeCardInfo> StripeCardInfo_ptr;

#endif /* HEADERS_PAYMENT_APIS_HPP_ */
