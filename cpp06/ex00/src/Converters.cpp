/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:21:21 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/28 22:45:27 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <limits>
// https://www.reddit.com/r/cpp_questions/comments/uovfpt/detect_floating_point_overflow/

static bool isIntOverflow(Converted &results)
{
	long double value = std::trunc(results.sharedValue);

	return (value > INT_MAX || value < INT_MIN);
}

static bool isFloatOverflow(Converted &results)
{
	return (results.sharedValue > std::numeric_limits<float>::max() || results.sharedValue < std::numeric_limits<float>::lowest());
}

static bool isDoubleOverflow(Converted &results)
{
	return (results.sharedValue > std::numeric_limits<double>::max() || results.sharedValue < std::numeric_limits<double>::lowest());
}

void convertChar(Converted &results)
{
	if (!std::isfinite(results.sharedValue))
	{
		results.charImpossible = true;
		return;
	}

	long double value = std::trunc(results.sharedValue);

	if (!(value >= 0 && value <= 127))
	{
		results.charImpossible = true;
		return;
	}

	if (!std::isprint(static_cast<int>(value))) // non displayable
		results.charNonDisplayable = true;
	else
		results.charConverted = static_cast<char>(static_cast<int>(value));
}

void convertInt(Converted &results)
{
	if (!std::isfinite(results.sharedValue) || isIntOverflow(results))
	{
		results.intImpossible = true;
		return;
	}
	results.intConverted = static_cast<int>(results.sharedValue);
}

void convertFloat(Converted &results)
{
	if (std::isfinite(results.sharedValue) && isFloatOverflow(results))
	{
		results.floatImpossible = true;
		return;
	}
	results.floatConverted = static_cast<float>(results.sharedValue);
}

void convertDouble(Converted &results)
{
	if (std::isfinite(results.sharedValue) && isDoubleOverflow(results))
	{
		results.doubleImpossible = true;
		return;
	}
	results.doubleConverted = static_cast<double>(results.sharedValue);
}


// void convertChar(const std::string& literal, Converted& results)
// {
// 	char charVal = literal[0];
	
// 	if (!(results.intConverted >= 0 && results.intConverted <= 127)) // not in ascii table range
// 	{
// 		results.charImpossible = true;
// 	}
// 	else if (!(std::isprint(results.intConverted)))//non displayable
// 	{
// 		results.charNonDisplayable = true;
// 	}
// 	else
// 		results.charConverted = charVal;

// 	results.intConverted = static_cast<int>(charVal);
// 	results.floatConverted = static_cast<float>(charVal);
// 	results.doubleConverted = static_cast<double>(charVal);
// }

// void convertInt(const std::string &literal, Converted &results)
// {
// 	try
// 	{
// 		results.converted = std::stoll(literal);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "Error: " << e.what() << std::endl;

// 		results.charImpossible = true;
// 		results.intImpossible = true;

// 		//check float and double
// 		convertToFloat()
// 		return;
// 	}
// 	results.intConverted = results.converted;
// 	convertIntToChar(results);
// 	results.floatConverted = static_cast<float>(results.intConverted);
// 	results.doubleConverted = static_cast<double>(results.intConverted);
	
// }

// void convertFloat(const std::string &literal, Converted &results)
// {
	
// 	try
// 	{
// 		results.floatConverted = std::stof(literal);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 		results.floatImpossible = true;
// 	}
	
// }

// void convertDouble(const std::string &literal, Converted &results)
// {
// 	results.converted = std::stod(literal);
	
// }

