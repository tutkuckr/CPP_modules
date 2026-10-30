/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:16 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/30 02:19:19 by tutku            ###   ########.fr       */
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
	if (checkIfPseudo(literal))
		return PSEUDO;
	// TODO: ADD CHECKER FOR NAN
	return ERROR;
}

bool calcSharedValue(const std::string &literal, Converted &results)
{
	try
	{	
		switch (results.type)
		{
			case CHAR:
				results.sharedValue = static_cast<unsigned char>(literal[0]);
				break;

			case INT:
				results.sharedValue = std::stold(literal);
				if (results.sharedValue == 0)
					results.sharedValue = 0;
				break;

			case FLOAT:
				results.sharedValue = std::stof(literal);
				break;

			case DOUBLE:
				results.sharedValue = std::stod(literal);
				break;

			case PSEUDO:
				if (literal.back() == 'f')
					results.sharedValue = std::stof(literal);
				else
					results.sharedValue = std::stod(literal);
				if (literal.front() == '+' || literal.front() == '-')
					results.pseudoSign = literal[0];
				break;

			default:
				std::cerr << "Error: Invalid literal" << std::endl;
				return false;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error:  Conversion impossible. ->" << e.what() << std::endl;
		return false;
	}
	return true;
}

void ScalarConverter::convert(const std::string &literal)
{
	Converted results;
	
	results.literal = literal;
	calcPrecision(results);
	results.type = detectType(literal);

	if (!calcSharedValue(literal, results))
	{
		results.charImpossible = true;
		results.intImpossible = true;
		results.floatImpossible = true;
		results.doubleImpossible = true;

		printMessage(results);
		return;
	}

	convertChar(results);
	convertInt(results);
	convertFloat(results);
	convertDouble(results);

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
