/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:14:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/09 23:20:56 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

void printMessage(const Converted& results)
{
	if (results.charNonDisplayable)
	{
		std::cout << BLUE << "char: " << RESET
				  << "Non displayable" << std::endl;
	}
	else if (results.charImpossible)
	{
		std::cout << BLUE << "char: " << RESET
				  << "impossible" << std::endl;
	}
	else
	{
		std::cout << BLUE << "char: " << RESET 
				  << "'" << results.charConverted << "'" << std::endl;
	}

	std::cout << BLUE << "int: " << RESET 
			  << results.intConverted << std::endl;

	std::cout << BLUE << "float: " << RESET 
			  << std::fixed << std::setprecision(1)
			  << results.floatConverted << "f" << std::endl;

	std::cout << BLUE << "double: " << RESET 
			 << results.doubleConverted << std::endl;
}

void convertChar(const std::string& literal, Converted& results)
{
	char charVal = literal[0];
	results.charConverted = charVal;
	results.intConverted = static_cast<int>(charVal);
	results.floatConverted = static_cast<float>(charVal);
	results.doubleConverted = static_cast<double>(charVal);
}

void convertInt(const std::string &literal, Converted &results)
{
	std::cout << "trying to convert int" << std::endl;
	try
	{
		results.intConverted = std::stoi(literal);
		std::cout << "int value" << results.intConverted << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "overflowwww" << std::endl;
		std::cerr << e.what() << '\n';
		return;
	}
	convertIntToChar(results);
	results.floatConverted = static_cast<float>(results.intConverted);
	results.doubleConverted = static_cast<double>(results.intConverted);
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
