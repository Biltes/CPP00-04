/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:50:42 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 14:51:00 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat:public WrongAnimal{
	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat& src);
		WrongCat& operator=(const WrongCat& src);
		void makeSound() const;
};

#endif