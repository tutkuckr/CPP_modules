/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:37:41 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/02/20 10:00:48 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *heapZombie = newZombie("HeapZombiee");
	heapZombie->announce();

	randomChump("StackZombie");

	delete heapZombie;
	return (0);
}

/*
	stackZombie is destroyed first,
	when randomChump function ends, stack object is destroyed automatically
	
	heapZombie lives until delete!
*/
