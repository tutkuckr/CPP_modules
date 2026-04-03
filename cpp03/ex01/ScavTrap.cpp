/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 03:57:38 by tutku             #+#    #+#             */
/*   Updated: 2026/04/03 20:04:18 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("NoName")
{
	hitPts = 100;
	energyPts = 50;
	attackDmg = 20;
	std::cout << "Created ScavTrap: " << name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPts = 100;
	energyPts = 50;
	attackDmg = 20;
	std::cout << "Created ScavTrap: " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "Copied ScavTrap: " << name << std::endl;
}

// or ClapTrap::operator=(other);
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPts = other.hitPts;
		this->energyPts = other.energyPts;
		this->attackDmg = other.attackDmg;
	}
	std::cout << "Assigned ScavTrap: " << name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destroyed ScavTrap " << name << std::endl;
}

void ScavTrap::printStatus()
{
	if (energyPts == 0)
	{
		std::cout << "ScavTrap " << name << " is out of energy points!" << std::endl;
	}
	else if (hitPts == 0)
		std::cout << "ScavTrap " << name << " is dead!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << name << " has " << energyPts << " energy points left!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (energyPts > 0 && hitPts > 0)
	{
		std::cout << "Scavtrap " << name << " is now in Gate keeper mode!" << std::endl;
		energyPts--;
		printStatus();
		return;
	}
	printStatus();
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPts > 0 && hitPts > 0)
	{
		std::cout << "ScavTrap " << name << " attacks "
				  << target << ", causing " << attackDmg << " points of damage!" << std::endl;
		energyPts--;
		printStatus();
		return;
	}
	printStatus();
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hitPts == 0)
	{
		std::cout << "ScavTrap " << name << " is out of hit points" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " took " << amount << " points of damage!" << std::endl;
	if (amount >= hitPts)
		hitPts = 0;
	else
		hitPts -= amount;
	std::cout << "ScavTrap " << name << " has " << hitPts << " hit points left!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hitPts == 0)
	{
		std::cout << "ScavTrap " << name << " is out of hit points!" << std::endl;
		return;
	}
	else if (energyPts == 0)
	{
		std::cout << "ScavTrap " << name << " is out of energy points!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << name << " healed " << amount << " points!" << std::endl;
		energyPts--;
		std::cout << "ScavTrap " << name << " has " << energyPts << " energy points left!" << std::endl;
		hitPts += amount;
	}
}
