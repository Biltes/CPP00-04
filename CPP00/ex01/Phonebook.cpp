/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:29 by migupere          #+#    #+#             */
/*   Updated: 2024/11/29 19:25:51 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(){this->_id = 0, _oldestContact = 0;}
PhoneBook::~PhoneBook(){}

void PhoneBook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "First name: ";
	getline(std::cin, input);
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Last Name: ";
	getline(std::cin, input);
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Nickname: ";
	getline(std::cin, input);
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Phone number: ";
	getline(std::cin, input);
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	for(unsigned long i = 0; i < input.length(); i++) {
		if(!isdigit(input[i])) {
			std::cout << "Invalid phone number" << std::endl;
			return;
		}
	}
	newContact.setPhoneNumber(input);

	std::cout << "Darkest secret: ";
	getline(std::cin, input);
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	newContact.setDarkestSecret(input);

	_contacts[_oldestContact] = newContact;
	_oldestContact = (_oldestContact + 1) % 8;
	std::cout << "Contact added successfully!" << std::endl;;
}

void PhoneBook::searchContact() const 
{
	if (this->_oldestContact == 0) {
		std::cout << "No contacts available" << std::endl;
		return;
	}
	std::cout << "Index" << ":" << std::endl;
	std::cout << "First Name" << "|";
	std::cout << "Last Name" << "|";
	std::cout << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << (i + 1) << "|";
		std::cout << std::setw(10) << _contacts[i].getFirstName().substr(0, 9) + ".";
		std::cout << std::setw(10) << _contacts[i].getLastName().substr(0, 9) + ".";
		std::cout << std::setw(10) << _contacts[i].getNickname().substr(0, 9) + "." << std::endl;
	}
	if (std::cin.fail()) {
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta entrada inválida
        }
	int index;
	std::cout << "Enter the index: ";
	std::cin >> index;
	if (std::cin.eof()) {
		std::cout << "Exiting program..." << std::endl;
		return ;
	}
	if	(index >= 1 && index < 9) {
		std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;;
		std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;;
		std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;;
		std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;;
		std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;;
	}
	else {
		std::cout << "Invalid index" << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
