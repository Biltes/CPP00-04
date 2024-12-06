/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:46:43 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 17:30:23 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << _name << " is dead" << std::endl;
}

void Zombie::announce(void) {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
