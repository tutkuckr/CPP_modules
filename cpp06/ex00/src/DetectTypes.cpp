/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DetectTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:24:36 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 15:54:23 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool checkIfChar(const std::string& literal)
{
	int len = literal.length();

	if (len == 1 && isprint(literal[0]) && !isdigit(literal[0]))
	{
		return true;
	}
	return false;
}

/*
	checkDot(), checkFatEnd()==1, checkDigits()
	in checkDigits()-> look for - and ignore at the beginning
*/
bool checkIfFloat(const std::string &literal)
{
	if (literal.empty())
		return false;
	if (literal.back() == 'f' || literal.back() == 'F')
		return true;
	return false;
}

bool checkIfInt(const std::string &literal)
{
	size_t len = literal.length();
	size_t i = 0;

	if (len == 0)
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == len)
		return false;

	while (i < literal.length())
	{
		if (!isdigit(static_cast<unsigned char>(literal[i])))
			return false;
		i++;
	}
	return true;
}

bool checkIfDouble(const std::string &literal)
{
	if (literal.empty())
		return false;
	return true;
}
