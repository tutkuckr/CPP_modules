/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:24:17 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/03/11 15:26:18 by tcakir-y         ###   ########.fr       */
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
	~ClapTrap();								//destructor
	ClapTrap(const ClapTrap &other);			//copy constructor
	ClapTrap(std::string name);
	ClapTrap &operator=(const ClapTrap &other);	//copy assignment
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName();
};


#endif