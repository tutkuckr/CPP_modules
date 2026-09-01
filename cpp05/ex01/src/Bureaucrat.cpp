/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:12:32 by tutku             #+#    #+#             */
/*   Updated: 2026/09/01 16:07:22 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// ========================CONSTRUCTORS============================

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

// ========================MEMBER FUNCTIONS========================

const std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	std::cout << PINK << "[BEFORE INCREMENT] " << RESET << *this << std::endl;
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << PINK << "[AFTER INCREMENT] " << RESET << *this << std::endl;
}

void Bureaucrat::decrementGrade()
{
	std::cout << PINK << "[BEFORE DECREMENT] " << RESET << *this << std::endl;
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << PINK << "[AFTER DECREMENT] " << RESET << *this << std::endl;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		bool isSigned = form.getSigned();
		form.beSigned(*this);
		
		if (!isSigned)
		{
			std::cout << getName()
					  << " signed "
					  << form.getName()
					  << std::endl;
		}
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << this->getName()
				  << " couldn't sign " 
				  << form.getName()
				  << " because "
				  << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName()
				  << " couldn't sign " 
				  << form.getName()
				  << " because "
				  << e.what() << '\n';
	}
}

// ========================EXCEPTIONS==============================

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", " << "bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
