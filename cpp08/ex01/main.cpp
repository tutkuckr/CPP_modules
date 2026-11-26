/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:59:07 by tutku             #+#    #+#             */
/*   Updated: 2026/11/26 03:22:22 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void check(bool condition, const std::string &message)
{
	if (condition)
		std::cout << GREEN << "[PASS] " << RESET;
	else
		std::cout << RED << "[FAIL] " << RESET;

	std::cout << message << std::endl;
}

void testSubjectExample()
{
	std::cout << "\n===== SUBJECT EXAMPLE =====\n";

	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	check(sp.shortestSpan() == 2, "Shortest span is 2");
	check(sp.longestSpan() == 14, "Longest span is 14");
}

void testIdenticalNumbers()
{
	std::cout << "\n===== IDENTICAL NUMBERS =====\n";

	Span sp(2);

	sp.addNumber(7);
	sp.addNumber(7);

	check(sp.shortestSpan() == 0, "Shortest span is 0");
	check(sp.longestSpan() == 0, "Longest span is 0");
}

void testNegativeNumbers()
{
	std::cout << "\n===== NEGATIVE NUMBERS =====\n";

	Span sp(3);

	sp.addNumber(-10);
	sp.addNumber(-3);
	sp.addNumber(-20);

	check(sp.shortestSpan() == 7, "Shortest span is 7");
	check(sp.longestSpan() == 17, "Longest span is 17");
}

void testSingleNumber()
{
	std::cout << "\n===== SINGLE NUMBER =====\n";

	Span sp(5);

	sp.addNumber(5);

	try
	{
		sp.shortestSpan();
		check(false, "shortestSpan() should throw");
	}
	catch (const Span::NotEnoughNumbersStored &e)
	{
		check(true, e.what());
	}

	try
	{
		sp.longestSpan();
		check(false, "longestSpan() should throw");
	}
	catch (const Span::NotEnoughNumbersStored &e)
	{
		check(true, e.what());
	}
}

void testAlreadyFullVector()
{
	std::cout << "\n===== ALREADY FULL VECTOR =====\n";

	Span sp(2);

	sp.addNumber(10);
	sp.addNumber(20);

	try
	{
		sp.addNumber(30);
		check(false, "Adding beyond capacity should throw");
	}
	catch (const Span::VectorAlreadyFull &e)
	{
		check(true, e.what());
	}

	check(sp.shortestSpan() == 10, "Shortest span is unchanged");
	check(sp.longestSpan() == 10, "Longest span is unchanged");
}

void testZeroCapacity()
{
	std::cout << "\n===== ZERO CAPACITY =====\n";

	Span sp(0);

	try
	{
		sp.addNumber(42);
		check(false, "Adding to zero capacity should throw");
	}
	catch (const Span::VectorAlreadyFull &e)
	{
		check(true, e.what());
	}
}

void testLargeSpan()
{
	std::cout << "\n===== 10,000 NUMBERS =====\n";

	Span sp(10000);

	for (int i = 0; i < 10000; ++i)
		sp.addNumber(i);

	check(sp.shortestSpan() == 1, "Shortest span is 1");
	check(sp.longestSpan() == 9999, "Longest span is 9999");
}

void testEmptySpan()
{
	std::cout << "\n===== EMPTY SPAN =====\n";

	Span sp(5);

	try
	{
		sp.shortestSpan();
		check(false, "shortestSpan() should throw on empty vector");
	}
	catch (const Span::NotEnoughNumbersStored &e)
	{
		check(true, "shortestSpan() correctly throws on empty vector");
		std::cout << e.what() << std::endl;
	}

	try
	{
		sp.longestSpan();
		check(false, "longestSpan() should throw on empty vector");
	}
	catch (const Span::NotEnoughNumbersStored &e)
	{
		check(true, "longestSpan() correctly throws on empty vector");
		std::cout << e.what() << std::endl;
	}
}

void testOverflow()
{
	std::cout << "\n===== OVERFLOW =====\n";
	Span sp(2);

	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);

	try
	{
		std::cout << sp.longestSpan() << std::endl;
		check(false, "Overflow should throw an exception");
	}
	catch (const std::exception &e)
	{
		check(true, "Overflow exception thrown correctly");
	}
}

int main()
{
	testSubjectExample();
	testIdenticalNumbers();
	testNegativeNumbers();
	testSingleNumber();
	testAlreadyFullVector();
	testZeroCapacity();
	testLargeSpan();
	testEmptySpan();
	testOverflow();

	return 0;
}
/*
https://www.geeksforgeeks.org/cpp/sorting-a-vector-in-c/
*/
