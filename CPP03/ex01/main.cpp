/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:23:23 by migupere          #+#    #+#             */
/*   Updated: 2024/12/18 15:44:28 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav1("C-3PO");
	ScavTrap scav2("R2-D2");
	ScavTrap scav3(scav1);
	ScavTrap scav4 = scav2;

	scav1.attack("R2-D2");
	scav1.takeDamage(3);
	scav1.beRepaired(2);
	scav2.attack("C-3PO");
	scav2.takeDamage(100);

	scav2.guardGate();
	scav3.guardGate();
	scav4.guardGate();
	
	

	return (0);
}