/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:16 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 15:29:42 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int detectType(const std::string& literal)
{
	if (literal.empty())
		return ERROR;
	if (checkIfChar(literal))
		return CHAR;
	if (checkIfFloat(literal))
		return FLOAT;
	if (checkIfInt(literal))
		return INT;
	if (checkIfDouble(literal))
		return DOUBLE;
	//TODO: ADD CHECKER FOR NAN
	return ERROR;
}

void ScalarConverter::convert(const std::string& literal)
{
	int type = detectType(literal);
	Converted results;

	if (TEST_MODE)
		std::cout << GREEN << "Value entered: " << RESET << literal  << std::endl;
	switch(type)
	{
		case CHAR:
			if (TEST_MODE)
				std::cout << "Type is CHAR" << std::endl;
			convertChar(literal, results);
			break;

		case INT:
			if (TEST_MODE)
					std::cout << "Type is INT" << std::endl;
			convertInt(literal, results);
			break;

		case FLOAT:
			if (TEST_MODE)
					std::cout << "Type is FLOAT" << std::endl;
			convertFloat(literal, results);
			break;

		case DOUBLE:
			if (TEST_MODE)
				std::cout << "Type is DOUBLE" << std::endl;
			convertDouble(literal, results);
			break;

		default: //TODO: add cases for nan  etc.
			std::cerr << "Error: Invalid literal" << std::endl;
			return;
		}
	printMessage(results);
}

/*
0–31   → Non displayable
32–126 → displayable
127    → Non displayable
>127   → outside standard ASCII range
<0     → outside standard ASCII range
*/

/*
STEPS:
1. detect the type of the literal passed as a parameter
2. convert it from str to actual type
3. convert it explicitly to the three other data types
4. display thr results

- if wrong or overflows -> impossible
-handle numeric limits and special values
*/

/*
static member function:
https://www.geeksforgeeks.org/cpp/static-member-function-in-cpp/

ascii table:
https://www.ascii-code.com/

disable constructor usage
https://www.geeksforgeeks.org/cpp/explicitly-defaulted-deleted-functions-c-11/
*/
