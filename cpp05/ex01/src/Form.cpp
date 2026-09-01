/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:54:24 by tutku             #+#    #+#             */
/*   Updated: 2026/09/01 13:30:44 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :  _name("Form"),
				_signed(false),
				_signGrade(150),
				_executeGrade(150)
{

}

Form::Form(const Form &other) :  _name(other._name),
								 _signed(other._signed),
								 _signGrade(other._signGrade),
								 _executeGrade(other._executeGrade)
{
	
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

Form::Form(const std::string name, const int signGrade, const int execGrade) :  _name(name),
																				_signed(false),
																				_signGrade(signGrade),
																				_executeGrade(execGrade)
{
	if (_signGrade > 150 || _executeGrade > 150)
		throw GradeTooLowException();
	if (_signGrade < 1 || _executeGrade < 1)
		throw GradeTooHighException();
}

Form::~Form()
{

}

// ========================MEMBER FUNCTIONS========================
void Form::beSigned(Bureaucrat b)
{
	if (_signed)
	{
		std::cout << BLUE << "Form is already signed!" << RESET << std::endl;
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
const char *Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low!");
}

// ========================GETTERS========================

std::string Form::getName() const
{
	return _name;
}

bool Form::getSigned() const
{
	return _signed;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Name: " << form.getName()
	   << "\nisSigned: " << form.getSigned()
	   << "\nSignGrade: " << form.getSignGrade()
	   << "\nExecGrade: " << (form.getExecuteGrade())
	   << std::endl;
	return os;
}
