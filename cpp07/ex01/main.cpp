/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:55:22 by tutku             #+#    #+#             */
/*   Updated: 2026/11/13 03:28:28 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T> void printElement(const T& element)
{
	std::cout << element << " ";
}

template <typename T> void increment(T& element)
{
	element++;
}

template <typename T> void addEmoji(T& element)
{
	element += "!";
}

void printTitle(const std::string &title)
{
	std::cout << "\n"
			  << "========================================\n"
			  << title << "\n"
			  << "========================================\n";
}

void expect(bool condition, const std::string &msg)
{
	if (condition)
		std::cout << GREEN << "[PASS]" << RESET
				  << " " << msg << std::endl;
	else
		std::cout << RED << "[FAIL]" << RESET
				  << " " << msg << std::endl;
}

void testInt()
{
	printTitle("INTEGER ARRAY TESTS");

	int arr[] = {1, 2, 3, 4, 5};
	size_t arrLen = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Expected: 1 2 3 4 5" << std::endl;
	::iter(arr, arrLen, printElement<int>);
	std::cout << "\n\n";

	std::cout << "Incrementing every element..." << std::endl;
	::iter(arr, arrLen, increment<int>);

	std::cout << "Expected: 2 3 4 5 6" << std::endl;
	::iter(arr, arrLen, printElement<int>);
	std::cout << std::endl;

	expect(arr[0] == 2 && arr[1] == 3 && arr[2] == 4 && arr[3] == 5 && arr[4] == 6,
		   "Array elements were modified");
}

void testString()
{
	printTitle("STRING ARRAY TESTS");

	std::string arr[] = {"Hello", "World", "Codam"};
	size_t arrLen = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Expected: Hello World Codam" << std::endl;
	::iter(arr, arrLen, printElement);
	std::cout << "\n\n";

	std::cout << "Adding ! to every string..." << std::endl;
	::iter(arr, arrLen, addEmoji);
	std::cout << "\n\n";

	std::cout << "Expected: Hello! World! Codam!" << std::endl;
	::iter(arr, arrLen, printElement);
	std::cout << "\n\n";

	expect(arr[0] == "Hello!" && arr[1] == "World!" && arr[2] == "Codam!", "All elements in array were modified!");
}

void testConstArray()
{
	printTitle("CONST ARRAY TESTS");

	const int arr[] = {10, 20, 30};
	size_t arrLen = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Expected: 10 20 30" << std::endl;
	::iter(arr, arrLen, printElement<int>);
	std::cout << std::endl;

	expect(arr[0] == 10 && arr[1] == 20 && arr[2] == 30,
		   "Const int array test");

	std::cout << "\n";

	const std::string words[] = {"Hello", "World"};
	size_t wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "Expected: Hello World" << std::endl;
	::iter(words, wordsLen, printElement<std::string>);
	std::cout << std::endl;

	expect(words[0] == "Hello" && words[1] == "World",
		   "Const str array test");
}

void testOtherCases()
{
	printTitle("SOME OTHER TESTS");

	std::cout << "--- Single element array ---" << std::endl;

	int single[] = {42};

	::iter(single, 1, increment<int>);

	std::cout << "Expected: 43" << std::endl;
	::iter(single, 1, printElement<int>);
	std::cout << std::endl;

	expect(single[0] == 43,
		   "Single element is incremented");

	std::cout << "\n--- Zero length ---" << std::endl;

	int arr[] = {1, 2, 3};

	::iter(arr, 0, increment<int>);

	expect(arr[0] == 1 && arr[1] == 2 && arr[2] == 3,
		   "Zero length: no element is modified");

	std::cout << "\n--- Partial array ---" << std::endl;

	int partial[] = {1, 2, 3, 4, 5};

	::iter(partial, 2, increment<int>);

	std::cout << "Expected: 2 3 3 4 5" << std::endl;
	::iter(partial, 5, printElement<int>);
	std::cout << std::endl;

	expect(partial[0] == 2 && partial[1] == 3 && partial[2] == 3 && partial[3] == 4 && partial[4] == 5,
		   "Only the first two elements are modified");

	std::cout << "\n--- Multiple iteration ---" << std::endl;

	int repeated[] = {1, 2, 3};

	::iter(repeated, 3, increment<int>);
	::iter(repeated, 3, increment<int>);

	std::cout << "Expected: 3 4 5" << std::endl;
	::iter(repeated, 3, printElement<int>);
	std::cout << std::endl;

	expect(repeated[0] == 3 && repeated[1] == 4 && repeated[2] == 5,
		   "Array is incremented twice");
}

int main()
{
	testInt();
	testString();
	testConstArray();
	testOtherCases();

	return 0;
}
