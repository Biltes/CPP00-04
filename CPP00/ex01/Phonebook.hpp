/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:15:32 by migupere          #+#    #+#             */
/*   Updated: 2024/11/29 18:58:39 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <limits>

class PhoneBook {
private:
	Contact _contacts[8];
	int _oldestContact;
	int _id;
public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact() const;
};

#endif
