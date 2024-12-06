/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:05:11 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 18:09:18 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class humanA {
private:
	std::string _name;
	Weapon &_weapon;
	
public:
	humanA(std::string name, Weapon &weapon);
	~humanA();
	void attack(void);
};

#endif