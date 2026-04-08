/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:58:51 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/08 20:49:12 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("")
{
	setInventoryToNull();
}

Character::Character(std::string const &name) : name(name)
{
	setInventoryToNull();
}

Character::Character(const Character &other) : name(other.name)
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		if (other.inventory[i] == NULL)
			this->inventory[i] = NULL;
		else
			this->inventory[i] = other.inventory[i]->clone(); //check
	}
}

//delete old inventory 
Character &Character::operator=(const Character &other)
{
	this->name = other.name;
	if (this != &other)
	{
		for (int i = 0; i < TOTAL_SLOT; i++)
		{
			if (this->inventory[i])
				delete inventory[i];
			this->inventory[i] = NULL;
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
		}
	}
	return (*this);
}

//Materias must be deleted when a Character is destroyed.
Character::~Character()
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	setInventoryToNull();
}

std::string const &Character::getName() const
{
	return (this->name);
}

// add a Materia to a full inventory -> nothing happens
void Character::equip(AMateria* m)
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Equipped " << inventory[i]->getType() << std::endl;
			return;
		}
	}
	std::cout << "Nothing happened, inventory already full!" << std::endl;
}

//save address before unequip
void Character::unequip(int idx)
{
	if (!(idx < 0 || idx > 3))
	{
		if (inventory[idx]) //copy value to floor object
		{
			dropped.drop(inventory[idx]);
			inventory[idx] = NULL;
		}
	}
	else
		std::cout << "Wrong index! Nothing happened" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (!(idx < 0 || idx > 3) && inventory[idx])
	{
		inventory[idx]->use(target);
	}
	else
		std::cout 
		<< "Wrong index or no materia found at idx! Nothing happened"
		<< std::endl;
}

void Character::setInventoryToNull()
{
	for (int i = 0; i < TOTAL_SLOT; i++)
	{
		inventory[i] = NULL;
	}
}

/*
todo:
*character class's unequip, use functions
*creation of garbage collector, free them later
*
*/
