/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:16 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/09/22 17:11:48 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//ScalarConverter::ScalarConverter(const ScalarConverter &other)
//{
//	(*this) = other;
//}

//ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
//{
//	(void)other;
//	return (*this);
//}

//ScalarConverter::~ScalarConverter()
//{

//}

void ScalarConverter::convert(const std::string& param)
{
	int type = detectType(param);

	std::cout << "DEBUG:\nargv[1]: " << param << std::endl;
	switch(type)
	{
		case CHAR:
			printChar(param);
			return;

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