#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cout
		<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
		<< std::endl;
	} else {
		for (int i = 1; i < ac; i++) {
			for (int j = 0; av[i][j]; j++)
				av[i][j] = (char)toupper(av[i][j]);
			std::cout
			<< av[i];
			if (av[i])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
