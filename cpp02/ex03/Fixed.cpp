/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:35 by tutku             #+#    #+#             */
/*   Updated: 2026/03/09 04:07:45 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const Fixed& other)
{
	fixedPoint = other.fixedPoint;
}

//stored= raw << fractionalBits
Fixed::Fixed(const int raw)
{
	fixedPoint = raw << fixed;
}

//stored = roundf(raw * (1 << fractionalBits))
Fixed::Fixed(const float raw)
{
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
}

int Fixed::getRawBits(void) const
{
	return (fixedPoint); //check this one
}

void Fixed::setRawBits(int const raw)
{
	fixedPoint = raw;
}

// copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
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

// ============ comparison operators ============
bool Fixed::operator>(const Fixed &other) const
{
	if (fixedPoint > other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
	if (fixedPoint < other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (fixedPoint >= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (fixedPoint <= other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const 
{
	if (fixedPoint == other.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (fixedPoint != other.getRawBits())
		return (true);
	return (false);
}

// ============ min,max ============
// only static member functions can be called without an object

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}
Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}
const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}
