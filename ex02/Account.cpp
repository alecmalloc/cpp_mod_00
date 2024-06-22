#include "Account.hpp"
#include <ostream>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// constructor destructor
Account::Account(int initial_deposit): 
_accountIndex(_nbAccounts++),
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << (Account::_nbAccounts - 1)
    << ";amount:" << Account::_amount
    << ";created" << std::endl;
	Account::_totalAmount += _amount;
}

Account::~Account(void) {
}

// member functions
int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts
    << ";total:" << Account::_totalAmount
    << ";deposits:" << Account::_totalNbDeposits
    << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm *ptm = std::localtime(&now);
	char formattedTime[21]; // Increased size to hold "[%Y%m%d_%H%M%S]\0"
	std::strftime(formattedTime, sizeof(formattedTime), "[%Y%m%d_%H%M%S] ", ptm);
	std::cout << formattedTime;
}

int main(void)
{
	Account aAccount(200);
	Account bAccount(100);
	Account::displayAccountsInfos();
	return 0;
}