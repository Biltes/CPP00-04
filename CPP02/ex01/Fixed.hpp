/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:10:09 by migupere          #+#    #+#             */
/*   Updated: 2024/12/06 18:46:19 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int _value;
		const static int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(int const intValue);
		Fixed(float const floatValue);
		Fixed(Fixed const & src);
		~Fixed();
		Fixed & operator=(Fixed const & src);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif