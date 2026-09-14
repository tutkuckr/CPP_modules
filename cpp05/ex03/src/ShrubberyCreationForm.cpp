/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:43:59 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/09/14 23:25:01 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
/*
Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory 
and writes ASCII trees inside it.
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target("ShrubberyCreationForm")
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(target)
{

}

void ShrubberyCreationForm::executeFormAction() const
{
	std::string fileName = _target + "_shrubbery";

	std::ofstream targetFile(fileName);
	if (targetFile.is_open())
	{
		targetFile << "          /\\\n"
					  "         /  \\          /\\\n"
					  "        /****\\        /  \\       /\\\n"
					  "       /******\\      /****\\     /  \\\n"
					  "      /********\\    /******\\   /****\\\n"
					  "          ||           ||        ||\n"
					  "          ||           ||        ||\n";
		targetFile.close();
	}
	else
	{
		std::cerr << "Error, could not open shrubbery file" << std::endl;
	}
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}
