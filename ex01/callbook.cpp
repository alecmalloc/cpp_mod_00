#include "callbook.hpp"
#include <iomanip>

#include <iomanip> // Include the <iomanip> library for std::setw

void	display_header(void)
{
	std::cout << std::setw(10) << std::right << "index";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "first name"; // Increase the width to accommodate longer names
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "last name"; // Increase the width to accommodate longer names
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "nickname"; // Increase the width to accommodate longer nicknames
	std::cout << std::endl;
}

void	display_entries(PhoneBook &Pb)
{
	for (int i = 0; !Pb.contacts[i].first_name.empty(); i++)
	{
		std::cout << std::setw(10) << std::right << i;
		std::cout << "|";
		std::cout << std::setw(10) << std::right << Pb.contacts[i].first_name;
		std::cout << "|";
		std::cout << std::setw(10) << std::right << Pb.contacts[i].last_name;
		std::cout << "|";
		std::cout << std::setw(10) << std::right << Pb.contacts[i].nick_name;
		std::cout << std::endl;
	}
}

void	book_search(PhoneBook &Pb)
{
	display_header();
	display_entries(Pb);
	return ;
}

void	bop_and_shift_up(PhoneBook &Pb)
{
	for (int i = 0; i < 7; i++)
		Pb.contacts[i] = Pb.contacts[i + 1];
}

int		index_selector(PhoneBook &Pb)
{
	for (int i = 0; i < 8; i++)
	{
		if (Pb.contacts[i].first_name.empty())
			return (i);
	}
	bop_and_shift_up(Pb);
	return (7);
}
void	book_add(PhoneBook &Pb)
{
	int i =	index_selector(Pb);
	std::cout << "working on: " << i << std::endl;
	std::string buffer;

	std::cout << "first name:" << std::endl;
	std::getline(std::cin, Pb.contacts[i].first_name);
	std::cout << "last name:" << std::endl;
	std::getline(std::cin, Pb.contacts[i].last_name);
	std::cout << "nickname:" << std::endl;
	std::getline(std::cin, Pb.contacts[i].nick_name);
	std::cout << "phone number:" << std::endl;
	std::getline(std::cin, Pb.contacts[i].phone_number);
	std::cout << "darkest secret:" << std::endl;
	std::getline(std::cin, Pb.contacts[i].darkest_secret);
}

int main()
{
	PhoneBook	Pb;
	std::string buffer;
	while (1)
	{
		std::cout << "Alec's PhoneBook: ";
		std::getline(std::cin, buffer);
		if (buffer == "EXIT")
			return (1);
		if (buffer == "SEARCH")
			book_search(Pb);
		if (buffer == "ADD")
			book_add(Pb);
	}
}