/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printMessage.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:48:35 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/29 00:58:21 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void calcPrecision(Converted &results)
{
	size_t dot = results.literal.find('.');
	
	if (dot == std::string::npos)
	return;

	size_t i = dot + 1;
	int precision = 0;

	while (i < results.literal.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(results.literal[i])))
			break;
		i++;
		precision++;
	}
	if (precision > 0)
		results.precision = precision;
}

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
	// std::cout << BLUE << "float: " << RESET 
	// 		  << std::fixed << std::setprecision(1)
	// 		  << results.floatConverted << "f" << std::endl;
	std::cout << BLUE << "float: " << RESET;

	if (results.floatImpossible)
	{
		std::cout << "impossible" << std::endl;
		return;
	}

	if (results.pseudoSign == '+' && std::isinf(results.floatConverted))
		std::cout << "+";

	std::cout << std::fixed << std::setprecision(results.precision)
			  << results.floatConverted << "f" << std::endl;
}

static void printDouble(const Converted& results)
{
	// std::cout << BLUE << "double: " << RESET 
	// 		<< results.doubleConverted << std::endl;
	std::cout << BLUE << "double: " << RESET;

	if (results.doubleImpossible)
	{
		std::cout << "impossible" << std::endl;
		return;
	}

	if (results.pseudoSign == '+' && std::isinf(results.doubleConverted))
		std::cout << "+";

	std::cout << std::fixed << std::setprecision(results.precision) << results.doubleConverted << std::endl;
}

void printMessage(const Converted& results)
{
	printChar(results);
	printInt(results);
	printFloat(results);
	printDouble(results);
}
