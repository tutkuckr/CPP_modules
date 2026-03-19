/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:24:17 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/19 05:18:18 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPts;			//health of Claptrap
		unsigned int energyPts;
		int attackDmg;

	public:
		ClapTrap();									//default constructor
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);			//copy constructor
		~ClapTrap();								//destructor
		ClapTrap &operator=(const ClapTrap &other);	//copy assignment

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		const std::string &getName() const;
		const unsigned int &getHitPts() const;
		const unsigned int &getEnergyPts() const;
		const int &getAttackDmg() const;
};


#endif
