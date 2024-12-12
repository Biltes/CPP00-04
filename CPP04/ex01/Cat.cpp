/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:46:36 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 15:02:04 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& src){
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat & Cat::operator=(const Cat& src){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meeeeoow" << std::endl;
}
