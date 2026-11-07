/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:05:53 by tutku             #+#    #+#             */
/*   Updated: 2026/11/07 17:20:07 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : numVar(0), doubleVar(0.0), strVar("")
{
}

Data::Data(const Data &other)
{
	(*this) = other;
}

Data &Data::operator=(const Data &other)
{
	if (this != (&other))
	{
		this->numVar = other.numVar;
		this->doubleVar = other.doubleVar;
		this->strVar = other.strVar;
	}
	return (*this);
}

Data::~Data()
{
	
}
