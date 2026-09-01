/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:54:24 by tutku             #+#    #+#             */
/*   Updated: 2026/09/01 16:23:49 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() :  _name("AForm"),
				_signed(false),
				_signGrade(150),
				_executeGrade(150)
{

}

AForm::AForm(const AForm &other) :  _name(other._name),
								 _signed(other._signed),
								 _signGrade(other._signGrade),
								 _executeGrade(other._executeGrade)
{
	
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) :  _name(name),
																				_signed(false),
																				_signGrade(signGrade),
																				_executeGrade(execGrade)
{
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
}

AForm::~AForm()
{

}

// ========================MEMBER FUNCTIONS========================
void AForm::beSigned(Bureaucrat b)
{
	if (_signed)
	{
		std::cout << YELLOW << "Form is already signed!" << RESET << std::endl;
	}
	else if(b.getGrade() <= _signGrade)
	{
		this->_signed = true;
	}
	else if(b.getGrade() > _signGrade)
	{
		throw GradeTooLowException();
	}
}

// ========================EXCEPTIONS========================
const char *AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

// ========================GETTERS========================

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Name: " << form.getName()
	   << "\nisSigned: " << form.getSigned()
	   << "\nSignGrade: " << form.getSignGrade()
	   << "\nExecGrade: " << (form.getExecuteGrade())
	   << std::endl;
	return os;
}
