/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:24:17 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/13 03:53:46 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int hitPts;			//health of Claptrap
		int energyPts;
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
		const int &getHitPts() const;
		const int &getEnergyPtr() const;
		const int &getAttackDmg() const;
};


#endif
