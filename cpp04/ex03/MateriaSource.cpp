/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:39:29 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/08 20:33:19 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		learnedMateria[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)  : IMateriaSource()
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		if(other.learnedMateria[i] == NULL)
			this->learnedMateria[i] = NULL;
		else
			this->learnedMateria[i] = other.learnedMateria[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < TOTAL_SLOT; i++)
		{
			if (this->learnedMateria[i])
				delete this->learnedMateria[i];
			if (other.learnedMateria[i] == NULL)
				this->learnedMateria[i] = NULL;
			else
				this->learnedMateria[i] = other.learnedMateria[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		if (this->learnedMateria[i])
			delete this->learnedMateria[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		if (learnedMateria[i] == NULL)
		{
			learnedMateria[i] = materia;
			std::cout << "Learned materia type " << learnedMateria[i]->getType() << std::endl; //test
			return;
		}
	}
}
/*
Returns a new Materia.
is a copy of the Materia previously learned by
the MateriaSource
whose type equals the one passed as parameter.
Returns 0 if the type is unknown.
*/
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (learnedMateria[i] && (learnedMateria[i]->getType() == type))
		{
			return (learnedMateria[i]->clone());
		}
	}
	std::cout << "Unknown type: " << type << std::endl;
	return NULL;
}

/*
MateriaSource must be able to learn "templates" of Materias to
create them when needed. 
Then, you will be able to generate a new Materia using just
a string that identifies its type.
*/
