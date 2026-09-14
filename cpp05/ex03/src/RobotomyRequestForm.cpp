/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:15:02 by tutku             #+#    #+#             */
/*   Updated: 2026/09/14 21:44:52 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC), _target("Default Robotomy Target")
{

}

RobotomyRequestForm ::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC), _target(target)
{
	
}

void RobotomyRequestForm::executeFormAction() const
{
	std::cout << "~ drilling noise ~" << std::endl;
	
	if (std::rand() % 2 == 1)
		std::cout << this->_target << " successfully robotomized" << std::endl;
	else
		std::cout << this->_target << " robotomy failed!" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

int RobotomyRequestForm::getSign() const
{
	return this->getSignGrade();
}

int RobotomyRequestForm::getExec() const
{
	return this->getExecuteGrade();
}
