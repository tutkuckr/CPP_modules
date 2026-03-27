/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:19:14 by tutku             #+#    #+#             */
/*   Updated: 2026/03/27 21:19:45 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Created brain class" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Copied brain class" << std::endl;
}

Brain &Brain::operator= (const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Assigned brain class" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Destroyed brain class" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return "<<wrong index entered>>";
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
	else
		std::cout << "Enter a valid index" << std::endl;
}
