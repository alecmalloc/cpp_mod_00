#include "callbook.h"

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
void	book_add(PhoneBook Pb)
{
	int i = index_selector(Pb);
	std::cout << "first name: ";
	std::cin >> Pb.contacts[i].first_name;
	std::cout << std::endl;
}

int main()
{
	PhoneBook Pb;
	while (1)
	{
		std::string buffer;
		std::cout << "Alec's PhoneBook: ";
		std::cin >> buffer;
		if (buffer == "EXIT")
			return (1);
		if (buffer == "SEARCH")
			book_search();
		if (buffer == "ADD")
			book_add(Pb);
		std::cout << std::endl;
	}
}