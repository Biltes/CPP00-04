/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:19 by migupere          #+#    #+#             */
/*   Updated: 2024/11/28 17:17:32 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) :
 _firstName(firstName), _lastName(lastName), _nickname(nickname), _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {}

void Contact::displayContact(void) {
	std::cout << "CONTACT INFORMATION" << std::endl;
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret" << _darkestSecret << std::endl;
	// cin.ignore();
}

void Contact::setFirstName(const std::string &name) {
	_firstName = name;
}

void Contact::setLastName(const std::string &name) {
	_lastName = name;
}

void Contact::setNickname(const std::string &nickname) {
	_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phone) {
	_phoneNumber = phone;
}

void Contact::setDarkestSecret(const std::string &secret) {
	_darkestSecret = secret;
}

const std::string &Contact::getFirstName(void) const {
	return _firstName;
}

const std::string &Contact::getLastName(void) const {
	return _lastName;
}

const std::string &Contact::getNickname(void) const {
	return _nickname;
}

const std::string &Contact::getPhoneNumber(void) const {
	return _phoneNumber;
}

const std::string &Contact::getDarkestSecret(void) const {
	return _darkestSecret;
}
