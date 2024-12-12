/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:45:46 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 14:54:14 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat:public Animal{
	public:
		Cat();
		~Cat();
		Cat(const Cat& src);
		Cat& operator=(const Cat& src);
		void makeSound() const;
};

#endif