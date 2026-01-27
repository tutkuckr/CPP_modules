/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:37:41 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/01/27 18:05:07 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name);
void	randomChump( std::string name);

Zombie*	newZombie( std::string name)
{
	Zombie zombie;

	zombie.setName("New Zombie");
	return (&zombie);
}

void	randomChump( std::string name)
{
	
}

int	main()
{
	Zombie *zombie;

	zombie = newZombie("Fooo");



	return (0);
}