/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:44:00 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 15:46:41 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default FragTrap"){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Default FragTrap was created and it's ready to fight!" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " was created and it's ready to fight!" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << _name << " was destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& src): ClapTrap(src){
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(const FragTrap& src){
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void FragTrap::highFivesGuys(void){
	if (_energyPoints > 0 && _hitPoints > 0)
		std::cout << "FragTrap " << _name << " says: Give me five guys!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " cannot give five guys!" << std::endl;
}
