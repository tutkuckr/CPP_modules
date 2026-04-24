/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:13:01 by tutku             #+#    #+#             */
/*   Updated: 2026/04/24 19:59:01 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("NoName"), _signed(false), _signGrade(150), _execGrade(150)
{
	
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

Form::~Form()
{

}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (!(bureaucrat.getGrade() <= this->getSignGrade()))
		throw GradeTooLowException();
	if (_signed)
		std::cout << "Form is already signed!" << std::endl;
	_signed = true;
}

int Form::getSignGrade() const
{
	return (_signGrade);
}

int Form::getExecGrade() const
{
	return (_execGrade);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_signed);
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
	os << "Name: " << other.getName() 
		<< "\nisSigned: " << other.getIsSigned()
		<< "\nSignGrade: " << other.getSignGrade()
		<< "\nExecGrade: " << (other.getExecGrade())
		<< std::endl;
	return (os);
}

const char *Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}


