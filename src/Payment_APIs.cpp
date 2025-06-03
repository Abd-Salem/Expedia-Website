/**
 * @file Payment_APIs.cpp
 * @brief Implements third-party payment service integrations
 * @details Concrete implementations for:
 *          - PayPal payment processing
 *          - Stripe payment processing
 *          - Square payment processing
 *
 * @author Abdallah Salem
 */

#include"../include/payment_APIs.hpp"
#include"../include/json.hpp"

void PayPalOnlinePaymentAPI::setCardInfo(PayPalCreditCard_ptr &user) {
	//data is sent to API and API set it.
}

void PayPalOnlinePaymentAPI::setUserInfo(PayPalCreditCard_ptr &user) {
	//data is sent to API and API set it.

}

bool PayPalOnlinePaymentAPI::makePayment(double money) {
	//suppose the process is successfully done.
	return true;
}

bool StripePaymentAPI::WithDrawMoney(StripeUserInfo_ptr &user,
		StripeCardInfo_ptr &card, double money) {
	//suppose the process is successfully done.
	return true;
}

bool SquarePaymentAPI::WithDrawMoney(std::string jsonQuery) {
	//suppose withdraw is successfully done.
	json::JSON query = json::JSON::Load(jsonQuery);
	return true;
}
