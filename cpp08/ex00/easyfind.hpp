/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 03:39:33 by tutku             #+#    #+#             */
/*   Updated: 2026/11/21 05:40:09 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm> //for std::find(firstIt, lastIt(not included), value);
#include <deque>
#include <list>

template <typename T> typename T::iterator
easyfind(T& container, int find);

class NoOccurrenceException : public std::exception
{
	public:
		const char *what() const noexcept override;
};

const char *NoOccurrenceException::what() const noexcept
{
	return "No occureence found";
};

#include "easyfind.tpp"

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"
#endif

	/*
	Assuming T is a container of integers,
	this function has to find the first occurrence
	of the second parameter in the first parameter.
	*/

	/*
	https://hackingcpp.com/cpp/std/containers
	sequence containers
	1. array - Fixed-size array container
	2. vector - Dynamic array, contiguous memory *
	3. deque - Double-ended queue *
	4. list - Doubly linked list *
	5. forward list - Singly linked list
	*/

	/*
	resources

	https://www.w3schools.com/cpp/cpp_iterators.asp
	https://www.geeksforgeeks.org/cpp/iterators-c-stl/
	*/
