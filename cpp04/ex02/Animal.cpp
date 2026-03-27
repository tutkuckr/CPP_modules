/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:56:41 by tutku             #+#    #+#             */
/*   Updated: 2026/03/22 20:01:40 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("**empty**")
{
	std::cout << "Created animal class with type: " << type << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Created animal class with type: " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Copied animal: " << type << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Assigned animal: " << type << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destroyed animal class" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Some animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
/*
with a virtual destructor, destruction happens like this:
** Dog::~Dog()
** Animal::~Animal()

Without a virtual destructor, it may do only:
** Animal::~Animal()

and skip the Dog part.
*/
/*
If a class has any virtual function, its destructor should be virtual too.
*/

/*
virtual = “this function can be replaced in children”
override = “I am replacing it here”

virtual matters when you use a base class pointer or reference
<<<<Animal* a = new Cat();
	a->makeSound();

	or

	Animal& a = c;
	a.makeSound();
>>>>

This only works properly when you call through:
a pointer
a reference
*/
