/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:41 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 15:01:52 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& src){
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog & Dog::operator=(const Dog& src){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Woof! Woof!" << std::endl;
}
                       