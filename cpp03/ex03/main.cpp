/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:23:50 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/22 16:18:29 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << "===== Default constructor =====" << std::endl;
	DiamondTrap a;
	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;
	a.attack("target_dummy");
	std::cout << std::endl;
	a.ClapTrap::takeDamage(18);
	std::cout << std::endl;
	a.ClapTrap::beRepaired(10);
	std::cout << std::endl;

	std::cout << "===== Parameter constructor =====" << std::endl;
	DiamondTrap b("Ruby");
	std::cout << std::endl;
	b.whoAmI();
	std::cout << std::endl;
	b.attack("bandit");
	std::cout << std::endl;
	b.ClapTrap::takeDamage(30);
	std::cout << std::endl;
	b.ClapTrap::beRepaired(15);
	std::cout << std::endl;

	std::cout << "===== Copy constructor =====" << std::endl;
	DiamondTrap c(b);
	std::cout << std::endl;
	c.whoAmI();
	std::cout << std::endl;
	c.attack("copy_target");
	std::cout << std::endl;

	std::cout << "===== Copy assignment =====" << std::endl;
	DiamondTrap d("Temp");
	std::cout << std::endl;
	d.whoAmI();
	std::cout << std::endl;
	std::cout << "--- assigning d = b ---" << std::endl;
	d = b;
	std::cout << std::endl;
	d.whoAmI();
	std::cout << std::endl;
	d.attack("assigned_target");
	std::cout << std::endl;

	std::cout << "===== Parent special functions =====" << std::endl;
	b.highFivesGuys();
	std::cout << std::endl;
	b.guardGate();
	std::cout << std::endl;

	std::cout << "===== Energy / HP behavior =====" << std::endl;
	DiamondTrap e("Fighter");
	std::cout << std::endl;
	e.whoAmI();
	std::cout << std::endl;

	std::cout << "--- attacking multiple times ---" << std::endl;
	e.attack("enemy1");
	std::cout << std::endl;
	e.attack("enemy2");
	std::cout << std::endl;
	e.attack("enemy3");
	std::cout << std::endl;

	std::cout << "--- taking damage and repairing ---" << std::endl;
	e.ClapTrap::takeDamage(40);
	std::cout << std::endl;
	e.ClapTrap::beRepaired(20);
	std::cout << std::endl;
	e.ClapTrap::takeDamage(200);
	std::cout << std::endl;
	e.ClapTrap::beRepaired(10);
	std::cout << std::endl;

	std::cout << "===== End of tests =====" << std::endl;
	return (0);
}
