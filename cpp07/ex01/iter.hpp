/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:55:57 by tutku             #+#    #+#             */
/*   Updated: 2026/11/13 03:22:08 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"

template <typename T> void iter(T* address, const size_t len, void(*function)(T&))
{
	std::cout << BLUE << "Parameter type: " << RESET << "non-const reference" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		function(address[i]);
	}
}

template <typename T>
void iter(const T *address, const size_t len, void (*function)(const T &))
{
	std::cout << BLUE << "Parameter type: " << RESET << "const reference" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		function(address[i]);
	}
}

#endif

/*
how to pass a function as a variable
example:
void process(int value, int (*func)(int)) {
	cout << "Result: " << func(value);
}
*/
