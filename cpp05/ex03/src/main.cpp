/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:12:37 by tutku             #+#    #+#             */
/*   Updated: 2026/09/14 23:29:19 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <sys/stat.h>

void expect(bool condition, const std::string &testName)
{
	if (condition)
		std::cout << GREEN << "[PASS] " << RESET << testName << std::endl;
	else
		std::cout << RED << "[FAIL] " << RESET << testName << std::endl;

	std::cout << std::endl;
}

static void testInternCreatesShrubbery()
{
	AForm *test = NULL;

	try
	{
		Intern intern;

		test = intern.makeForm(
			"shrubbery creation",
			"TEST");

		expect(
			test != NULL,
			"Intern creates shrubbery creation");
		expect(
			test->getName() == "ShrubberyCreationForm",
			"Intern creates correct Shrubbery form");

		delete test;
	}
	catch (const std::exception &e)
	{
		delete test;

		expect(false, "Intern creates shrubbery creation");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testInternCreatesRobotomy()
{
	AForm *test = NULL;

	try
	{
		Intern intern;

		test = intern.makeForm(
			"robotomy request",
			"TEST");

		expect(
			test != NULL,
			"Intern creates robotomy request");

		expect(
			test->getName() == "RobotomyRequestForm",
			"Intern creates correct Robotomy form");

		delete test;
	}
	catch (const std::exception &e)
	{
		delete test;

		expect(false, "Intern creates robotomy request");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testInternCreatesPresidential()
{
	AForm *test = NULL;

	try
	{
		Intern intern;

		test = intern.makeForm(
			"presidential pardon",
			"TEST");

		expect(
			test != NULL,
			"Intern creates presidential pardon");

		expect(
			test->getName() == "PresidentialPardonForm",
			"Intern creates correct Presidential form");

		delete test;
	}
	catch (const std::exception &e)
	{
		delete test;

		expect(false, "Intern creates presidential pardon");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testInternInvalidForm()
{
	try
	{
		Intern intern;

		AForm *test = intern.makeForm(
			"invalid form",
			"TEST");

		delete test;

		expect(false, "Intern rejects invalid form");
	}
	catch (const Intern::FormNotFoundException &e)
	{
		expect(true, "Intern rejects invalid form");

		std::cout << YELLOW
				  << e.what()
				  << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		expect(false, "Intern throws correct exception");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

int main ()
{
	if (EX03_TEST)
	{
		std::cout << GREEN << "\n=== EX02 Tests ===\n"
				  << RESET << std::endl;
		testInternCreatesShrubbery();
		testInternCreatesRobotomy();
		testInternCreatesPresidential();
		testInternInvalidForm();
	}
	return 0;
}
