/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:18:06 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/09/22 17:02:35 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		std::cout << RED << "Please enter input!" << RESET << std::endl;
		return 1;
	}
	
	std::string param(argv[1]);
	ScalarConverter::convert(param);
	
	return 0;
}