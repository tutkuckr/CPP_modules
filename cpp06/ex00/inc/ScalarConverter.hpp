/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:32 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/06 14:22:41 by tcakir-y         ###   ########.fr       */
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
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;

	public:
		// ========================MEMBER FUNCTIONS========================
		static void convert(const std::string& literal);
};

// ========================CONVERT UTILS========================
void	convertChar(const std::string &literal);
bool	checkIfChar(const std::string& param);
bool	checkIfFloat(const std::string &param);
bool	checkIfInt(const std::string &param);
bool	checkIfDouble(const std::string &param);

#endif
