/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:41:54 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 14:54:10 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog:public Animal{
	public:
		Dog();
		~Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);
		void makeSound() const;
};

#endif