/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:21:21 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 15:30:06 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void convertChar(const std::string& literal, Converted& results)
{
	char charVal = literal[0];
	
	if (!(results.intConverted >= 0 && results.intConverted <= 127)) // not in ascii table range
	{
		results.charImpossible = true;
	}
	else if (!(std::isprint(results.intConverted)))//non displayable
	{
		results.charNonDisplayable = true;
	}
	else
		results.charConverted = charVal;

	results.intConverted = static_cast<int>(charVal);
	results.floatConverted = static_cast<float>(charVal);
	results.doubleConverted = static_cast<double>(charVal);
}

void convertInt(const std::string &literal, Converted &results)
{
	results.converted = std::stoll(literal);

	if (results.converted > INT_MAX || results.converted < INT_MIN) //int overflow
	{
		results.charImpossible = true;
		results.intImpossible = true;
		results.floatConverted = static_cast<float>(results.converted);
		results.doubleConverted = static_cast<double>(results.converted);
	}
	else
	{
		results.intConverted = results.converted;
		convertIntToChar(results);
		results.floatConverted = static_cast<float>(results.intConverted);
		results.doubleConverted = static_cast<double>(results.intConverted);
	}
}

void convertFloat(const std::string &literal, Converted &results)
{
	results.converted = std::stof(literal);
}

void convertDouble(const std::string &literal, Converted &results)
{
	results.converted = std::stod(literal);
	
}

