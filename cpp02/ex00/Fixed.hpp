/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:40 by tutku             #+#    #+#             */
/*   Updated: 2026/02/26 15:44:30 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int fixed = 8;
		

	public:
		Fixed();								//constructor
		Fixed(const Fixed &other);				//copy constructor
		Fixed &operator=(const Fixed& other);	//copy assignment operator
		~Fixed();								// destructor
		int getRawBits(void) const;
};
#endif

/*
 The idea of const functions is 
 not to allow them to modify the object on which they are called.
*/