/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:40 by tutku             #+#    #+#             */
/*   Updated: 2026/03/07 21:47:54 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedPoint;
		static const int	fixed = 8;

	public:
		Fixed();								//constructor
		Fixed(const int raw);					//int to fixed point
		Fixed(const float raw);					//float to fixed point
		Fixed(const Fixed &other);				//copy constructor
		Fixed &operator=(const Fixed &other);	// copy assignment operator
		//ARITHMETIC OPERATORS
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);
		//COMPARISON OPERATORS
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		//PREFIX POSTFIX 
		Fixed &operator++();					//prefix -> ++a
		Fixed operator++(int);					//postfix -> a++
		Fixed &operator--();
		Fixed operator--(int);

		~Fixed(); // destructor
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		void	convertToFixed(const int raw);
		void	convertToFixed(const float raw);
		float	toFloat(void) const;
		int		toInt(void ) const;
		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);
#endif

/*
 The idea of const functions is 
 not to allow them to modify the object on which they are called.
*/

/*
Overloading the << Operator for Your Own Classes
https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
*/
