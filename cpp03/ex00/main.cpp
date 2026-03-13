/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:23:50 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/13 04:24:26 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// int main(void)
// {
// 	ClapTrap one("The One");
// 	ClapTrap two;

// 	one.attack(two.getName());
// 	return (0);
// }

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("First");
	ClapTrap b("Second");

	std::cout << "\n--- Attack test ---\n"
			  << std::endl;

	a.attack(b.getName());

	std::cout << "\n--- Damage test ---\n"
			  << std::endl;

	b.takeDamage(3);

	std::cout << "\n--- Repair test ---\n"
			  << std::endl;

	b.beRepaired(2);

	std::cout << "\n--- Attack test ---\n"
			  << std::endl;

	for (int i = 0; i < 12; i++)
		a.attack("Random"); //check

	std::cout << "\n--- Death test ---\n"
			  << std::endl;

	b.takeDamage(50);
	b.attack(a.getName());
	b.beRepaired(10);

	std::cout << "\n--- Copy constructor test ---\n"
			  << std::endl;

	ClapTrap c(a);

	std::cout << "\n--- Assignment operator test ---\n"
			  << std::endl;

	ClapTrap d("Fourth");
	d = b;

	std::cout << "\n--- Default constructor test ---\n"
			  << std::endl;
	ClapTrap e;

	std::cout << "\n--- End ---\n"
			  << std::endl;

	return 0;
}
