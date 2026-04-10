/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:55:49 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/10 17:17:30 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
Exceptions:

try - defines the code to test
throw - triggers an exception
catch - handles the error
*/

Bureaucrat::Bureaucrat()
{

}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

const std::string Bureaucrat::getName()
{
	return (_name);
}

int Bureaucrat::getGrade()
{
	return (_grade);
}

void Bureaucrat::incrementGrade(int amount)
{
	_grade -= amount;
	try
	{
		if (_grade < 1)
			throw "Bureaucrat::GradeTooHighException";
	}
	catch(const std::string err)
	{
		std::cerr << err << std::endl;
	}
}

void Bureaucrat::decrementGrade(int amount)
{
	_grade += amount;
	try
	{
		if (_grade > 150)
			throw "Bureaucrat::GradeTooLowException";
	}
	catch(const std::string err)
	{
		std::cerr << err << std::endl;
	}
	
}

