/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:14:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/09/22 17:12:23 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//TODO: create one main printer function!
void printChar(const std::string& param)
{
	std::cout << BLUE << "char literal: " << RESET << param << std::endl;
	
}

int detectType(const std::string& param)
{
	int len = param.length();

	if (len == 1 && isprint(param[0]) && !isdigit(param[0]))
	{
		return CHAR;
	}
	return ERROR;
	
	
}

/*
how to check for char?

-len == 1, isprint() == 1, !isdigit()

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