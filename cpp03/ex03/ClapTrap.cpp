/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:25:04 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/22 16:13:48 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name("NoName"),
	  hitPts(10),
	  energyPts(10),
	  attackDmg(0)
{
	std::cout << "Created ClapTrap: " << name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: name(name),
	  hitPts(10),
	  energyPts(10),
	  attackDmg(0)
{
	std::cout << "Created ClapTrap: " << name << std::endl;
}

//or *this = other -> by using copy assignment operator
ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPts(other.hitPts),
	  energyPts(other.energyPts),
	  attackDmg(other.attackDmg)
{
	std::cout << "Copied ClapTrap: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroyed ClapTrap: " << name << std::endl;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPts = other.hitPts;
		this->energyPts = other.energyPts;
		this->attackDmg = other.attackDmg;
	}
	std::cout << "Assigned ClapTrap: " << name << std::endl;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPts == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy points!" << std::endl;
	}
	else if (hitPts == 0)
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
	else
	{	
		std::cout << "ClapTrap " << name << " attacks " 
				<< target << ", causing " << attackDmg << " points of damage!" << std::endl;
		energyPts--;
		std::cout << "ClapTrap " << name << " has " << energyPts << " energy points left!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPts == 0)
	{
		std::cout << "ClapTrap " << name << " is out of hit points" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
	if (amount >= hitPts)
		hitPts = 0;
	else
		hitPts -= amount;
	std::cout << "ClapTrap " << name << " has " << hitPts << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPts == 0)
	{
		std::cout << "ClapTrap " << name << " is out of hit points!" << std::endl;
		return;
	}
	if (energyPts == 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy points!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name <<
			" healed " << amount << " points!" << std::endl;
		energyPts--;
		std::cout << "ClapTrap " << name << " has " << energyPts << " energy points left!" << std::endl;
		hitPts += amount;
		std::cout << "ClapTrap " << name << " has " << hitPts << " hit points left!" << std::endl;
	}
}

const std::string &ClapTrap::getName() const
{
	return (name);
}

const unsigned int &ClapTrap::getHitPts() const
{
	return (hitPts);
}

const unsigned int &ClapTrap::getEnergyPts() const
{
	return (energyPts);
}

const int &ClapTrap::getAttackDmg() const
{
	return (attackDmg);
}

/*
 ClapTrap attacks, it causes its target to lose <attack damage> hit points.

 ClapTrap repairs itself, it regains <amount> hit points. 

 Attacking and repairing each cost 1 energy point.
 
Of course, ClapTrap can’t do anything if it has no hit points or
energy points left.
*/
