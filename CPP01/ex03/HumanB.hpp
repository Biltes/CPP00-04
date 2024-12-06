/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:08 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 18:09:05 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class humanB {
private:
	std::string _name;
	Weapon *_weapon;

public:
	humanB(std::string name);
	~humanB();
	void attack(void);
	void setWeapon(Weapon &weapon);
};

#endif
