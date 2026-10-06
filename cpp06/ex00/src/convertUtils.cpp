/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:14:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/05 01:23:13 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//TODO: create one main printer function!
void convertChar(const std::string& param)
{
	std::cout << BLUE << "char literal: " << RESET << param << std::endl;
	
}

bool checkIfChar(const std::string& param)
{
	int len = param.length();

	if (len == 1 && isprint(param[0]) && !isdigit(param[0]))
	{
		return true;
	}
	return false;
}

bool checkIfFloat(const std::string &param)
{
	

	if ()
	{
		return true;
	}
	return false;
}

int detectType(const std::string& param)
{

	if (checkIfChar(param))
		return CHAR;
	if (checkIfFloat(param))
		return FLOAT;
	return ERROR;
}

/*
how to check for
*****
char?
-len == 1, isprint() == 1, !isdigit()
*****
float?
checkDot(), checkFatEnd()==1, checkDigits()
	in checkDigits()-> look for - and ignore at the beginning
*****
double?
checkDot(), checkFatEnd()==0, checkDigits()
	in checkDigits()-> look for - and ignore at the beginning
******
int
checkSign() -> + -
checkDot()==0, checkFatEnd()==0, checkDigits()


input 65
char:   'A'
int:    65
float:  65.0f
double: 65.0

input 42
char   → '*'
int    → 42
float  → 42.0f
double → 42.0

valid and printable     → 'A'
valid but non-printable → Non displayable
cannot become char      → impossible

starts with optional sign? yes/no
digits? yes
decimal point? yes
digits after point? yes
ends with f? yes

→ FLOAT
*/

//void checkChar(std::string param)
//{
//	if (param.length() == 1)
//	{
//		if (std::isprint(param[0]))
//		{
//			std::cout << BLUE << "char literal: " << RESET << param << std::endl;
//		}
//		else
//		{
//			std::cout << BLUE << "char: " << RESET << RED << " Non displayable" << RESET << std::endl;
//		}
//	}
//	else
//	{

//	}
//}
