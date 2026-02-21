/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:51:59 by tutku             #+#    #+#             */
/*   Updated: 2026/02/21 18:25:22 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon club("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon club2("crude spiked club");
	HumanB jim("Jim");
	jim.attack(); //jim has no weapon message
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club");
	jim.attack();
	return (0);
}
