/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:52:33 by tutku             #+#    #+#             */
/*   Updated: 2026/02/21 18:17:42 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &weapon;
		std::string name;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
};

#endif
