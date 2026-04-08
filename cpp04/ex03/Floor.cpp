/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:36:39 by tutku             #+#    #+#             */
/*   Updated: 2026/04/08 19:55:08 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : totalDropped(0)
{
	setDroppedToNull();
}

Floor::Floor(const Floor &other)
{
	*this = other;
}

Floor &Floor::operator=(const Floor &other)
{
	if (this != &other)
	{
		deleteDropped();
		this->totalDropped = other.totalDropped;
		for (int i = 0; i < TOTAL_DROP; i++)
		{
			if (other.dropped[i])
				this->dropped[i] = other.dropped[i]->clone();
		}
	}
	return (*this);
}

Floor::~Floor()
{
	deleteDropped();
}

void Floor::deleteDropped()
{
	for (int i = 0; i < TOTAL_DROP; i++)
	{
		if (dropped[i])
		{
			delete dropped[i];
		}
	}
	setDroppedToNull();
	totalDropped = 0;
}

void Floor::drop(AMateria *materia)
{
	if (totalDropped == TOTAL_DROP) //no space left to drop
	{
		deleteDropped();
	}
	for (int i = 0; i < TOTAL_DROP; i++) //copy materia to first free space
	{
		if (dropped[i] == NULL)
		{
			dropped[i] = materia;
			totalDropped++;
			return;
		}
	}
}

void Floor::setDroppedToNull()
{
	for (int i = 0; i < TOTAL_DROP; i++)
	{
		dropped[i] = NULL;
	}
}
