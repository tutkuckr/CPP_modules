/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:40 by tutku             #+#    #+#             */
/*   Updated: 2026/02/25 19:31:40 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		

	public:
		Fixed();								//constructor
		Fixed(const Fixed &other);				//copy constructor
		Fixed &operator=(const Fixed& other);	//copy assignment operator
		~Fixed();								// destructor
		int getRawBits(void);
};
#endif
