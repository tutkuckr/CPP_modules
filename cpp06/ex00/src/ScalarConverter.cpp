/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:16 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/09 18:50:03 by tutku            ###   ########.fr       */
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
	return ERROR;
}

void ScalarConverter::convert(const std::string& literal)
{
	int type = detectType(literal);
	Converted results;

	switch(type)
	{
		case CHAR:
			convertChar(literal, results);
			break;

		case INT:
			convertInt(literal, results);
			break;

		case FLOAT:
			break;

		case DOUBLE:
			break;

		default:
			std::cout << "default" << std::endl;
			break;
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
