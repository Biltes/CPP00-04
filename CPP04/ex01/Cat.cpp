/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:46:36 by migupere          #+#    #+#             */
/*   Updated: 2024/12/13 11:27:17 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): brain(new Brain()){
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src){
	brain = new Brain(*src.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat & Cat::operator=(const Cat& src){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &src)
	{
		type = src.type;
		delete brain;
		brain = new Brain(*src.brain);
	}
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meeeeoow" << std::endl;
}

Brain* Cat::getBrain() const{
	return brain;
}