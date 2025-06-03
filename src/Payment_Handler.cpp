/**
 * @file Payment_Handler.cpp
 * @brief Implements payment transaction management
 * @details Handles:
 *          - Payment method selection
 *          - Transaction information collection
 *          - Payment execution
 *
 * @author Abdallah Salem
 */
#include"../include/Payment_Handler.hpp"

PaymentHandler::PaymentHandler() :
		Trans_Info(std::make_unique<TransactionInfo>()), Pay(
				std::make_unique<MakePayment>()) {

}

bool PaymentHandler::setTransactionInfo() {
	//collect transaction data
	std::string input;
	std::cout
			<< "\nChoose your payment method: (to cancel Enter e/E) \n1- PayPal\n2- Stripe\n3- Square\n";
	std::cin >> input;
	if (input == "e" || input == "E")
		return false;
	else if (input == "1")
		Trans_Info->method = "paypal";
	else if (input == "2")
		Trans_Info->method = "stripe";
	else if (input == "3")
		Trans_Info->method = "square";
	std::cout << "\nEnter your name on card: (to cancel Enter e/E) ";
	std::cin >> input;
	if (input == "e" || input == "E")
		return false;
	Trans_Info->name = input;
	std::cout << "\nEnter your address: (to cancel Enter e/E) ";
	std::cin >> input;
	if (input == "e" || input == "E")
		return false;
	Trans_Info->address = input;
	std::cout << "\nEnter your card ID number: (to cancel Enter e/E) ";
	std::cin >> input;
	if (input == "e" || input == "E")
		return false;
	Trans_Info->id = input;
	std::cout << "\nEnter your card expire date: (to cancel Enter e/E) ";
	std::cin >> input;
	if (input == "e" || input == "E")
		return false;
	Trans_Info->expire_date = input;
	std::cout << "\nEnter your ccv: (to cancel Enter e/E) ";
	std::cin >> input;
	if (input == "e" || input == "E")
		return false;
	Trans_Info->ccv = std::stoi(input);
	return true;
}

bool PaymentHandler::makeThePayment() {
	//call API to make the Payment.
	return Pay->pay(Trans_Info);
}

