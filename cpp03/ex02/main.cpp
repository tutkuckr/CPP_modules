/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:23:50 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/20 21:44:16 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

static void separator(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========\n"
			  << std::endl;
}

int main(void)
{
	separator("Default constructor");
	FragTrap a;
	std::cout << "Name: " << a.getName() << std::endl;
	std::cout << "HP: " << a.getHitPts() << std::endl;
	std::cout << "Energy: " << a.getEnergyPts() << std::endl;
	std::cout << "Attack damage: " << a.getAttackDmg() << std::endl;

	separator("Named constructor");
	FragTrap b("Fraggy");
	std::cout << "Name: " << b.getName() << std::endl;
	std::cout << "HP: " << b.getHitPts() << std::endl;
	std::cout << "Energy: " << b.getEnergyPts() << std::endl;
	std::cout << "Attack damage: " << b.getAttackDmg() << std::endl;

	separator("Attack test");
	b.attack("target_1");
	b.attack("target_2");

	separator("High five test");
	b.highFivesGuys();

	separator("Take damage and repair");
	b.takeDamage(25);
	b.beRepaired(10);

	separator("Copy constructor");
	FragTrap c(b);
	std::cout << "Copied Name: " << c.getName() << std::endl;
	std::cout << "Copied HP: " << c.getHitPts() << std::endl;
	std::cout << "Copied Energy: " << c.getEnergyPts() << std::endl;
	std::cout << "Copied Attack damage: " << c.getAttackDmg() << std::endl;

	separator("Copy assignment");
	FragTrap d;
	d = b;
	std::cout << "Assigned Name: " << d.getName() << std::endl;
	std::cout << "Assigned HP: " << d.getHitPts() << std::endl;
	std::cout << "Assigned Energy: " << d.getEnergyPts() << std::endl;
	std::cout << "Assigned Attack damage: " << d.getAttackDmg() << std::endl;

	separator("Death behavior");
	FragTrap e("Fragile");
	e.takeDamage(150);
	e.attack("enemy");
	e.beRepaired(10);
	e.highFivesGuys();

	separator("Energy exhaustion");
	FragTrap f("TiredFrag");
	for (int i = 0; i < 102; i++)
		f.attack("training_dummy");
	std::cout << "Remaining energy: " << f.getEnergyPts() << std::endl;
	f.highFivesGuys();
	f.beRepaired(5);

	separator("Construction / destruction chaining");
	{
		FragTrap temp("ScopedFrag");
		temp.attack("intruder");
		temp.highFivesGuys();
		std::cout << "Leaving scope now..." << std::endl;
	}

	separator("End of main");
	return (0);
}
