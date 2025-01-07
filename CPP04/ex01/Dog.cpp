/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:43:41 by migupere          #+#    #+#             */
/*   Updated: 2024/12/13 11:27:29 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): brain(new Brain()){
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& src): Animal(src){
	brain = new Brain(*src.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog & Dog::operator=(const Dog& src){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &src)
	{
		type = src.type;
		delete brain;
		brain = new Brain(*src.brain);
	}
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const{
	return brain;
}
