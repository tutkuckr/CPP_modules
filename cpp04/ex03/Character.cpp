/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:58:51 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/07 15:39:10 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("")
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(std::string const &name) : name(name)
{
	for (int i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	
}

//delete old inventory 
Character &Character::operator=(const Character &other) 
{
	if (this != &other)
	{
		
	}
	return (*this);
}

//Materias must be deleted when a Character is destroyed.
Character::~Character()
{

}

std::string const &Character::getName() const
{
	return (this->name);
}

// add a Materia to a full inventory -> nothing happens
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
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
		//inventory[idx]//copy this value to another object
	}
	else
		std::cout << "Wrong index! Nothing happened" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (!(idx < 0 || idx > 3))
	{
		inventory[idx]->use(target);
	}
	else
		std::cout << "Wrong index! Nothing happened" << std::endl;
}


/*
todo:
*character class's equip,unequip, use functions
*creation of garbage collector, free them later
*
*/