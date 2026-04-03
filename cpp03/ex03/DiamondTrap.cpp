/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:54:11 by tutku             #+#    #+#             */
/*   Updated: 2026/04/03 20:29:09 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
/*
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
• Hit points (FragTrap) -> 100
• Energy points (ScavTrap) -> 50
• Attack damage (FragTrap) -> 30
• attack() (ScavTrap)
*/
DiamondTrap::DiamondTrap() : ClapTrap("NoName_clap_name"),
	FragTrap("NoName"), ScavTrap("NoName")
{
	this->name = "NoName";
	this->hitPts = 100;
	this->energyPts = 50;
	this->attackDmg = 30;
	std::cout << "Created DiamondTrap: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
	FragTrap("NoName"), ScavTrap("NoName")
{
	this->name = name;
	this->hitPts = 100;
	this->energyPts = 50;
	this->attackDmg = 30;
	std::cout << "Created DiamondTrap: " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	FragTrap(other), ScavTrap(other)
{
	this->name = other.name;
	std::cout << "Copied DiamondTrap: " << this->name << std::endl;
}

DiamondTrap &DiamondTrap::operator= (const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other); // copies ClapTrap::name + stats
		this->name = other.name;	// copies DiamondTrap::name
	}
	std::cout << "Assigned DiamondTrap: " << this->name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destroyed DiamondTrap " << name << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target); // attackDmg = 20;
}

/*
https://www.freecodecamp.org/news/what-is-virtual-inheritance/
	ClapTrap.  ClapTrap
		\      /
   FragTrap   ScavTrap
		\      /
	  DiamondTrap
compiloer doesnt know which instance we are referring to -
or through ScavTrap or FragTrap

inherit virtually:
there will be only one instance of the base class
among the derived classes that virtually inherited it.

hierarchical class structure becomes:
		ClapTrap
		/      \
   FragTrap   ScavTrap
		\      /
	  DiamondTrap


***virtual public ClapTrap*** for FragTrap and ScavTrap
both FragTrap and ScavTrap share the same single ClapTrap base inside DiamondTrap.
class ScavTrap : virtual public ClapTrap
class FragTrap : virtual public ClapTrap
class DiamondTrap : public FragTrap, public ScavTrap

FragTrap and ScavTrap do not each create their own separate ClapTrap part
DiamondTrap ends up with one shared ClapTrap base
*/

