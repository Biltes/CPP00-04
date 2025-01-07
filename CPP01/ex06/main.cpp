/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:45:38 by migupere          #+#    #+#             */
/*   Updated: 2024/12/13 17:06:01 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
	if (ac != 2){
		std::cerr << "Usage: " << av[0] << " <level>" << std::endl;
		return 1;
	}

	Harl harl;

	harl.complain(av[1]);
	return 0;
}
