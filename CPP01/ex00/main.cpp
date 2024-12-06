/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:49:33 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 17:30:34 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string ZombieName;
	
	while(true){
		std::cout << "Enter the name of the Zombie: ";
		std::getline(std::cin, ZombieName);
		if (std::cin.eof()) {
			std::cout << std::endl << "Exiting Zombie. Goodbye!" << std::endl;
			break;
		}
		if (ZombieName.empty()) {
			std::cout << "Field cannot be empty" << std::endl;
			continue;
		}
		Zombie *zombie = newZombie(ZombieName);
		zombie->announce();
		delete zombie;
		std::cout << "Enter the name of the Zombie: ";
		std::getline(std::cin, ZombieName);
		if (std::cin.eof()) {
			std::cout << std::endl << "Exiting Zombie. Goodbye!" << std::endl;
			break;
		}
		if (ZombieName.empty()) {
			std::cout << "Field cannot be empty" << std::endl;
			continue;
		}
		randomChump(ZombieName);
		return 0;
	}
}
