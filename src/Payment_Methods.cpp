/**
 * @file Payment_Methods.cpp
 * @brief Implements payment method adapters
 * @details Contains concrete payment processing classes:
 *          - PaypalPayment: PayPal API integration
 *          - StripePayment: Stripe API integration
 *          - SquarePayment: Square API integration
 *
 * @author Abdallah Salem
 */
#include"../include/payment_methods.hpp"
#include"../include/json.hpp"
#include<sstream>

PaypalPayment::PaypalPayment() :
		paypal(std::make_unique<PayPalOnlinePaymentAPI>()), info(
				std::make_unique<PayPalCreditCard>()) {

}

PaypalPayment& PaypalPayment::operator=(const PaypalPayment &other) {
	if (this != &other) {
		*paypal = *other.paypal;
		*info = *other.info;
	}
	return *this;
}

PaypalPayment& PaypalPayment::operator=(PaypalPayment &&other) {
	if (this != &other) {
		paypal = std::move(other.paypal);
		info = std::move(other.info);
	}
	return *this;
}

void PaypalPayment::setUserInfo(const TransactionInfo_ptr &trans_info) {
	info->name = trans_info->name;
	info->address = trans_info->address;
}

void PaypalPayment::setCardInfo(const TransactionInfo_ptr &trans_info) {
	info->id = trans_info->id;
	info->expire_date = trans_info->expire_date;
	info->ccv = trans_info->ccv;
}

bool PaypalPayment::makePayment(double money) {
	paypal->setCardInfo(info);
	paypal->setUserInfo(info);
	if (paypal->makePayment(money)) {
		std::cout << "Your Payment is successfully made.\n";
		return true;
	}
	std::cout << "Payment is not made !!. (Try Again)\n";
	return false;
}

StripePayment::StripePayment() :
		user(std::make_unique<StripeUserInfo>()), card(
				std::make_unique<StripeCardInfo>()) {
}

StripePayment& StripePayment::operator=(const StripePayment &other) {
	if (this != &other) {
		*user = *other.user;
		*card = *other.card;
	}
	return *this;
}

StripePayment& StripePayment::operator=(StripePayment &&other) {
	if (this != &other) {
		user = std::move(other.user);
		card = std::move(other.card);
	}
	return *this;
}

void StripePayment::setUserInfo(const TransactionInfo_ptr &trans_info) {
	user->name = trans_info->name;
	user->address = trans_info->address;
}

void StripePayment::setCardInfo(const TransactionInfo_ptr &trans_info) {
	card->id = trans_info->id;
	card->expire_date = trans_info->expire_date;
	card->ccv = trans_info->ccv;
}

bool StripePayment::makePayment(double money) {
	if (StripePaymentAPI::WithDrawMoney(user, card, money)) {
		std::cout << "Your Payment is successfully made.\n";
		return true;
	}
	std::cout << "Payment is not made !!. (Try Again)\n";
	return false;
}

void SquarePayment::setUserInfo(const TransactionInfo_ptr &trans_info) {
	query["user_info"] = json::Array(trans_info->name, trans_info->address);
}

void SquarePayment::setCardInfo(const TransactionInfo_ptr &trans_info) {
	query["card_info"] = json::Object();
	query["card_info"]["id"] = trans_info->id;
	query["card_info"]["ccv"] = trans_info->ccv;
	query["card_info"]["expire_date"] = trans_info->expire_date;
}

bool SquarePayment::makePayment(double money) {
	query["Payment_money"] = json::Array(money);
	std::ostringstream str_query;
	str_query << query;
	if (SquarePaymentAPI::WithDrawMoney(str_query.str())) {
		std::cout << "Your Payment is successfully made.\n";
		return true;
	}
	std::cout << "Payment is not made !!. (Try Again)\n";
	return false;
}

