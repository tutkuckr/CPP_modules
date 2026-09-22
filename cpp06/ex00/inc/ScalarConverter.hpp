/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:32 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/09/22 13:16:15 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"

#define ERROR -1
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class ScalarConverter
{
	private:
		// ========================CONSTRUCTORS============================
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		// ========================MEMBER FUNCTIONS========================
		static void convert(std::string param);
};

int		detectType(std::string param);
void	checkChar(std::string param);



#endif