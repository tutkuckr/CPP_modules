/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:24:11 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/08 20:02:52 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

//base class -> parent - ICharacter
//derived class -> Character

ICharacter::ICharacter()
{

}

ICharacter::ICharacter(const ICharacter &)
{
	
}

ICharacter &ICharacter::operator=(const ICharacter &other)
{
	if (this != &other)
	{
		
	}
	return *this;
}
