#include <iostream>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (int i = 1; i < ac; i++) {
			for (int j = 0; av[i][j]; j++) {
				std::cout << static_cast<char>(toupper(av[i][j]));
			}
		}
		std::cout << std::endl;
	}
}
