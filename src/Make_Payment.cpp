/**
 * @file Make_payment.cpp
 * @brief Implements payment processing operations
 * @details Contains:
 *          - Payment method factory implementation
 *          - Payment execution flow
 *          - Integration with payment APIs
 *
 * @author Abdallah Salem
 */
#include "../include/make_payment.hpp"

MakePayment::MakePayment() :
		payment(nullptr) {

}

IPayment_ptr PaymentFactory::getPaymentMethod(const std::string &method) {
	//set the method of paying
	if (method == "paypal")
		return std::make_unique<PaypalPayment>();
	else if (method == "stripe")
		return std::make_unique<StripePayment>();
	else if (method == "square")
		return std::make_unique<SquarePayment>();
	return nullptr;
}

void MakePayment::setMethod(const std::string &method) {
	payment = std::move(PaymentFactory::getPaymentMethod(method));
}

bool MakePayment::pay(const TransactionInfo_ptr &info) {
	//payment process
	MakePayment::setMethod(info->method);
	if (!payment)
		return false;
	payment->setCardInfo(info);
	payment->setUserInfo(info);
	return payment->makePayment(info->money);
}
