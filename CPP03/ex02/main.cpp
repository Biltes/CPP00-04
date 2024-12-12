/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:47:50 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 15:47:04 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	ClapTrap clap1("C-4PO");
	ClapTrap clap2("R2-D3");
	
	ScavTrap scav1("C-3PO");
	ScavTrap scav2("R2-D2");

	FragTrap frag1("BB-8");
	FragTrap frag2("BB-9E");

	clap1.attack("R2-D3");
	scav1.attack("R2-D2");
 
	clap2.takeDamage(2);
	scav2.takeDamage(2);
	frag2.takeDamage(2);

	clap1.beRepaired(2);
	scav1.beRepaired(2);
	frag1.attack("BB-9E");
	frag1.beRepaired(2);

	frag1.highFivesGuys();

	frag2.takeDamage(200);
	frag2.beRepaired(200);
	frag2.highFivesGuys();
	
	scav2.takeDamage(200);
	scav2.guardGate();
	scav1.guardGate();

	return (0);
}