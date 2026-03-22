/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:13:50 by tutku             #+#    #+#             */
/*   Updated: 2026/03/22 19:21:38 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal ("dog")
{
	std::cout << "Created Dog class: " << type << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Created Dog class: " << type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Copied class: " << type << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Destroyed Dog class" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof Woof!" << std::endl;
}
