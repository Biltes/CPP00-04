/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:33:46 by migupere          #+#    #+#             */
/*   Updated: 2024/12/13 11:34:16 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& src){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain & Brain::operator=(const Brain& src){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = src.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index) const{
	if (index < 0 || index >= 100)
		return ("Invalid index");
	return (ideas[index]);
}

void Brain::setIdea(int index, std::string idea){
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	else
		std::cout << "Invalid index" << std::endl;
}
