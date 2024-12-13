/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:32:41 by migupere          #+#    #+#             */
/*   Updated: 2024/12/12 17:37:55 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain& src);
		Brain& operator=(const Brain& src);
		
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};

#endif