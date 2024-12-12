/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:32:02 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 15:07:39 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		std::string getType() const;
		virtual void makeSound() const;
};

#endif