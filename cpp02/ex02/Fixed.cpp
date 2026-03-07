/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:35 by tutku             #+#    #+#             */
/*   Updated: 2026/03/07 20:59:31 by tutku            ###   ########.fr       */
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
	std::cout << "setRawBits member function called" << std::endl;
	fixedPoint = raw;
}

// copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		this->fixedPoint = other.fixedPoint;
	return (*this);
}

// operator for when the object is passed as a parameter
std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	os << other.toFloat();
	return (os);
}

// ============arithmetic operators: +, -, *, and /============

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;

	result.setRawBits(fixedPoint + other.fixedPoint);
	// result.fixedPoint = fixedPoint + other.fixedPoint;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;

	result.setRawBits(fixedPoint - other.fixedPoint);
	// result.fixedPoint = fixedPoint - other.fixedPoint;
	return (result);
}

// each value already had (<< 8)
// result becomes: 2^8 * 2^8 = 2^16
// we add >> 8
Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;

	result.setRawBits((fixedPoint * other.fixedPoint) >> fixed);
	// result.fixedPoint = (fixedPoint * other.fixedPoint) >> fixed;
	return (result);
}

// for division, loose the scaling when divide
// *before* dividing we increase precision
Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result;

	result.setRawBits((fixedPoint << fixed) / other.fixedPoint);
	// result.fixedPoint = ((fixedPoint << fixed) / other.fixedPoint) ;
	return (result);
}

// ============ increment/decrement operators: ++,-- ============

// prefix (++a) -> returns modified object
// increment and returns the updated object
Fixed& Fixed::operator++()
{
	fixedPoint++;
	return (*this);
}

// postfix (a++) -> must return old copy
// save old value in temp
// increment, then return saved copy
// (int) is never used, it is only there to differentiate
// temp is local var, cannot return reference here!
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	fixedPoint++;
	return (temp);
}

//prefix increment
Fixed& Fixed::operator--()
{
	fixedPoint--;
	return (*this);
}

//postfix increment
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	fixedPoint--;
	return (temp);
}

static int &min(int &fixed1, int &fixed2);
static int &min(const int &fixed1, const int &fixed2);
static int &max(int &fixed1, int &fixed2);
static int &max(const int &fixed1, const int &fixed2);
