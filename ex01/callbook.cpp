#include "callbook.hpp"

void	display_header(void)
{
	std::cout << std::setw(10) << std::right << "index";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "first name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "last name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "nickname";
	std::cout << std::endl;
}

void 	display_contact(PhoneBook &Pb, unsigned short index)
{
	// no need to check lower bounds because using unsigned short
	if (index > 7)
	{
		std::cout << "index out of bounds..." << std::endl;
		return ;
	}
	std::cout << "first name: " << Pb.contacts[index].first_name << std::endl;
	std::cout << "last name: " << Pb.contacts[index].last_name << std::endl;
	std::cout << "nickname: " << Pb.contacts[index].nick_name << std::endl;
	std::cout << "phone number: " << Pb.contacts[index].phone_number << std::endl;
	std::cout << "darkest secret " << Pb.contacts[index].darkest_secret << std::endl;
}

unsigned short	get_contacts_length(PhoneBook &Pb)
{
	for (int i = 0; i < 8; i++)
	{
		if (Pb.contacts[i].first_name.empty())
			return (i);
	}
	return (8);
}

void	display_entries(PhoneBook &Pb)
{
	unsigned short index;
	std::string buffer;

	unsigned short length = get_contacts_length(Pb);
	for (int i = 0; i < length; i++)
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
	std::cout << "show index: ";
	std::getline(std::cin, buffer);
	std::stringstream ss(buffer);
	ss >> index;
	display_contact(Pb, index);
}

void	book_search(PhoneBook &Pb)
{
	display_header();
	if (!Pb.contacts[0].first_name.empty())
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

void	str_shorten(std::string &str)
{
	if (str.length() < 10)
		return ;
	std::string trim;
	trim = str.substr(0, 10);
	trim.replace(9, 1, ".");
	str = trim;
}

void	book_add(PhoneBook &Pb)
{
	int i =	index_selector(Pb);
	std::string buffer;

	std::cout << "first name: ";
	std::getline(std::cin, Pb.contacts[i].first_name);
	str_shorten(Pb.contacts[i].first_name);
	std::cout << "last name: ";
	std::getline(std::cin, Pb.contacts[i].last_name);
	str_shorten(Pb.contacts[i].last_name);
	std::cout << "nickname: ";
	std::getline(std::cin, Pb.contacts[i].nick_name);
	str_shorten(Pb.contacts[i].nick_name);
	std::cout << "phone number: ";
	std::getline(std::cin, Pb.contacts[i].phone_number);
	std::cout << "darkest secret: ";
	std::getline(std::cin, Pb.contacts[i].darkest_secret);
	std::cout << std::endl;
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