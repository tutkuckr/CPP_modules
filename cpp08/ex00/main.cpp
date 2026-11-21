/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 04:13:50 by tutku             #+#    #+#             */
/*   Updated: 2026/11/21 05:49:03 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void check(bool condition, const std::string &message)
{
	if (condition)
		std::cout << GREEN << "[PASS] " << RESET << message << std::endl;
	else
		std::cout << RED << "[FAIL] " << RESET << message << std::endl;
}

template <typename T>
void testFound(T &container, int find, const std::string &message)
{
	try
	{
		auto it = easyfind(container, find);

		check((((*it) == find)), message);
	}
	catch(const std::exception& e)
	{
		check(false, message);
		std::cout << "Exception: " << e.what() << std::endl;
	}	
}

template <typename T>
void testNotFound(T &container, int find, const std::string &message)
{
	try
	{
		easyfind(container, find);
		check(false, message);
	}
	catch(const std::exception& e)
	{
		check(true, message);
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
}

int main()
{
	std::cout << CYAN << "\n===== VECTOR TESTS =====\n"
			  << RESET;

	std::vector<int> vec = {10, 20, 30, 40, 50};

	testFound(vec, 10, "Find first element");
	testFound(vec, 30, "Find middle element");
	testFound(vec, 50, "Find last element");
	testNotFound(vec, 99, "Value not present");

	//list == double linked list
	std::cout << CYAN << "\n===== LIST TESTS =====\n"
			  << RESET;

	std::list<int> lst = {5, 15, 25, 35};

	testFound(lst, 5, "Find first element");
	testFound(lst, 25, "Find middle element");
	testNotFound(lst, 100, "Value not present");

	// add and remove elements from both sides
	std::cout << CYAN << "\n===== DEQUE TESTS =====\n"
			  << RESET;

	std::deque<int> deq = {100, 200, 300};

	testFound(deq, 200, "Find middle element");
	testNotFound(deq, 400, "Value not present");

	std::cout << CYAN << "\n===== ARRAY TESTS =====\n"
			  << RESET;

	std::array<int, 5> arr = {1, 2, 3, 4, 5};

	testFound(arr, 3, "Find element in std::array");
	testNotFound(arr, 10, "Value not present");

	std::cout << CYAN << "\n===== DUPLICATE TESTS =====\n"
			  << RESET;

	std::vector<int> duplicates = {10, 20, 30, 20, 40};

	testFound(duplicates, 20, "Find FIRST occurrence of duplicate");

	std::cout << CYAN << "\n===== EMPTY CONTAINER TESTS =====\n"
			  << RESET;

	std::vector<int> emptyVec;
	std::list<int> emptyList;
	std::array<int, 0> emptyArr = {};

	testNotFound(emptyVec, 10, "Empty vector throws exception");
	testNotFound(emptyList, 10, "Empty list throws exception");
	testNotFound(emptyArr, 10, "Empty array throws exception");

	std::cout << CYAN << "\n===== SINGLE ELEMENT TESTS =====\n"
			  << RESET;

	std::vector<int> single = {42};

	testFound(single, 42, "Find only element");
	testNotFound(single, 10, "Missing value in single element container");

	return 0;
}
