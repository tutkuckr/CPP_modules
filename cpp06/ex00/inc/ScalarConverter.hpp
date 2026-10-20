/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:11:32 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 16:16:58 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <climits>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"

#define TEST_MODE 1 //Set it to 0 to disable testing

#define ERROR -1
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

struct Converted
{
	char			charConverted = 0;
	int				intConverted = 0;
	float			floatConverted = 0.0f;
	double			doubleConverted = 0.0;
	long long int	converted = 0;

	bool			charNonDisplayable = false;
	bool			charImpossible = false;
	bool			intImpossible = false;

	bool			hasDot = false;
	bool			hasF = false;
	bool			hasOnlyDigits = false; //?
};

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

// ========================CONVERTERS========================
void	convertChar(const std::string &literal, Converted &results);
void	convertInt(const std::string &literal, Converted &results);
void	convertFloat(const std::string &literal, Converted &results);
void	convertDouble(const std::string &literal, Converted &results);

// ========================CONVERT UTILS========================
void	convertIntToChar(Converted &results);

// ========================DETECT TYPES========================
bool	checkIfChar(const std::string &literal);
bool	checkIfFloat(const std::string &literal);
bool	checkIfInt(const std::string &literal);
bool	checkIfDouble(const std::string &literal);


// ========================PRINT MESSAGE========================
void	printMessage(const Converted &results);

#endif
