/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printMessage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:48:35 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 15:52:37 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void printChar(const Converted& results)
{
	if (results.charImpossible)
	{
		std::cout << BLUE << "char: " << RESET
				  << "impossible" << std::endl;
	}
	else if (results.charNonDisplayable)
	{
		std::cout << BLUE << "char: " << RESET
				  << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << BLUE << "char: " << RESET 
				  << "'" << results.charConverted << "'" << std::endl;
	}
}

static void printInt(const Converted& results)
{
	if (results.intImpossible)
	{
		std::cout << BLUE << "int: " << RESET
				  << "impossible" << std::endl;
	}
	else
	{
		std::cout << BLUE << "int: " << RESET 
				  << results.intConverted << std::endl;
	}
}

static void printFloat(const Converted& results)
{
	std::cout << BLUE << "float: " << RESET 
			  << std::fixed << std::setprecision(1)
			  << results.floatConverted << "f" << std::endl;
}

static void printDouble(const Converted& results)
{
	std::cout << BLUE << "double: " << RESET 
			<< results.doubleConverted << std::endl;
}

void printMessage(const Converted& results)
{

	printChar(results);
	printInt(results);
	printFloat(results);
	printDouble(results);
}
