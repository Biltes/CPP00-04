/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:04:40 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 17:41:55 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int zombieNumber;
	std::string zombieName;
	
	while(true){
		std::cout << "Enter the number of Zombies: ";
		std::cin >> zombieNumber;
		if (std::cin.eof()) {
			std::cout << std::endl << "Exiting zombieHorde. Goodbye!" << std::endl;
			break;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Try 1 to 1050 range" << std::endl;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (zombieNumber <= 0 || zombieNumber > 1050) {
			std::cout << "Invalid number. Available 1 to 1050 zombie range" << std::endl;
			continue;;
		}
		std::cout << "Enter the name of the Zombies: ";
		std::getline(std::cin, zombieName);
		if (std::cin.eof()) {
			std::cout << std::endl << "Exiting zombieHorde. Goodbye!" << std::endl;
			break;
		}
		if (zombieName.empty()) {
			std::cout << "Field cannot be empty" << std::endl;
			continue;
		}
		Zombie *zombies = zombieHorde(zombieNumber, zombieName);
		for (int i = 0; i < zombieNumber; i++)
			zombies[i].announce();
		delete[] zombies;
		return 0;
	}
}