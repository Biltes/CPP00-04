/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:08:22 by migupere          #+#    #+#             */
/*   Updated: 2024/12/05 12:22:55 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

humanB::humanB(std::string name) : _name(name) { _weapon = NULL; }

humanB::~humanB() {}

void humanB::attack(void){
	if (_weapon == NULL)
		std::cout << _name << " has no weapon" << std::endl;
	else
		std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
}

void humanB::setWeapon(Weapon &weapon){
	_weapon = &weapon;
}
