/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:52:44 by tutku             #+#    #+#             */
/*   Updated: 2026/02/21 18:17:22 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *weapon;
		std::string name;

	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack();
};

#endif
