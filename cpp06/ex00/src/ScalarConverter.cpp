/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:16 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/06 14:23:29 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int detectType(const std::string& param)
{

	if (checkIfChar(param))
		return CHAR;
	if (checkIfFloat(param))
		return FLOAT;
	if (checkIfInt(param))
		return INT;
	if (checkIfDouble(param))
		return DOUBLE;
	return ERROR;
}

void ScalarConverter::convert(const std::string& literal)
{
	int type = detectType(literal);

	std::cout << "DEBUG:\nargv[1]: " << literal << std::endl;
	switch(type)
	{
		case CHAR:
			convertChar(literal);
			break;

		case INT:

		case FLOAT:

		case DOUBLE:

		default:
			std::cout << RED << "Invalid type!" << RESET << std::endl; //TODO: change later

	}

}

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
