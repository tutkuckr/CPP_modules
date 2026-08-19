/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:00:20 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/24 20:07:46 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void printTitle(const std::string &title)
{
	std::cout << "\n========================================\n";
	std::cout << title << std::endl;
	std::cout << "========================================\n";
}

static void testBureaucratCreation()
{
	printTitle("TEST 1: Bureaucrat creation");

	try
	{
		Bureaucrat b1("Alice", 1);
		std::cout << "Created: " << b1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Bob", 150);
		std::cout << "Created: " << b2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("TooHigh", 0);
		std::cout << "Created: " << b3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Could not create bureaucrat with grade 0: "
				  << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b4("TooLow", 151);
		std::cout << "Created: " << b4 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Could not create bureaucrat with grade 151: "
				  << e.what() << std::endl;
	}
}

static void testFormCreation()
{
	printTitle("TEST 2: Form creation");

	try
	{
		Form f1("Normal Form", 50, 25);
		std::cout << f1;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form f2("Easy Form", 150, 150);
		std::cout << f2;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form f3("Invalid High Form", 0, 50);
		std::cout << "Created invalid high form:\n"
				  << f3;
	}
	catch (const std::exception &e)
	{
		std::cout << "Could not create form with signGrade 0: "
				  << e.what() << std::endl;
	}

	try
	{
		Form f4("Invalid Low Form", 151, 50);
		std::cout << "Created invalid low form:\n"
				  << f4;
	}
	catch (const std::exception &e)
	{
		std::cout << "Could not create form with signGrade 151: "
				  << e.what() << std::endl;
	}
}

static void testSuccessfulSigning()
{
	printTitle("TEST 3: Successful signing");

	try
	{
		Bureaucrat boss("Boss", 1);
		Form form("Important Contract", 50, 25);

		std::cout << "Before signing:\n";
		std::cout << form;

		boss.signForm(form);

		std::cout << "After signing:\n";
		std::cout << form;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void testFailedSigning()
{
	printTitle("TEST 4: Failed signing");

	try
	{
		Bureaucrat intern("Intern", 150);
		Form form("High Grade Document", 10, 5);

		std::cout << "Before signing:\n";
		std::cout << form;

		intern.signForm(form);

		std::cout << "After signing attempt:\n";
		std::cout << form;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void testExactGradeSigning()
{
	printTitle("TEST 5: Signing with exact required grade");

	try
	{
		Bureaucrat test("test", 42);
		Form form("Exact Grade Form", 42, 20);

		std::cout << "Before signing:\n";
		std::cout << form;

		test.signForm(form);

		std::cout << "After signing:\n";
		std::cout << form;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void testAlreadySignedForm()
{
	printTitle("TEST 6: Signing an already signed form");

	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat anotherBoss("AnotherBoss", 1);
		Form form("Already Signed Form", 50, 50);

		std::cout << "Initial form:\n";
		std::cout << form;

		boss.signForm(form);
		anotherBoss.signForm(form);

		std::cout << "Final form:\n";
		std::cout << form;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void testCopyConstructor()
{
	printTitle("TEST 7: Form copy constructor");

	try
	{
		Bureaucrat boss("Boss", 1);
		Form original("Original Form", 50, 25);

		boss.signForm(original);

		std::cout << "Original:\n";
		std::cout << original;

		Form copy(original);

		std::cout << "Copy:\n";
		std::cout << copy;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

//_name, _signGrade and _execGrade are const
static void testAssignmentOperator()
{
	printTitle("TEST 8: Form assignment operator");

	try
	{
		Bureaucrat boss("Boss", 1);

		Form form1("Form One", 50, 25);
		Form form2("Form Two", 100, 75);

		boss.signForm(form1);

		std::cout << "Before assignment:\n";
		std::cout << "form1:\n"
				  << form1;
		std::cout << "form2:\n"
				  << form2;

		form2 = form1;

		std::cout << "After form2 = form1:\n";
		std::cout << "form1:\n"
				  << form1;
		std::cout << "form2:\n"
				  << form2;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

static void testBureaucratIncrementDecrement()
{
	printTitle("TEST 9: Bureaucrat increment/decrement");

	try
	{
		Bureaucrat b("Middle", 75);
		std::cout << "Initial: " << b << std::endl;

		b.incrementGrade();
		b.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat top("Top", 1);
		std::cout << "Trying to increment grade 1 bureaucrat:\n";
		top.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << "Trying to decrement grade 150 bureaucrat:\n";
		bottom.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int main()
{
	testBureaucratCreation();
	testFormCreation();
	testSuccessfulSigning();
	testFailedSigning();
	testExactGradeSigning();
	testAlreadySignedForm();
	testCopyConstructor();
	testAssignmentOperator();
	testBureaucratIncrementDecrement();

	return (0);
}
