/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:52:10 by tutku             #+#    #+#             */
/*   Updated: 2026/02/21 18:23:12 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return (type);
}
void Weapon::setType(std::string type)
{
	this->type = type;
}
