/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:38:04 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/02/20 09:56:09 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	memory allocated on stack
	constructor Zombie(std::string) runs
	object is ready
*/
void randomChump(std::string name)
{
	Zombie zombie(name);

	zombie.announce();
}

