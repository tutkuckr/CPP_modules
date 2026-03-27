/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:13:50 by tutku             #+#    #+#             */
/*   Updated: 2026/03/27 22:12:42 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal ("cat")
{
	this->brain = new Brain();
	std::cout << "Created Cat class: " << type << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	this->brain = new Brain();
	std::cout << "Created Cat class: " << type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(NULL)
{
	*this = other;
	std::cout << "Copied class: " << type << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Assigned Cat class: " << type << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Destroyed Cat class" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (brain->getIdea(index));
}
