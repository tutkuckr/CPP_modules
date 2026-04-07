/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:07:12 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/07 13:41:31 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &other) : AMateria(other)
{
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice()
{

}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	//std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	AMateria::use(target);
}
