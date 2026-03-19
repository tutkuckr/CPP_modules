/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 03:57:25 by tutku             #+#    #+#             */
/*   Updated: 2026/03/19 05:04:47 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:


	public:
		ScavTrap(); //default constructor
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other); //copy constructor
		ScavTrap &operator=(const ScavTrap &other);//copy assignment
		~ScavTrap(); //destructor

		void guardGate();
		void attack(const std::string &target); //same from claptrap but different message
		void printStatus();
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount);
};

#endif
