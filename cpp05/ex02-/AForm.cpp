/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:13:01 by tutku             #+#    #+#             */
/*   Updated: 2026/04/24 20:23:57 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("NoName"), _signed(false), _signGrade(150), _execGrade(150)
{
	
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm()
{

}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (!(bureaucrat.getGrade() <= this->getSignGrade()))
		throw GradeTooLowException();
	if (_signed)
		std::cout << "Form is already signed!" << std::endl;
	_signed = true;
}

int AForm::getSignGrade() const
{
	return (_signGrade);
}

int AForm::getExecGrade() const
{
	return (_execGrade);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_signed);
}

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
	os << "Name: " << other.getName() 
		<< "\nisSigned: " << other.getIsSigned()
		<< "\nSignGrade: " << other.getSignGrade()
		<< "\nExecGrade: " << (other.getExecGrade())
		<< std::endl;
	return (os);
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}


