/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:13:50 by tutku             #+#    #+#             */
/*   Updated: 2026/04/10 12:05:46 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal ("Cat")
{
	std::cout << "Created Cat class: " << type << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Created Cat class: " << type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Copied class: " << type << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Destroyed Cat class" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow Meow!" << std::endl;
}
