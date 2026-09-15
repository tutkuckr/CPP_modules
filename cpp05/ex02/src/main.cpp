/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:12:37 by tutku             #+#    #+#             */
/*   Updated: 2026/09/15 12:43:09 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <sys/stat.h>

void expect(bool condition, const std::string &testName)
{
	if (condition)
		std::cout << GREEN << "[PASS] " << RESET << testName << std::endl;
	else
		std::cout << RED << "[FAIL] " << RESET << testName << std::endl;

	std::cout << std::endl;
}

static void testDefaultShrubberyConstructor()
{
	try
	{
		ShrubberyCreationForm test;

		expect(
			test.getTarget() == "Default Shrubbery",
			"default Shrubbery class created");
	}
	catch (const std::exception &e)
	{
		expect(false, "default Shrubbery class created");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testShrubberyConstructor()
{
	try
	{
		std::string target = "TEST_SHRUBBERY";
		ShrubberyCreationForm test(target);

		expect((test.getTarget() == target), "Shrubbery class created");
	}
	catch (const std::exception &e)
	{
		expect(false, "Shrubbery class created");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testShrubberyCopyConstructor()
{
	try
	{
		ShrubberyCreationForm test("test");
		ShrubberyCreationForm copy(test);

		expect(
			copy.getTarget() == test.getTarget(),
			"Shrubbery copy constructor copies target");
	}
	catch (const std::exception &e)
	{
		expect(false, "Shrubbery copy constructor copies target");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testShrubberyAssignment()
{
	try
	{
		ShrubberyCreationForm test("test");
		ShrubberyCreationForm copy("copy");

		copy = test;

		expect(
			copy.getTarget() == test.getTarget(),
			"Shrubbery assignment copies target");
	}
	catch (const std::exception &e)
	{
		expect(false, "Shrubbery assignment copies target");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testShrubberyFileCreate()
{
	try
	{
		std::string target = "TEST_FILECREATE";
		std::string fileName = target + "_shrubbery";
		
		ShrubberyCreationForm test(target);

		test.executeFormAction();
		std::ifstream file(fileName);

		expect((file.is_open()), "schrubbery file created");
		file.close();
		//std::remove(fileName.c_str()); //to remove the file
	}
	catch (const std::exception &e)
	{
		expect(false, "schrubbery file created");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testShrubberyFileCreateWithSpaces()
{
	try
	{
		std::string target = "TEST FILE WITH SPACES";
		std::string fileName = target + "_shrubbery";

		ShrubberyCreationForm test(target);

		test.executeFormAction();

		std::ifstream file(fileName);

		expect(
			file.is_open(),
			"shrubbery file created with spaces");

		file.close();
		//std::remove(fileName.c_str()); //to remove the file
	}
	catch (const std::exception &e)
	{
		expect(false, "shrubbery file created with spaces");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testShrubberyFileContent()
{
	try
	{
		std::string target = "TEST_FILECREATE";
		std::string fileName = target + "_shrubbery";

		std::string correctFileContent = "          /\\\n"
							 "         /  \\          /\\\n"
							 "        /****\\        /  \\       /\\\n"
							 "       /******\\      /****\\     /  \\\n"
							 "      /********\\    /******\\   /****\\\n"
							 "          ||           ||        ||\n"
							 "          ||           ||        ||\n";

		ShrubberyCreationForm test(target);

		test.executeFormAction();

		std::ifstream file(fileName);

		std::string content = "";
		std::string temp;

		while (std::getline(file, temp))
		{
			content += temp + "\n";
		}

		expect(content == correctFileContent, "shrubbery file contains expected content");

		file.close();
		//std::remove(fileName.c_str()); //to remove the file
	}
	catch (const std::exception &e)
	{
		expect(false, "schrubbery file created");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testRobotomyConstructor()
{
	try
	{
		std::string target = "TEST_ROBOT";
		RobotomyRequestForm test(target);

		expect(test.getTarget() == target, "RobotomyRequestForm constructor");
	}
	catch (const std::exception &e)
	{
		expect(false, "RobotomyRequestForm constructor");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testRobotomyCopyConstructor()
{
	try
	{
		RobotomyRequestForm test("test");
		RobotomyRequestForm copy(test);

		expect(
			copy.getTarget() == test.getTarget(), "RobotomyRequestForm copy constructor copies target");

		expect(
			copy.getSignGrade() == test.getSignGrade(), "RobotomyRequestForm copy constructor copies base form");
	}
	catch (const std::exception &e)
	{
		expect(false, "RobotomyRequestForm copy constructor");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testRobotomyAssignment()
{
	try
	{
		RobotomyRequestForm test("test");
		RobotomyRequestForm copy("copy");

		copy = test;

		expect(
			copy.getTarget() == test.getTarget(),
			"RobotomyRequestForm assignment copies target");
	}
	catch (const std::exception &e)
	{
		expect(false, "RobotomyRequestForm assignment operator");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testRobotomize()
{
	try
	{
		RobotomyRequestForm test("test");
		std::cout << YELLOW
				  << "Testing robotomy randomness:"
				  << RESET << std::endl;

		for (int i = 0; i < 10; i++)
			test.executeFormAction();

		expect(true, "Robotomy function executed");
	}
	catch(const std::exception& e)
	{
		expect(false, "RobotomyRequestForm robotomizer");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testDefaultPresidentialConstructor()
{
	try
	{
		PresidentialPardonForm test;

		expect(
			test.getTarget() == "Default Presidential Target",
			"default PresidentialPardonForm class created");
	}
	catch (const std::exception &e)
	{
		expect(false, "default PresidentialPardonForm class created");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testPresidentialConstructor()
{
	try
	{
		std::string target = "TEST";
		PresidentialPardonForm test(target);

		expect(
			test.getTarget() == target,
			"PresidentialPardonForm constructor");
	}
	catch (const std::exception &e)
	{
		expect(false, "PresidentialPardonForm constructor");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testPresidentialCopyConstructor()
{
	try
	{
		PresidentialPardonForm test("TEST");
		PresidentialPardonForm copy(test);

		expect(
			copy.getTarget() == test.getTarget(),
			"PresidentialPardonForm copy constructor copies target");
	}
	catch (const std::exception &e)
	{
		expect(false, "PresidentialPardonForm copy constructor");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testPresidentialAssignment()
{
	try
	{
		PresidentialPardonForm test("TEST");
		PresidentialPardonForm copy("COPY");

		copy = test;

		expect(
			copy.getTarget() == test.getTarget(),
			"PresidentialPardonForm assignment copies target");
	}
	catch (const std::exception &e)
	{
		expect(false, "PresidentialPardonForm assignment operator");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testPardon()
{
	try
	{
		PresidentialPardonForm test("TEST");

		test.executeFormAction();

		expect(true, "Presidential pardon function executed");
	}
	catch (const std::exception &e)
	{
		expect(false, "Presidential pardon function executed");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testExecuteUnsignedForm()
{
	try
	{
		ShrubberyCreationForm testShrubbery("TEST_EXECUTE");
		Bureaucrat testBureaucrat("Executor", 1);

		//didnt sign first
		testShrubbery.execute(testBureaucrat);

		expect(false, "unsigned form cannot be executed");
	}
	catch (const AForm::NotSignedException &e)
	{
		expect(true, "unsigned form cannot be executed");
		std::cout << YELLOW
				  << e.what()
				  << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		expect(false, "unsigned form throws correct exception");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}

	try
	{
		ShrubberyCreationForm testShrubbery("TEST_LIMIT");
		Bureaucrat test("test", 137);
		

		testShrubbery.beSigned(test);
		testShrubbery.execute(test);

		expect(true, "test bureaucrat with exact required grade can execute");
	}
	catch (const std::exception &e)
	{
		expect(false, "test bureaucrat with exact required grade can execute");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}

	try
	{
		ShrubberyCreationForm testShrubbery("TEST_OUT_OF_LIMIT");
		Bureaucrat test("test", 138); //limit is 137
		

		testShrubbery.beSigned(test);
		testShrubbery.execute(test);
		expect(false, "test bureaucrat with lower than required grade cannot execute");
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cout << YELLOW << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "bureaucrat with lower than required grade cannot execute");
	}
	catch (const std::exception &e)
	{
		expect(false, "test bureaucrat with lower than required grade cannot execute");

		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

int main ()
{
	if (EX02_TEST)
	{
		std::cout << GREEN << "\n=== EX02 Tests ===\n"
				  << RESET << std::endl;

		// Shrubbery
		std::cout << GREEN << "\n=== Shrubbery Tests ===\n"
				  << RESET << std::endl;
		testDefaultShrubberyConstructor();
		testShrubberyConstructor();
		testShrubberyCopyConstructor();
		testShrubberyAssignment();
		testShrubberyFileCreate();
		testShrubberyFileCreateWithSpaces();
		testShrubberyFileContent();

		//Robotomy
		std::cout << GREEN << "\n=== Robotomy Tests ===\n"
				  << RESET << std::endl;
		testRobotomyConstructor();
		testRobotomyCopyConstructor();
		testRobotomyAssignment();
		testRobotomize();

		//Presintial Pardon
		std::cout << GREEN << "\n=== Presidential Tests ===\n"
				  << RESET << std::endl;
		testDefaultPresidentialConstructor();
		testPresidentialConstructor();
		testPresidentialCopyConstructor();
		testPresidentialAssignment();
		testPardon();

		//execute form action
		std::cout << GREEN << "\n=== Test execute ===\n"
				  << RESET << std::endl;
		testExecuteUnsignedForm();
		}
	return 0;
}
