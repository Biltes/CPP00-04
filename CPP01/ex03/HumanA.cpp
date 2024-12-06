/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:48 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 18:11:31 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

humanA::humanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

humanA::~humanA() {}

void humanA::attack(void){
	std::cout << _name << " attacks with his " << _weapon.getType() << std::endl;
}
