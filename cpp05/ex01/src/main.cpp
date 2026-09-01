/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:12:37 by tutku             #+#    #+#             */
/*   Updated: 2026/09/01 16:15:40 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

void expect(bool condition, const std::string &testName)
{
	if (condition)
		std::cout << GREEN << "[PASS] " << RESET << testName << std::endl;
	else
		std::cout << RED << "[FAIL] " << RESET << testName << std::endl;

	std::cout << std::endl;
}

static void testDefaultConstructor()
{
	try
	{
		Form a;
		std::cout << a << std::endl;

		expect(((a.getName() == "Form") 
			 && (a.getExecuteGrade() == 150) 
			 && (a.getSignGrade()) == 150)
			 && (a.getSigned() != true), "default form created");
	}
	catch (const std::exception &e)
	{
		expect(false, "default form created");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testCopyConstructor()
{
	Form b("TEST", 35, 45);
	std::cout << b << std::endl;
	try
	{
		std::cout << "Copying form.." << std::endl;
		Form copy(b);
		std::cout << "Copied: " << copy << std::endl;

		expect(((copy.getName() == b.getName()) 
			 && (copy.getSignGrade() == b.getSignGrade())
			 && (copy.getExecuteGrade()) == b.getExecuteGrade())
			 && (copy.getSigned() != true), "copy constructor copies name and grade");
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(false, "copy constructor copies name and grade");
	}
}

static void testAssignmentOperator()
{
	Form a("Form1", 30, 150);
	Form b("Form2", 70, 135);

	std::cout << "Before assignment:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	b = a;

	std::cout << "After b = a:" << std::endl;
	std::cout << "b: " << b << std::endl;

	expect((b.getSigned() == a.getSigned()), "assignment keeps const name, grades and changes only signed");
}

static void testValidConstructor()
{
	const std::string name = "ValidForm";
	int signGrade = 50;
	int executeGrade = 100;

	try
	{
		Form a(name, signGrade, executeGrade);
		std::cout << a << std::endl;

		expect((a.getName() == name 
			 && a.getSignGrade() == signGrade
			 && a.getExecuteGrade() == executeGrade), "form with given variables created");
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(false, "form with given variables created");
	}
}

static void testTooHighConstructor()
{
	int signGrade = -5;
	int executeGrade = 2;
	try
	{
		std::cout << "Trying to create a form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< std::endl;
		Form b("TooHighSignGrade", signGrade, executeGrade);
		expect(false, "negative signGrade throws GradeTooHighException");
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << YELLOW << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "negative signGrade throws GradeTooHighException");
	}
	catch (const std::exception &e)
	{
		expect(false, "negative signGrade throws correct exception");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}

	signGrade = 5;
	executeGrade = -2;
	try
	{
		std::cout << "Trying to create a form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< std::endl;
		Form b("TooHighExecuteGrade", executeGrade, executeGrade);
		expect(false, "negative executeGrade throws GradeTooHighException");
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << YELLOW << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "negative executeGrade throws GradeTooHighException");
	}
	catch (const std::exception &e)
	{
		expect(false, "negative executeGrade throws correct exception");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}

	signGrade = 0;
	executeGrade = 0;
	try
	{
		std::cout << "Trying to create a form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< std::endl;
		Form b("TooHigh", signGrade, executeGrade);
		expect(false, "signGrade:0 executeGrade:0 throws GradeTooHighException");
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << YELLOW << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "signGrade:0 executeGrade:0 throws GradeTooHighException");
	}
	catch (const std::exception &e)
	{
		expect(false, "signGrade:0 executeGrade:0 throws correct exception");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testTooLowConstructor()
{
	int signGrade = 151;
	int executeGrade = 7;

	try
	{
		std::cout << "Trying to create a form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< std::endl;
		Form b("TooLow", signGrade, executeGrade);
		expect(false, "signGrade lower than 150 throws GradeTooLowException");
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << YELLOW << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "signGrade lower than 150 throws GradeTooLowException");
	}
	catch (const std::exception &e)
	{
		expect(false, "signGrade lower than 150 throws correct exception type");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}

	signGrade = 30;
	executeGrade = 151;

	try
	{
		std::cout << "Trying to create a form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< std::endl;
		Form b("TooLow", signGrade, executeGrade);
		expect(false, "executeGrade lower than 150 throws GradeTooLowException");
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << YELLOW << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "executeGrade lower than 150 throws GradeTooLowException");
	}
	catch (const std::exception &e)
	{
		expect(false, "executeGrade lower than 150 throws correct exception type");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}
void testUnsigned()
{
	int signGrade = 30;
	int executeGrade = 50;
	int grade = 10;

	Bureaucrat b("bureaucrat", grade);
	Form a("unsigned", signGrade, executeGrade);

	try
	{
		std::cout << "Trying to sign form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< " bureaucrat grade: " << std::to_string(b.getGrade())
											<< std::endl;
		a.beSigned(b);
		expect(true, "Forum signed, signGrade:" + std::to_string(a.getSignGrade()) + " bureaucrat grade:" + std::to_string(b.getGrade()));
	}
	catch(const std::exception& e)
	{
		expect(false,  "Forum signed, signGrade:" + std::to_string(a.getSignGrade()) + " bureaucrat grade:" + std::to_string(b.getGrade()));
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

void testAlreadySigned()
{
	int signGrade = 30;
	int executeGrade = 50;
	int grade = 10;

	Bureaucrat b("bureaucrat", grade);
	Form a("alreadySigned", signGrade, executeGrade);
	a.beSigned(b);

	try
	{
		std::cout << "Trying to sign already signed form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< " bureaucrat grade: " << std::to_string(b.getGrade())
											<< std::endl;
		a.beSigned(b);
		expect(true, "Forum already signed, signGrade:" + std::to_string(a.getSignGrade()) + " bureaucrat grade:" + std::to_string(b.getGrade()));
	}
	catch(const std::exception& e)
	{
		expect(false,  "Forum already signed, signGrade:" + std::to_string(a.getSignGrade()) + " bureaucrat grade:" + std::to_string(b.getGrade()));
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

void testBeSignedException()
{
	int signGrade = 30;
	int executeGrade = 2;
	int grade = 31;

	Bureaucrat bur("bureaucrat", grade);
	Form form("alreadySigned", signGrade, executeGrade);

	try
	{
		std::cout << "Trying to sign already signed form with signGrade:" << std::to_string(signGrade) 
											<< " executeGrade:" << std::to_string(executeGrade)
											<< " bureaucrat grade: " << std::to_string(bur.getGrade())
											<< std::endl;
		form.beSigned(bur);
		expect(true, "Signed signGrade:" + std::to_string(form.getSignGrade()) + " bureaucrat grade:" + std::to_string(bur.getGrade()));
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cout << YELLOW << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "bureaucrat grade lower than signGrade throws GradeTooLowException");
	}
	catch(const std::exception& e)
	{
		expect(false,  "bureaucrat grade lower than signGrade, signGrade:" + std::to_string(form.getSignGrade()) + " bureaucrat grade:" + std::to_string(bur.getGrade()));
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

void testSignFormSuccess()
{
	int grade = 50;
	int signGrade = 60;
	int executeGrade = 60;

	Bureaucrat bur("bureaucrat", grade);
	Form form("form", signGrade, executeGrade);
	
	bur.signForm(form);
	expect((form.getSigned() == true), (bur.getName() + " signed " + form.getName()));
}

void testSignFormException()
{
	int grade = 50;
	int signGrade = 40;
	int executeGrade = 60;

	Bureaucrat bur("bureaucrat", grade);
	Form form("form", signGrade, executeGrade);
	
	bur.signForm(form);
	expect((form.getSigned() != true), (bur.getName() + " grade is low to sign " + form.getName()));
}

void testSignFormAlreadySigned()
{
	int grade = 50;
	int signGrade = 51;
	int executeGrade = 60;

	Bureaucrat bur("bureaucrat", grade);
	Form form("form", signGrade, executeGrade);
	
	std::cout << "Trying to sign the form" << std::endl;
	bur.signForm(form);
	std::cout << "Trying to sign the form again" << std::endl;
	bur.signForm(form);
	expect((form.getSigned() == true), (bur.getName() + " already signed " + form.getName()));
}

void testConstructor()
{
	std::cout << BLUE << "\n=== Constructor Tests ===\n"
			  << RESET << std::endl;
	testDefaultConstructor();
	testCopyConstructor(); // b(a)
	testAssignmentOperator(); // b = a
	testValidConstructor();
	testTooHighConstructor();
	testTooLowConstructor();
}

void testBeSigned()
{
	std::cout << BLUE << "\n=== Testing beSigned() ===\n"
			  << RESET << std::endl;
	testUnsigned();
	testAlreadySigned();
	testBeSignedException();
	
}

void testSignForm()
{
	std::cout << BLUE << "\n=== Testing signForm() ===\n"
	<< RESET << std::endl;
	testSignFormSuccess();
	testSignFormException();
	testSignFormAlreadySigned();
}

int main ()
{
	if (EX01_TEST)
	{
		std::cout << GREEN << "\n=== EX01 Tests ===\n"
				  << RESET << std::endl;
		testConstructor();
		testBeSigned();
		testSignForm();
	}
	return 0;
}
