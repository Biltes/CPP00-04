/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:54:15 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 17:43:23 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Zombie {
private:
	std::string _name;

public:
	Zombie();
	~Zombie();
	void announce(void);
	void zombieName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif