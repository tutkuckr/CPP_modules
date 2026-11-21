/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:40:05 by tutku             #+#    #+#             */
/*   Updated: 2026/11/21 03:33:18 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void check(bool condition, const std::string& testMsg)
{
	if (condition)
	{
		std::cout << GREEN << "[PASS] " << RESET << " " << testMsg << std::endl;
	}
	else
	{
		std::cout << RED << "[FAIL]" << RESET << " " << testMsg << std::endl;
	}
}

int main (void)
{
	std::cout << CYAN << "\n===== EMPTY ARRAY =====\n" << RESET;
	Array<int> empty;
	check(empty.size() == 0, "Size of empty array is0");
	try
	{
		empty[0] = 10;
		check(false, "Empty array access throws exception");
	}
	catch (const std::exception &e)
	{
		check(true, "Empty array access throws exception");
	}

	std::cout << CYAN << "\n===== ARRAY WITH SIZE =====\n" << RESET;

	unsigned int arrSize = 5;
	Array<int> arr(arrSize);
	check(arr.size() == arrSize, "Size of array is 5");

	try
	{
		arr[100] = 10;
		check(false, "Index greater than size throws exception");
	}
	catch (const std::exception &e)
	{
		check(true, "Index greater than size throws exception");
	}

	std::cout << CYAN << "\n===== ARRAY ELEMENTS ARE INITIALIZED TO 0 =====\n" << RESET;
	bool isAllZero = true;

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if (arr[i] != 0)
			isAllZero = false;
	}
	check(isAllZero, "All elements are 0");

	std::cout << CYAN << "\n===== CHANGE ARRAY ELEMENTS =====\n" << RESET;

	arr[0] = -1;
	arr[3] = -100;
	arr[2] = 42;

	check(arr[0] == -1, "Element index 0 is -1");
	check(arr[3] == -100, "Element index 3 is -100");
	check(arr[2] == 42, "Element index 2 is 42");

	std::cout << CYAN << "\n===== COPY CONSTRUCTOR =====\n" << RESET;

	Array<int> copy(arr);
	check(copy.size() == arr.size(), "Copy has same size");
	check(copy[0] == arr[0], "Copy has same values");

	copy[0] = 999;
	check(arr[0] == arr[0], "Original array unchanged after modifying copy");
	check(copy[0] == 999, "Copy array modified successfully");

	std::cout << CYAN << "\n===== ASSIGNMENT OPERATOR =====\n"
			  << RESET;

	Array<int> assign(1);
	assign = arr;

	check(assign.size() == arr.size(), "Assigned array has correct size");
	check(assign[0] == arr[0], "Assigned array has correct first element");
	check(assign[2] == arr[2], "Assigned array has correct third element");
	check(assign[3] == arr[3], "Assigned array has correct fourth element");

	assign[1] = 4242;

	check(arr[1] == 0, "Original array stays the same after assignment");
	check(assign[1] == 4242, "Assigned array modified successfully");

	std::cout << CYAN << "\n===== OUT OF BOUNDS =====\n" << RESET;

	try
	{
		arr[-1] = 5;
		check(false, "Negative index throws the exception");
	}
	catch(const std::exception& e)
	{
		check(true, "Negative index throws the exception");
	}

	try
	{
		arr[5] = 5;
		check(false, "Index equal to size throws exception");
	}
	catch (const std::exception &e)
	{
		check(true, "Index equal to size throws exception");
	}
	std::cout << CYAN << "\n===== STRING ARRAY =====\n" << RESET;

	Array<std::string> strings(3);

	check(strings.size() == 3, "String array has correct size");
	check(strings[0] == "", "String initialized empty");

	strings[0] = "Hello";
	strings[1] = "World";

	check(strings[0] == "Hello", "First string assigned");
	check(strings[1] == "World", "Second string assigned");

	std::cout << CYAN << "\n===== CHAR ARRAY =====\n"
			  << RESET;

	Array<char> chars(3);

	check(chars[0] == '\0', "Char initialized to null character");

	chars[0] = 'A';
	check(chars[0] == 'A', "Char assigned correctly");

	std::cout << CYAN << "\n===== BOOL ARRAY =====\n"
			  << RESET;

	Array<bool> bools(3);

	check(bools[0] == false, "Bool initialized to false");

	bools[0] = true;
	check(bools[0] == true, "Bool assigned correctly");

	return (0);
}

/*
new int[3]();          // 0, 0, 0
new double[3]();       // 0.0, 0.0, 0.0
new bool[3]();         // false, false, false
new char[3]();         // '\0', '\0', '\0'
new std::string[3]();  // "", "", ""
*/
