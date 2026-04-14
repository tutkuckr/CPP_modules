/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:27:57 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/14 14:12:12 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooLowException.hpp"

//GradeTooLowException::GradeTooLowException()
//{
	
//}

//GradeTooLowException::~GradeTooLowException()
//{

//}

//GradeTooLowException::GradeTooLowException(int grade) : _grade(grade)
//{
	
//}
GradeTooLowException::GradeTooLowException(int grade) : _grade(grade)
{
	_message = "Grade too low! " + std::to_string(getGrade());
}

const char *GradeTooLowException::what()
{
	return (_message.c_str());
}

int GradeTooLowException::getGrade()
{
	return (_grade);
}
