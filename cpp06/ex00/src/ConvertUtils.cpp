/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:14:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 15:24:18 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

void printMessage(const Converted& results)
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

	std::cout << BLUE << "float: " << RESET 
			  << std::fixed << std::setprecision(1)
			  << results.floatConverted << "f" << std::endl;

	std::cout << BLUE << "double: " << RESET 
			 << results.doubleConverted << std::endl;
}

void convertIntToChar(Converted& results)
{
	if (!(results.intConverted >= 0 && results.intConverted <= 127)) // not in ascii table range
	{
		results.charImpossible = true;
	}
	else if (std::isprint(results.intConverted))
	{
		results.charConverted = static_cast<char>(results.intConverted);
	}
	else //non displayable
	{
		results.charNonDisplayable = true;
	}
}

/*
stoi
https://www.xqa.io/learn/cpp/intermediate/c-string-to-int-and-vice-versa
*/
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
checkDot()==0, checkFatEnd()==0, checkDigits()(all number)


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
