/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 17:13:50 by tutku             #+#    #+#             */
/*   Updated: 2026/03/27 22:11:44 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal ("dog")
{
	this->brain = new Brain();
	std::cout << "Created Dog class: " << type << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->brain = new Brain();
	std::cout << "Created Dog class: " << type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(NULL)
{
	*this = other;
	std::cout << "Copied class: " << type << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (this->brain != NULL)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	std::cout << "Assigned Dog class: " << type << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Destroyed Dog class" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof Woof!" << std::endl;
}

void Dog::setIdea(int index, const std::string &idea)
{
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}
