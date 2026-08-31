/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:12:37 by tutku             #+#    #+#             */
/*   Updated: 2026/08/31 17:10:46 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		Bureaucrat a;
		std::cout << a << std::endl;

		expect(((a.getName() == "Bureaucrat") && (a.getGrade() == 150)), "default bureaucrat created");
	}
	catch (const std::exception &e)
	{
		expect(false, "default bureaucrat created");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testCopyConstructor()
{
	Bureaucrat b("Copy", 35);
	try
	{
		std::cout << "Copying bureaucrat.." << std::endl;
		Bureaucrat copy(b);
		std::cout << "Copied: " << copy << std::endl;

		expect(((copy.getName() == b.getName()) && (copy.getGrade() == b.getGrade())),"copy constructor copies name and grade");
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
	Bureaucrat a("Bureaucrat1", 30);
	Bureaucrat b("Bureaucrat2", 70);

	std::cout << "Before assignment:" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	b = a;

	std::cout << "After b = a:" << std::endl;
	std::cout << "b: " << b << std::endl;

	expect((b.getName() == "Bureaucrat2"), "assignment keeps const name and copies grade");
}

static void testValidConstructor()
{
	const std::string name = "Valid";
	int grade = 50;

	try
	{
		Bureaucrat a(name, grade);
		std::cout << a << std::endl;

		expect((a.getName() == name && a.getGrade() == grade), "bureaucrat with given variables created");
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(false, "bureaucrat with given variables created");
	}
}

static void testTooHighConstructor()
{
	int grade = -5;
	try
	{
		std::cout << "Trying to create a bureaucrat with grade:" << std::to_string(grade) << std::endl;
		Bureaucrat b("TooHigh", grade);
		expect(false, "negative grade throws GradeTooHighException");
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "negative grade throws GradeTooHighException");
	}
	catch (const std::exception &e)
	{
		expect(false, "negative grade throws correct exception");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}

	grade = 0;
	try
	{
		std::cout << "Trying to create a bureaucrat with grade:" << std::to_string(grade) << std::endl;
		Bureaucrat b("TooHigh", grade);
		expect(false, "grade:0 throws GradeTooHighException");
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "grade:0 throws GradeTooHighException");
	}
	catch (const std::exception &e)
	{
		expect(false, "grade:0 throws correct exception");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testTooLowConstructor()
{
	int grade = 151;

	try
	{
		std::cout << "Trying to create a bureaucrat with grade:" << std::to_string(grade) << std::endl;
		Bureaucrat b("TooLow", grade);
		expect(false, "grade lower than 150 throws GradeTooLowException");
	}
	catch(const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << "[EXCEPTION] "
				  << RESET << e.what() << std::endl;
		expect(true, "grade lower than 150 throws GradeTooLowException");
	}
	catch (const std::exception &e)
	{
		expect(false, "grade lower than 150 throws correct exception type");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testIncrementGrade()
{
	int grade = 50;
	try
	{
		Bureaucrat b("Tutku", grade);
		b.incrementGrade();

		expect((b.getGrade() == grade - 1), "grade " + std::to_string(grade) + " incremented to " + std::to_string(b.getGrade()));
	}
	catch(const std::exception& e)
	{
		expect(false, "grade incremented");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testIncrementBoundary()
{
	int grade = 2;

	try
	{
		Bureaucrat b("Highest", grade);
		b.incrementGrade();

		expect(b.getGrade() == 1, "grade 2 increments to highest grade 1");
	}
	catch (const std::exception &e)
	{
		expect(false, "grade 2 increments to highest grade 1");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testIncrementException()
{
	int grade = 1;
	Bureaucrat test("Highest", grade);
	try
	{
		test.incrementGrade();
		expect(false, "grade 1 throws GradeTooHighException");
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << "[EXCEPTION] " << RESET << e.what() << std::endl;
		expect((test.getGrade() == 1), "failed increment, keeping grade at 1");
	}
	catch (const std::exception &e)
	{
		expect(false, "increment threw correct exception type");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testDecrementGrade()
{
	int grade = 50;
	try
	{
		Bureaucrat b("Tutku", grade);
		b.decrementGrade();
		expect((b.getGrade() == grade + 1), "grade " + std::to_string(grade) + " decremented to " + std::to_string(b.getGrade()));
	}
	catch(const std::exception& e)
	{
		expect(false, "grade decremented");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testDecrementBoundary()
{
	int grade = 149;

	try
	{
		Bureaucrat b("Lowest", grade);
		b.decrementGrade();

		expect(b.getGrade() == 150, "grade 149 decrements to lowest grade 150");
	}
	catch (const std::exception &e)
	{
		expect(false, "grade 149 decrements to lowest grade 150");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testDecrementException()
{
	int grade = 150;
	Bureaucrat test("Lowest", grade);

	try
	{
		test.decrementGrade();
		expect(false, "decrement grade " + std::to_string(grade) + " throws GradeTooLowException");
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << "[EXCEPTION] " << RESET << e.what() << std::endl;
		expect(true, "failed decrement");
	}
	catch (const std::exception &e)
	{
		expect((test.getGrade() == 150), "failed decrement, keeping grade at 150");
		std::cerr << RED << "[UNEXPECTED EXCEPTION] "
				  << RESET << e.what() << std::endl;
	}
}

static void testDecrement()
{
	std::cout << BLUE << "\n=== Decrement Tests ===\n"
			  << RESET << std::endl;
	testDecrementGrade(); // 50 -> 51
	testDecrementBoundary(); // 149 -> 150
	testDecrementException(); // 150 -> x
}

static void testIncrement()
{
	std::cout << BLUE << "\n=== Increment Tests ===\n"
			  << RESET << std::endl;
	testIncrementGrade(); // 50 -> 49
	testIncrementBoundary(); // 2 -> 1
	testIncrementException(); // 1-> x
}

static void testConstructor()
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

int main ()
{
	Bureaucrat b("Tutku", 50);

	if (EX00_TEST)
	{
		std::cout << GREEN << "\n=== EX00 Tests ===\n"
				  << RESET << std::endl;

		testConstructor();
		testIncrement();
		testDecrement();
	}
	return 0;
}
