/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:01:20 by tutku             #+#    #+#             */
/*   Updated: 2026/03/20 21:39:40 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("NoName")
{
	hitPts = 100;
	energyPts = 100;
	attackDmg = 30;
	std::cout << "Created FragTrap: " << name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPts = 100;
	energyPts = 100;
	attackDmg = 30;
	std::cout << "Created FragTrap: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "Copied FragTrap: " << name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPts = other.hitPts;
		this->energyPts = other.energyPts;
		this->attackDmg = other.attackDmg;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destroyed FragTrap " << name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (hitPts == 0)
	{
		std::cout << "FragTrap " << name << " is out of hit points!" << std::endl;
		return;
	}
	else if (energyPts == 0)
	{
		std::cout << "FragTrap " << name << " is out of energy points!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << name << " is giving high-fives!"<< std::endl;
		energyPts--;
		std::cout << "FragTrap " << name << " has " << energyPts << " energy points left!" << std::endl;
	}
}

void FragTrap::printStatus()
{
	if (energyPts == 0)
	{
		std::cout << "FragTrap " << name << " is out of energy points!" << std::endl;
	}
	else if (hitPts == 0)
		std::cout << "FragTrap " << name << " is dead!" << std::endl;
	else
	{
		std::cout << "FragTrap " << name << " has " << energyPts << " energy points left!" << std::endl;
	}
}

void FragTrap::attack(const std::string &target)
{
	if (energyPts > 0 && hitPts > 0)
	{
		std::cout << "FragTrap " << name << " attacks "
				  << target << ", causing " << attackDmg << " points of damage!" << std::endl;
		energyPts--;
		printStatus();
		return;
	}
	printStatus();
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hitPts == 0)
	{
		std::cout << "FragTrap " << name << " is out of hit points" << std::endl;
		return;
	}
	std::cout << "FragTrap " << name << " took " << amount << " points of damage!" << std::endl;
	if (amount >= hitPts)
		hitPts = 0;
	else
		hitPts -= amount;
	std::cout << "FragTrap " << name << " has " << hitPts << " hit points left!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hitPts == 0)
	{
		std::cout << "FragTrap " << name << " is out of hit points!" << std::endl;
		return;
	}
	else if (energyPts == 0)
	{
		std::cout << "FragTrap " << name << " is out of energy points!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << name << " healed " << amount << " points!" << std::endl;
		energyPts--;
		std::cout << "FragTrap " << name << " has " << energyPts << " energy points left!" << std::endl;
		hitPts += amount;
	}
}
