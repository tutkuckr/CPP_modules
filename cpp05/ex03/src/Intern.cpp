/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 22:10:06 by tutku             #+#    #+#             */
/*   Updated: 2026/09/14 23:06:49 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// ========================CONSTRUCTORS============================

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator= (const Intern &other)
{
	(void)other;
	return *this;
}

// ========================MEMBER FUNCTIONS========================

void Intern::printMsg(std::string formName)
{
	std::cout << "Intern creates " << formName << std::endl;
}

int Intern::getFormIndex(std::string formName)
{
	std::string formNames[3] =
		{
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			return i;
		}
	}
	throw(FormNotFoundException());
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	int formIndex = getFormIndex(formName);

	switch (formIndex)
	{
		case 0:
			printMsg(formName);
			return new ShrubberyCreationForm(target);
		case 1:
			printMsg(formName);
			return new RobotomyRequestForm(target);
		case 2:
			printMsg(formName);
			return new PresidentialPardonForm(target);
		default:
			throw std::logic_error("Invalid form index");
	}
}

// ========================EXCEPTIONS==============================

const char* Intern::FormNotFoundException::what() const noexcept
{
	return ("Intern could not find the form!");
}
