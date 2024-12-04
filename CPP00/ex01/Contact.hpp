/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:23 by migupere          #+#    #+#             */
/*   Updated: 2024/12/03 13:26:20 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
		const std::string &getFirstName(void) const;
    	const std::string &getLastName(void) const;
    	const std::string &getNickname(void) const;
    	const std::string &getPhoneNumber(void) const;
    	const std::string &getDarkestSecret(void) const;
    	void setFirstName(const std::string &name);
    	void setLastName(const std::string &name);
    	void setNickname(const std::string &nickname);
    	void setPhoneNumber(const std::string &phone);
   		void setDarkestSecret(const std::string &secret);
	private:
		void displayContact(void);
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif
