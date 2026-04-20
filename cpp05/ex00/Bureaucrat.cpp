/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:55:49 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/20 17:24:32 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
Exceptions:

try - defines the code to test
throw - triggers an exception
catch - handles the error
*/

// no name, no grade
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{

}

// name and grade
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
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

void Bureaucrat::incrementGrade()
{

	std::cout << "Trying to increment grade.." << std::endl;
	if (_grade == 1)
		throw GradeTooHighException();
	_grade --;
	std::cout << "Grade incremented!" << std::endl;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "Trying to decrement grade.." << std::endl;
	if (_grade == 150)
		throw GradeTooLowException();
	_grade ++;
	std::cout << "Grade decremented!" << std::endl;
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
	os << other.getName() << ", bureaucrat grade " << (other.getGrade());
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

/*
overriding what() function:
https://stackoverflow.com/questions/66313527/c-overriding-exceptionwhat
https://www.geeksforgeeks.org/cpp/exceptionwhat-in-c-with-examples/
override: override a virtual function from the base class,
	compiler gives error if no matching virtual function is found in the base.
noexcept: tells compiler this function will never throw an exception
	also part of std::exception::what()
*/
