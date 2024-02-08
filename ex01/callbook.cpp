#include "callbook.h"
#include <limits>

void	book_search(void)
{
	return ;
}

int		index_selector(PhoneBook Pb)
{
	for (int i = 0; i < 8; i++)
	{
		if (Pb.contacts[i].first_name.empty())
			return (i);
	}
	return (0);
}
void	book_add(PhoneBook &Pb)
{
	int i =	index_selector(Pb);

	std::cout << "first name:" << std::endl;
	std::cin >> Pb.contacts[i].first_name;
	std::cout << "last name:" << std::endl;
	std::cin >> Pb.contacts[i].last_name;
	std::cout << "nickname:" << std::endl;
	std::cin >> Pb.contacts[i].nick_name;
	std::cout << "phone number:" << std::endl;
	std::cin >> Pb.contacts[i].phone_number;
	std::cout << "darkest secret:" << std::endl;
	std::cin >> Pb.contacts[i].darkest_secret;
}

int main()
{
	PhoneBook	Pb;
	std::string buffer;
	while (1)
	{
		std::cout << "Alec's PhoneBook: ";
		std::getline(std::cin, buffer);
		if (buffer.empty())
			return (1);
		if (buffer == "EXIT")
			return (1);
		if (buffer == "SEARCH")
			book_search();
		if (buffer == "ADD")
			book_add(Pb);
	}
}