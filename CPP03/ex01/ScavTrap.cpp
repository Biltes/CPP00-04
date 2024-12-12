/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:09:26 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 15:26:06 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Default ScavTrap"){
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Default ScavTrap " << _name << " was created and it's ready to fight!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " was created and it's ready to fight!" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << _name << " was destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src): ClapTrap(src){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src){
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target){
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
		std::cout << "[ScavTrap " << _name << " - Hit Points: " << _hitPoints << ", Energy Points: " << _energyPoints << ", Attack Damage: " << _attackDamage << "]" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " cannot attack!" << std::endl;
}

void ScavTrap::guardGate(){
	if (_energyPoints > 0 && _hitPoints > 0)
		std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode! No one shall pass!!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " cannot guard the gate!" << std::endl;
}
