/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:55:49 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/14 16:07:39 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
Exceptions:

try - defines the code to test
throw - triggers an exception
catch - handles the error
*/

Bureaucrat::Bureaucrat() : _name("noName"), _grade(150)
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

//noGrade
Bureaucrat::Bureaucrat(std::string const name) :  _name(name), _grade(150)
{
	
}

//noName
Bureaucrat::Bureaucrat(int grade) : _name("noName"), _grade(grade)
{
	try
	{
		if (_grade < 1)
			throw GradeTooHighException(getGrade());
		else if (_grade > 150)
			throw GradeTooLowException(getGrade());
		_grade = grade;
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << getGrade() << '\n';
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

//name and grade
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	try
	{
		_grade = 150;
		if (grade < 1)
			throw GradeTooHighException(grade);
		else if (grade > 150)
			throw GradeTooLowException(grade);
		_grade = grade;
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << getGrade() << '\n';
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == 1)
			throw GradeTooHighException(getGrade());
		_grade --;
	}
	catch(GradeTooHighException &e)
	{
		std::cerr << e.what() << getGrade() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Trying to decrement grade.." << std::endl;
	try
	{
		if (_grade == 150)
			throw GradeTooLowException(getGrade());
		_grade ++;
	}
	catch(GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

//operator for when the object is passed as a parameter
std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
	os << (other.getName() + ", bureaucrat grade " + std::to_string(other.getGrade()));
	return (os);
}
