/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MandatoryFunctions.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 03:34:13 by tutku             #+#    #+#             */
/*   Updated: 2026/11/12 04:57:12 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MandatoryFunctions.hpp"

// randomly instantiates A, B, or C and returns the instance as a Base pointer.
Base *generate(void)
{
	int randomNum = rand() % 3;

	if (randomNum == 0)
		return (new A());
	else if (randomNum == 1)
		return (new B());
	return (new C());
}

// prints the actual type of the object pointed to by p
void identify(Base *p)
{
	if (p == NULL)
	{
		std::cout << RED << "Null pointer!" << RESET << std::endl;
		return;
	}
	if(dynamic_cast<A* >(p) != NULL)
	{
		std::cout << "Type: " << GREEN << "A" << RESET << std::endl;
		return;
	}
	if (dynamic_cast<B* >(p) != NULL)
	{
		std::cout << "Type: " << GREEN << "B" << RESET << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p) != NULL)
	{
		std::cout << "Type: " << GREEN << "C" << RESET << std::endl;
		return;
	}
	std::cout << RED << "Unknown type!" << RESET << std::endl;
}

// prints the actual type of the object referenced by p
// Using a pointer inside this function is forbidden.
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A& >(p);
		std::cout << "Type: " << GREEN << "A" << RESET << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		// Not A, continue checking
	}

	try
	{
		(void)dynamic_cast<B& >(p);
		std::cout << "Type: " << GREEN << "B" << RESET << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		// Not B, continue checking
	}

	try
	{
		(void)dynamic_cast<C& >(p);
		std::cout << "Type: " << GREEN << "C" << RESET << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		// Not C
		std::cout << RED << "Unknown type!" << RESET << std::endl;
	}
}
