/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:42 by tutku             #+#    #+#             */
/*   Updated: 2026/02/26 18:06:54 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

/*
==============================Const Member Functions==============================
https://www.geeksforgeeks.org/cpp/const-member-functions-c/
==============================Fixed Point Numbers==============================
https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html


To define a fixed point type conceptually, all we need are two parameters:

width of the number representation, and
binary point position within the number
fixed<w,b> for the rest of this article, 
where w denotes the number of bits used as a whole (the Width of a number), 
and b denotes the position of binary point counting from the least significant bit (counting from 0).
fixed<8,3> -> 8-bit fixed point number, of which 3 right most bits are fractional
*/