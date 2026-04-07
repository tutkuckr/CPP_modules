/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:59:00 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/07 15:31:24 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];

	public:
		Character();
		Character(std::string const &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
