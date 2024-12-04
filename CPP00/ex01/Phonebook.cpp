/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:29 by migupere          #+#    #+#             */
/*   Updated: 2024/12/03 17:44:34 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

PhoneBook::PhoneBook(){this->_id = 0, _oldestContact = 0;}
PhoneBook::~PhoneBook(){}

void PhoneBook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "First name: ";
	if (!getline(std::cin, input))
		return ;
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Last Name: ";
	if (!getline(std::cin, input))
		return ;
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Nickname: ";
	if (!getline(std::cin, input))
		return ;
	if(input.empty()) {
		std::cout << "Field cannot be empty" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Phone number: ";
	if (!getline(std::cin, input))
		return ;
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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
	int index;
	std::cout << "Enter the index: ";
	std::cin >> index;
	if (std::cin.eof()) {
		return ;
	}
	if	(index >= 1 && index < 9) {
		std::cout << "First Name: " << _contacts[index - 1].getFirstName() << std::endl;;
		std::cout << "Last Name: " << _contacts[index - 1].getLastName() << std::endl;;
		std::cout << "Nickname: " << _contacts[index - 1].getNickname() << std::endl;;
		std::cout << "Phone number: " << _contacts[index - 1].getPhoneNumber() << std::endl;;
		std::cout << "Darkest secret: " << _contacts[index - 1].getDarkestSecret() << std::endl;;
	}
	else {
		std::cout << "Invalid index" << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
