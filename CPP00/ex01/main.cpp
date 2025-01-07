/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:26 by migupere          #+#    #+#             */
/*   Updated: 2024/12/16 16:05:59 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main (void)
{
	PhoneBook phonebook;
	std::string command;

	std::cout << "Welcome to the Phonebook!" << std::endl;
	while(true)
	{
		command.clear();
		if (std::cin.eof()){
			std::cout << "\nExiting Phonebook. Goodbye!" << std::endl;
			break ;
		}
		std::cout << "Please enter a command: ";
		if (!std::getline(std::cin, command))
        {
            std::cout << "\nExiting Phonebook. Goodbye!" << std::endl;
            break;
        }
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Exiting Phonebook. Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try ADD, SEARCH or EXIT." << std::endl;
	}
	return 0;
}
