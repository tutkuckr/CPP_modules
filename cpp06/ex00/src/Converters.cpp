/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 15:21:21 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/30 02:09:17 by tutku            ###   ########.fr       */
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
