/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 03:25:04 by tutku             #+#    #+#             */
/*   Updated: 2026/11/12 05:00:32 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MandatoryFunctions.hpp"

void printTitle(const std::string &title)
{
	std::cout << "\n"
			  << "========================================\n"
			  << title << "\n"
			  << "========================================\n";
}

void expect(bool condition, const std::string msg)
{
	if (condition)
	{
		std::cout << GREEN << "[PASS]" << RESET << msg << std::endl;
	}
	else
	{
		std::cout << RED << "[FAIL]" << RESET << msg << std::endl;
	}
}

void testIdentifyPointer()
{
	printTitle("IDENTIFY POINTER TESTS");

	A a;
	B b;
	C c;

	Base *testA = &a;
	Base *testB = &b;
	Base *testC = &c;

	std::cout << "Expected: A" << std::endl;
	identify(testA);
	std::cout << std::endl;

	std::cout << "Expected: B" << std::endl;
	identify(testB);
	std::cout << std::endl;

	std::cout << "Expected: C" << std::endl;
	identify(testC);
	std::cout << std::endl;
}

void testIdentifyReference()
{
	printTitle("IDENTIFY REFERENCE TESTS");

	A a;
	B b;
	C c;

	Base &testA = a;
	Base &testB = b;
	Base &testC = c;

	std::cout << "Expected: A" << std::endl;
	identify(testA);
	std::cout << std::endl;

	std::cout << "Expected: B" << std::endl;
	identify(testB);
	std::cout << std::endl;

	std::cout << "Expected: C" << std::endl;
	identify(testC);
	std::cout << std::endl;
}

void testGenerate()
{
	printTitle("GENERATE TESTS");

	for (int i = 0; i < 10; i++)
	{
		Base *test = generate();

		std::cout << "Test " << (i + 1) << ":" << std::endl;

		expect(test != nullptr, " generate() returned a random object");

		if (test != nullptr)
		{
			std::cout << "Pointer:   ";
			identify(test);

			std::cout << "Reference: ";
			identify(*test);

			delete test;
		}

		std::cout << std::endl;
	}
}

void testEdgeCases()
{
	printTitle("EDGE CASE TESTS");

	// Test 1: NULL
	std::cout << "--- Null ---" << std::endl;

	Base *test = NULL;
	identify(test);

	std::cout << std::endl;

	// Test 2: Base object
	std::cout << "--- Actual Base object ---" << std::endl;

	Base base;

	std::cout << "Pointer:   ";
	identify(&base);

	std::cout << "Reference: ";
	identify(base);

	std::cout << std::endl;
}

void testReassignPointer()
{
	printTitle("REASSIGN POINTER TESTS");

	A a;
	B b;
	C c;

	Base *test = &a;

	std::cout << "Expected: A" << std::endl;
	identify(test);

	test = &b;

	std::cout << "Expected: B" << std::endl;
	identify(test);

	test = &c;

	std::cout << "Expected: C" << std::endl;
	identify(test);
}

int main()
{
	// Get a different random number each time the program runs
	srand(time(NULL));

	testIdentifyPointer();
	testIdentifyReference();
	testGenerate();
	testEdgeCases();
	testReassignPointer();

	return 0;
}

/*
https://www.w3schools.com/cpp/cpp_howto_random_number.asp
*/
