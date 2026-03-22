/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:33:04 by tutku             #+#    #+#             */
/*   Updated: 2026/03/22 19:43:10 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("wrong cat")
{
	std::cout << "Created Wrong Cat class: " << type << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "Created Wrong Cat class: " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copied class: " << type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destroyed Wrong Cat class" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow Meow!" << std::endl;
}
