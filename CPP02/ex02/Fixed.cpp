/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:55:42 by migupere          #+#    #+#             */
/*   Updated: 2024/12/09 16:33:26 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0){
}

Fixed::Fixed(Fixed const & src){
	*this = src;
}

Fixed::Fixed(int const intValue){
	_value = intValue << _fractionalBits;
}

Fixed::Fixed(float const floatValue){
	_value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed & Fixed::operator=(Fixed const & src){
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed(){
}

int Fixed::getRawBits( void ) const{
	return _value;
}

void Fixed::setRawBits( int const raw){
	_value = raw;
}

float Fixed::toFloat( void ) const{
	return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const{
	return _value / (1 << _fractionalBits);
}

Fixed Fixed::operator+(Fixed const & src){
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed const & src){
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(Fixed const & src){
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(Fixed const & src){
	return Fixed(this->toFloat() / src.toFloat());
}

Fixed & Fixed::operator++(){
	_value++;
	return *this;
}

Fixed & Fixed::operator--(){
	_value--;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	operator--();
	return tmp;
}

bool Fixed::operator>(Fixed const & src) const{
	return _value > src._value;
}

bool Fixed::operator<(Fixed const & src) const{
	return _value < src._value;
}

bool Fixed::operator>=(Fixed const & src) const{
	return _value >= src._value;
}

bool Fixed::operator<=(Fixed const & src) const{
	return _value <= src._value;
}

bool Fixed::operator==(Fixed const & src) const{
	return _value == src._value;
}

bool Fixed::operator!=(Fixed const & src) const{
	return _value != src._value;
}

Fixed & Fixed::max(Fixed & a, Fixed & b){
	return (a > b) ? a : b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b){
	return (a > b) ? a : b;
}

Fixed & Fixed::min(Fixed & a, Fixed & b){
	return (a < b) ? a : b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b){
	return (a < b) ? a : b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & src){
	o << src.toFloat();
	return o;
}