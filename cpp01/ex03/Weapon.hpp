/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:51:52 by tutku             #+#    #+#             */
/*   Updated: 2026/02/21 16:43:55 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon 
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string& getType();
		void setType(std::string type);
};

#endif
