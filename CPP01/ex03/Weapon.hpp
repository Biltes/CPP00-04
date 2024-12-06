/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:01:22 by migupere          #+#    #+#             */
/*   Updated: 2024/12/04 18:03:47 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
	std::string _type;
	
public:
	Weapon(std::string type);
	~Weapon();
	const std::string& getType(void);
	void setType(std::string type);
};

#endif
