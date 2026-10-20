/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DetectTypes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:24:36 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 17:05:11 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool checkIfChar(const std::string& literal)
{
	size_t len = literal.length();

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
	size_t i = 0;
	bool hasDot = false;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length() - 1)
	{
		if (!isdigit(static_cast<unsigned char>(literal[i])))
		{
			if (literal[i] == '.')
			{
				if (hasDot)
					return false;
				hasDot = true;
			}
			else
				return false;
		}
		i++;
	}
	if (literal[i] == 'f' || literal[i] == 'F')
	{	
		if (hasDot)
			return true;
	}
	return false;
}

bool checkIfInt(const std::string &literal)
{
	size_t i = 0;

	if (literal.length() == 0)
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
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
	size_t i = 0;
	bool hasDot = false;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (!isdigit(static_cast<unsigned char>(literal[i])))
		{
			if (literal[i] == '.')
			{
				if (hasDot)
					return false;
				hasDot = true;
			}
			else
				return false;
		}
		i++;
	}
	return true;
}
