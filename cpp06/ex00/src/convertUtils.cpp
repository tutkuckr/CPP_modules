/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:14:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/09/22 13:55:27 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int checkIfChar(std::string param)
{
	if (param.length() == 1)
	{
		if (std::isprint(param[0]))
		{
			return CHAR;
			//std::cout << BLUE << "char literal: " << RESET << param << std::endl;
		}
		else
		{
			return ERROR;
			//std::cout << BLUE << "char: " << RESET << RED << " Non displayable" << RESET << std::endl;
		}
	}
	else
	{

	}
}

int detectType(std::string param)
{
	int type;

	
	
	return type;
}

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