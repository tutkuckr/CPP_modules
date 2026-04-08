/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:59:00 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/08 20:05:33 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Floor.hpp"
#define TOTAL_SLOT 4

class Floor;
class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[TOTAL_SLOT];
		Floor dropped;

	public:
		Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();
		
		Character(std::string const &name);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void setInventoryToNull();
};

#endif

// base class -> parent - ICharacter
// derived class -> Character
