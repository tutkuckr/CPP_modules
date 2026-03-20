/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 21:01:27 by tutku             #+#    #+#             */
/*   Updated: 2026/03/20 21:34:29 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap(); //default
		FragTrap(const FragTrap &other); //copy constructor
		FragTrap &operator=(const FragTrap &other); // copy assignment
		~FragTrap(); //destructor
		FragTrap(std::string name);

		void highFivesGuys(void);
		void printStatus();
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount);
		void attack(const std::string &target);
};

#endif
