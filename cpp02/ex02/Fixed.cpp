/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:35 by tutku             #+#    #+#             */
/*   Updated: 2026/03/04 18:08:34 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPoint = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPoint = other.fixedPoint;
}

//stored= raw << fractionalBits
Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPoint = raw << fixed;
}

//stored = roundf(raw * (1 << fractionalBits))
Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(raw * (1 << fixed)) ;
}

//converts the fixed-point value to a floating-point value
float Fixed::toFloat(void) const
{
	return ((float)fixedPoint / ( 1 << fixed));
}

//converts the fixed-point value to an integer value
int Fixed::toInt(void ) const
{
	return (fixedPoint >> fixed);
}

//copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->fixedPoint = other.fixedPoint;
	return (*this);
}

//operator for when the object is passed as a parameter
std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPoint); //check this one
}

void Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}
