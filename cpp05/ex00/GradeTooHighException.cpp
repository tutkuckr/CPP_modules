/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:16:47 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/14 14:25:27 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"

//GradeTooHighException::GradeTooHighException()
//{
	
//}

//GradeTooHighException::~GradeTooHighException()
//{

//}

GradeTooHighException::GradeTooHighException(int grade) : _grade(grade)
{
	_message = "Grade too high! " + std::to_string(getGrade());
}

const char *GradeTooHighException::what()
{
	return (_message.c_str());
}

int GradeTooHighException::getGrade()
{
	return (_grade);
}
