/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:30 by migupere          #+#    #+#             */
/*   Updated: 2024/12/18 15:33:06 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
	ClapTrap clap1("C-3PO");
	ClapTrap clap2("R2-D2");
	ClapTrap clap3(clap1);
	ClapTrap clap4 = clap2;
	
	clap1.attack("R2-D2");
	clap2.takeDamage(2);
	clap1.attack("R2-D2");
	clap2.takeDamage(5);
	clap2.attack("C-3PO");
	clap1.takeDamage(10);

	clap1.beRepaired(8);
	clap1.attack("R2-D2");
	
	clap2.beRepaired(4);
	clap2.attack("C-3PO");
	clap1.takeDamage(10);
	clap3.takeDamage(8);

	return(0);
}