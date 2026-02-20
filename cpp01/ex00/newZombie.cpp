/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:38:08 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/02/20 09:57:46 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Allocates a Zombie on the heap
Zombie *newZombie(std::string name)
{
	Zombie *heapZombie = new Zombie(name);
	return (heapZombie);
}
