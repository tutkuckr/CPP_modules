/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:37:41 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/02/20 10:36:19 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int			zombieAmount = 5;
	std::string	zombieName = "nup";
	int			i = 0;
	Zombie		*hoardZombie = zombieHorde(zombieAmount, zombieName);

	while (i < zombieAmount)
	{
		hoardZombie[i].announce();
		i++;
	}

	delete[] hoardZombie;
	return (0);
}
