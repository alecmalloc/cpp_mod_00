#include "Account.hpp"

Account::Account(int initial_deposit) : _amount(initial_deposit) {
}

int main(void)
{
	Account myAccount(500);
	myAccount.displayStatus();

	return 0;
}