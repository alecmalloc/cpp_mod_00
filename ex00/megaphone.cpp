#include <iostream>

char *str_up(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

int main(int ac, char **av) {
	if (ac == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" \
		<< std::endl, 0);
	for(int i = 1; i < ac; i++)
		std::cout << str_up(av[i]) << ' ';
	std::cout << std::endl;
	return 0;
}