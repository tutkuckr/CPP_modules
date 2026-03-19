/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:23:50 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/19 06:01:28 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void separator(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========\n"
			  << std::endl;
}

int main()
{
	separator("Default construction");
	ScavTrap a;
	std::cout << "Name: " << a.getName() << std::endl;
	std::cout << "HP: " << a.getHitPts() << std::endl;
	std::cout << "Energy: " << a.getEnergyPts() << std::endl;
	std::cout << "Attack damage: " << a.getAttackDmg() << std::endl;

	separator("Named construction");
	ScavTrap b("Guardian");
	std::cout << "Name: " << b.getName() << std::endl;
	std::cout << "HP: " << b.getHitPts() << std::endl;
	std::cout << "Energy: " << b.getEnergyPts() << std::endl;
	std::cout << "Attack damage: " << b.getAttackDmg() << std::endl;

	separator("Special ability");
	b.guardGate();

	separator("Attack test");
	b.attack("bandit");
	b.attack("monster");

	separator("Take damage and repair");
	b.takeDamage(30);
	std::cout << "HP after damage: " << b.getHitPts() << std::endl;
	b.beRepaired(15);
	std::cout << "HP after repair: " << b.getHitPts() << std::endl;

	separator("Copy constructor");
	ScavTrap c(b);
	std::cout << "Copied Name: " << c.getName() << std::endl;
	std::cout << "Copied HP: " << c.getHitPts() << std::endl;
	std::cout << "Copied Energy: " << c.getEnergyPts() << std::endl;
	std::cout << "Copied Attack damage: " << c.getAttackDmg() << std::endl;

	separator("Assignment operator");
	ScavTrap d;
	d = b;
	std::cout << "Assigned Name: " << d.getName() << std::endl;
	std::cout << "Assigned HP: " << d.getHitPts() << std::endl;
	std::cout << "Assigned Energy: " << d.getEnergyPts() << std::endl;
	std::cout << "Assigned Attack damage: " << d.getAttackDmg() << std::endl;

	std::cout << "After self assignment, Name: " << d.getName() << std::endl;

	separator("Energy exhaustion");
	ScavTrap e("TiredOne");
	for (int i = 0; i < 52; i++)
		e.attack("training dummy");

	std::cout << "Remaining energy: " << e.getEnergyPts() << std::endl;

	separator("Death behavior");
	ScavTrap f("Fragile");
	f.takeDamage(200);
	std::cout << "HP after fatal damage: " << f.getHitPts() << std::endl;
	f.attack("enemy");
	f.beRepaired(10);
	f.guardGate();

	separator("Construction / destruction chaining");
	{
		ScavTrap temp("ScopedTrap");
		temp.attack("intruder");
		temp.guardGate();
		std::cout << "Leaving scope now..." << std::endl;
	}

	separator("End of main");
	return 0;
}

/*
	When ScavTrap is created:
		1.ClapTrap constructor
		2.ScavTrap constructor
	Destruction is reversed: (derived part depends on base part)
		1.ScavTrap destructor
		2.ScavTrap destructor

*/
