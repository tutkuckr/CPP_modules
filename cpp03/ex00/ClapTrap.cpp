/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:25:04 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/11 17:51:08 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	name = "NoName";
	hitPts = 10;
	energyPts = 10;
	attackDmg = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->name = other.name;
	this->hitPts = other.hitPts;
	this->energyPts = other.energyPts;
	this->attackDmg = other.attackDmg;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPts(10), energyPts(10), attackDmg(0)
{
	
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPts > 0 && hitPts != 0)
	{	
		std::cout << "ClapTrap " << name << " attacks " 
				<< target << ", causing 1 points of damage!" << std::endl;
		energyPts--;
	}
	else if (energyPts == 0 || hitPts == 0)
	{
		std::cout <<
			"No hit points or energy points left to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPts -= amount;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPts > 0 && hitPts != 0)
	{
		std::cout <<
			"Used 1 energy point to be repaired!" << std::endl;
		energyPts--;
	}
	else if (energyPts == 0 || hitPts == 0)
	{
		std::cout <<
			"No hit points or energy points left to be repaired!" << std::endl;
	}
}

std::string ClapTrap::getName()
{
	return (name);
}

/*
 ClapTrap attacks, it causes its target to lose <attack damage> hit points.

 ClapTrap repairs itself, it regains <amount> hit points. 

 Attacking and repairing each cost 1 energy point.
 
Of course, ClapTrap can’t do anything if it has no hit points or
energy points left.
*/