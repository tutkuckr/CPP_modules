/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:42 by tutku             #+#    #+#             */
/*   Updated: 2026/03/07 22:08:33 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main(void)
// {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

static void separator(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========\n"
			  << std::endl;
}

int main(void)
{
	separator("CONSTRUCTORS");

	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	separator("COPY ASSIGNMENT");

	a = Fixed(1234.4321f);
	std::cout << "a after assignment = " << a << std::endl;

	separator("TOINT / TOFLOAT");

	std::cout << "a.toInt() = " << a.toInt() << std::endl;
	std::cout << "a.toFloat() = " << a.toFloat() << std::endl;

	std::cout << "b.toInt() = " << b.toInt() << std::endl;
	std::cout << "b.toFloat() = " << b.toFloat() << std::endl;

	std::cout << "c.toInt() = " << c.toInt() << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << std::endl;

	separator("GETRAWBITS / SETRAWBITS");

	Fixed rawTest;
	std::cout << "rawTest initial raw bits = " << rawTest.getRawBits() << std::endl;
	rawTest.setRawBits(256);
	std::cout << "rawTest after setRawBits(256) = " << rawTest << std::endl;
	std::cout << "rawTest raw bits = " << rawTest.getRawBits() << std::endl;

	separator("COMPARISON OPERATORS");

	Fixed x(5.5f);
	Fixed y(2.25f);
	Fixed z(5.5f);

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "z = " << z << std::endl;

	std::cout << "x > y  : " << (x > y) << std::endl;
	std::cout << "x < y  : " << (x < y) << std::endl;
	std::cout << "x >= y : " << (x >= y) << std::endl;
	std::cout << "x <= y : " << (x <= y) << std::endl;
	std::cout << "x == y : " << (x == y) << std::endl;
	std::cout << "x != y : " << (x != y) << std::endl;

	std::cout << "x == z : " << (x == z) << std::endl;
	std::cout << "x != z : " << (x != z) << std::endl;
	std::cout << "x >= z : " << (x >= z) << std::endl;
	std::cout << "x <= z : " << (x <= z) << std::endl;

	separator("ARITHMETIC OPERATORS");

	Fixed n1(10.5f);
	Fixed n2(2.0f);

	std::cout << "n1 = " << n1 << std::endl;
	std::cout << "n2 = " << n2 << std::endl;

	std::cout << "n1 + n2 = " << (n1 + n2) << std::endl;
	std::cout << "n1 - n2 = " << (n1 - n2) << std::endl;
	std::cout << "n1 * n2 = " << (n1 * n2) << std::endl;
	std::cout << "n1 / n2 = " << (n1 / n2) << std::endl;
	
	Fixed n3(1.5f);
	Fixed n4(2.25f);

	std::cout << "n3 = " << n3 << std::endl;
	std::cout << "n4 = " << n4 << std::endl;

	std::cout << "n3 + n4 = " << (n3 + n4) << std::endl;
	std::cout << "n3 - n4 = " << (n3 - n4) << std::endl;
	std::cout << "n3 * n4 = " << (n3 * n4) << std::endl;
	std::cout << "n3 / n4 = " << (n3 / n4) << std::endl;
	//(384 << 8) / 576= 98304 / 576= 170 -> 170 / 256 = 0.6640625

	separator("PRE-INCREMENT");

	/*
	ϵ = 1 / (1 << 8)
	= 1 / 256
	= 0.00390625
	This is the smallest representable increment
	*/
	Fixed inc1;

	std::cout << "inc1 before = " << inc1 << std::endl;
	std::cout << "++inc1 = " << ++inc1 << std::endl;
	std::cout << "inc1 after = " << inc1 << std::endl;

	std::cout << "++inc1 = " << ++inc1 << std::endl;
	std::cout << "inc1 after second prefix = " << inc1 << std::endl;

	separator("POST-INCREMENT");

	Fixed inc2;

	std::cout << "inc2 before = " << inc2 << std::endl;
	std::cout << "inc2++ returns = " << inc2++ << std::endl;
	std::cout << "inc2 after = " << inc2 << std::endl;

	std::cout << "inc2++ returns = " << inc2++ << std::endl;
	std::cout << "inc2 after second postfix = " << inc2 << std::endl;

	separator("PRE-DECREMENT");

	Fixed dec1(1);

	std::cout << "dec1 before = " << dec1 << std::endl;
	std::cout << "--dec1 = " << --dec1 << std::endl;
	std::cout << "dec1 after = " << dec1 << std::endl;

	std::cout << "--dec1 = " << --dec1 << std::endl;
	std::cout << "dec1 after second prefix decrement = " << dec1 << std::endl;

	separator("POST-DECREMENT");

	Fixed dec2(1);

	std::cout << "dec2 before = " << dec2 << std::endl;
	std::cout << "dec2-- returns = " << dec2-- << std::endl;
	std::cout << "dec2 after = " << dec2 << std::endl;

	std::cout << "dec2-- returns = " << dec2-- << std::endl;
	std::cout << "dec2 after second postfix decrement = " << dec2 << std::endl;

	separator("MIN / MAX WITH NON-CONST OBJECTS");

	Fixed m1(3.5f);
	Fixed m2(7.25f);

	std::cout << "m1 = " << m1 << std::endl;
	std::cout << "m2 = " << m2 << std::endl;

	std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
	std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

	separator("MIN / MAX WITH CONST OBJECTS");

	const Fixed cm1(12.75f);
	const Fixed cm2(6.125f);

	std::cout << "cm1 = " << cm1 << std::endl;
	std::cout << "cm2 = " << cm2 << std::endl;

	std::cout << "min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
	std::cout << "max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;

	separator("CHAINED EXPRESSIONS");

	Fixed p1(1.5f);
	Fixed p2(2.5f);
	Fixed p3(3.0f);

	std::cout << "p1 = " << p1 << std::endl;
	std::cout << "p2 = " << p2 << std::endl;
	std::cout << "p3 = " << p3 << std::endl;

	std::cout << "(p1 + p2) * p3 = " << ((p1 + p2) * p3) << std::endl;
	std::cout << "(p3 - p1) / p2 = " << ((p3 - p1) / p2) << std::endl;

	separator("SUBJECT-LIKE TEST");

	Fixed subA;
	Fixed const subB(Fixed(5.05f) * Fixed(2));

	std::cout << "subA = " << subA << std::endl;
	std::cout << "++subA = " << ++subA << std::endl;
	std::cout << "subA = " << subA << std::endl;
	std::cout << "subA++ = " << subA++ << std::endl;
	std::cout << "subA = " << subA << std::endl;
	std::cout << "subB = " << subB << std::endl;
	std::cout << "max(subA, subB) = " << Fixed::max(subA, subB) << std::endl;

	separator("END");

	return (0);
}
