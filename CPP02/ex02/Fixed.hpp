/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:15:01 by migupere          #+#    #+#             */
/*   Updated: 2024/12/09 16:31:11 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		Fixed(int const intValue);
		Fixed(float const floatValue);
		Fixed(Fixed const & src);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		
		Fixed & operator=(Fixed const & src);
		Fixed operator+(Fixed const & src);
		Fixed operator-(Fixed const & src);
		Fixed operator*(Fixed const & src);
		Fixed operator/(Fixed const & src);
		Fixed & operator++();
		Fixed operator++(int);
		Fixed & operator--();
		Fixed operator--(int);
		
		bool operator>(Fixed const & src) const;
		bool operator<(Fixed const & src) const;
		bool operator>=(Fixed const & src) const;
		bool operator<=(Fixed const & src) const;
		bool operator==(Fixed const & src) const;
		bool operator!=(Fixed const & src) const;

		static Fixed & max(Fixed & a, Fixed & b);
		static Fixed const & max(Fixed const & a, Fixed const & b);
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif