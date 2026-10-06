/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DetectTypeUtils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:24:36 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/06 16:24:10 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool checkIfChar(const std::string& param)
{
	int len = param.length();

	if (len == 1 && isprint(param[0]) && !isdigit(param[0]))
	{
		return true;
	}
	return false;
}

/*
	checkDot(), checkFatEnd()==1, checkDigits()
	in checkDigits()-> look for - and ignore at the beginning
*/
bool checkIfFloat(const std::string &param)
{
	if (checkDot(param)) //TODO:finish
	{
		return true;
	}
	return false;
}

bool checkIfInt(const std::string &param)
{
	if (checkDot(param)) //TODO:finish
	{
		return true;
	}
	return false;
}

bool checkIfDouble(const std::string &param)
{
	if (checkDot(param)) //TODO:finish
	{
		return true;
	}
	return false;
}
