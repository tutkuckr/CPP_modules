/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:06:22 by tutku             #+#    #+#             */
/*   Updated: 2026/11/07 18:04:31 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void runTest(Data *test)
{
	uintptr_t serialized = Serializer::serialize(test);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Original pointer:     " << test << std::endl;
	std::cout << "Serialized integer:   " << serialized << std::endl;
	std::cout << "Deserialized pointer: " << deserialized << std::endl;
	std::cout << std::endl;

	if (test == deserialized)
	{
		if (deserialized != nullptr)
		{
			std::cout << "numVar:    " << deserialized->numVar << std::endl;
			std::cout << "doubleVar: " << deserialized->doubleVar << std::endl;
			std::cout << "strVar:    " << deserialized->strVar << std::endl;
		}
		std::cout << std::endl;
		std::cout << GREEN << "[PASS]" << RESET << " Pointers are equal." << std::endl;
	}
	else
	{
		std::cout << RED << "[FAIL]" << RESET << " Pointers are equal." << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}

static void test1()
{
	std::cout << BLUE << "\n========== STARTING TEST 1: BASIC TEST =========="
			  << RESET << std::endl;
	Data test;

	test.numVar = 42;
	test.doubleVar = 1.23;
	test.strVar = "TEST THIS!";
	runTest(&test);
}

static void test2()
{
	std::cout << BLUE << "\n========== STARTING TEST 2: NEGATIVE VALUES =========="
			  << RESET << std::endl;

	Data test;

	test.numVar = -2147483647;
	test.doubleVar = -123.456;
	test.strVar = "Negative values";

	runTest(&test);
}

static void test3()
{
	std::cout << BLUE << "\n========== STARTING TEST 3: DEFAULT VALUES =========="
			  << RESET << std::endl;

	Data test;

	runTest(&test);
}

static void test4()
{
	std::cout << BLUE << "\n========== STARTING TEST 4: NULL POINTER =========="
			  << RESET << std::endl;

	Data *test = nullptr;

	runTest(test);
}

static void test5()
{
	std::cout << BLUE << "\n========== STARTING TEST 5: HEAP ALLOCATION =========="
			  << RESET << std::endl;

	Data *test = new Data;

	test->numVar = 100;
	test->doubleVar = 99.99;
	test->strVar = "Heap allocation test";

	runTest(test);

	delete test;
}

static void test6()
{
	std::cout << BLUE << "\n========== STARTING TEST 6: MULTIPLE OBJECTS =========="
			  << RESET << std::endl;

	Data first;
	first.numVar = 10;
	first.doubleVar = 1.5;
	first.strVar = "First object";

	Data second;
	second.numVar = 20;
	second.doubleVar = 2.5;
	second.strVar = "Second object";

	std::cout << "----- First object -----" << std::endl;
	runTest(&first);

	std::cout << "----- Second object -----" << std::endl;
	runTest(&second);

	uintptr_t firstSerialized = Serializer::serialize(&first);
	uintptr_t secondSerialized = Serializer::serialize(&second);

	if (firstSerialized != secondSerialized)
		std::cout << GREEN << "[PASS]" << RESET
				  << " Different objects have different addresses."
				  << std::endl;
	else
		std::cout << RED << "[FAIL]" << RESET
				  << " Different objects have different addresses."
				  << std::endl;
}

static void test7()
{
	std::cout << BLUE << "\n========== STARTING TEST 7: MODIFY ORIGINAL =========="
			  << RESET << std::endl;

	Data test;
	test.numVar = 42;
	test.doubleVar = 3.14;
	test.strVar = "Original";

	uintptr_t serialized = Serializer::serialize(&test);
	Data *deserialize = Serializer::deserialize(serialized);

	deserialize->numVar = 100;
	deserialize->strVar = "Modified";

	if (test.numVar == 100 && test.strVar == "Modified" && deserialize == &test)
		std::cout << GREEN << "[PASS]" << RESET
				  << " Deserialized pointer modifies original object."
				  << std::endl;
	else
		std::cout << RED << "[FAIL]" << RESET
				  << " Deserialized pointer modifies original object."
				  << std::endl;

	std::cout << "--------------------------------" << std::endl;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();

	return 0;
}
