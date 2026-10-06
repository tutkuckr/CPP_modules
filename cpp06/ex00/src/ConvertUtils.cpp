/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:14:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/06 14:24:57 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//TODO: create one main printer function!
void convertChar(const std::string& param)
{
	std::cout << BLUE << "char literal: " << RESET << param << std::endl;
	
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
