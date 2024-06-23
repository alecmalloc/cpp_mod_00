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
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
	<< ";amount:" << _amount
	<< ";closed" << std::endl;
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

void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << _accountIndex 
  	<< "amount:" << _amount
	<< ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm *ptm = std::localtime(&now);
	char formattedTime[21]; // Increased size to hold "[%Y%m%d_%H%M%S]\0"
	std::strftime(formattedTime, sizeof(formattedTime), "[%Y%m%d_%H%M%S] ", ptm);
	std::cout << formattedTime;
}

void Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";p_amount:" << p_amount
	<< ";deposit:" << deposit 
	<< ";amount:" << _amount
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex 
	<< ";p_amount" << p_amount;
	if ((_amount - withdrawal) < 0) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal
	<< ";amount:" << _amount
	<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int main(void)
{
	Account aAccount(200);
	Account bAccount(100);
	aAccount.displayAccountsInfos();
	aAccount.displayStatus();
	bAccount.displayStatus();
	aAccount.makeDeposit(2);
	aAccount.displayAccountsInfos();
	bAccount.makeWithdrawal(2);
	bAccount.~Account();
	return 0;
}