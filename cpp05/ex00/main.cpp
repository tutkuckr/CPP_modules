/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:00:20 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/23 17:44:23 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//int main(void)
//{
//	Bureaucrat test("testBureaucrat", 160);
//	Bureaucrat test2;
//	test2.decrementGrade();

//	return 0;
//}

static void printSeparator(const std::string &label)
{
	std::cout << "\n=== " << label << " ===" << std::endl;
}

int main()
{
	printSeparator("Default constructor");
	{
		Bureaucrat b;
		std::cout << b << std::endl;
	}

	printSeparator("Valid bureaucrat (grade 1 and grade 150)");
	{
		Bureaucrat top("Bureaucrat_1", 1);
		Bureaucrat bottom("Bureaucrat_2", 150);
		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	}

	printSeparator("Bureaucrat with grade 0 -> GradeTooHighException");
	{
		try
		{
			Bureaucrat b("Bureaucrat_Too_High", 0);
			std::cout << b << std::endl; // wont reach here
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	printSeparator("Construction with grade 151 -> GradeTooLowException");
	{
		try
		{
			Bureaucrat b("Bureaucrat_Too_Low", 151);
			std::cout << b << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	printSeparator("Normal increment (grade 5 -> 4)");
	{
		try
		{
			Bureaucrat b("Eve", 5);
			b.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << '\n';
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	printSeparator("Normal decrement (grade 5 -> 6)");
	{
		try
		{
			Bureaucrat b("Frank", 5);
			b.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << '\n';
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Caught: " << e.what() << '\n';
		}
	}

	printSeparator("Increment at grade 1 -> GradeTooHighException");
	{
		try
		{
			Bureaucrat b("Grace", 1);
			b.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "Caught: " << e.what() << '\n';
		}
	}

	printSeparator("Decrement at grade 150 -> GradeTooLowException");
	{
		try
		{
			Bureaucrat b("Hank", 150);
			b.decrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	printSeparator("Copy constructor");
	{
		Bureaucrat original("Ivy", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}

	//const name, so only grade is copied
	printSeparator("Assignment operator");
	{
		Bureaucrat a("Jake", 10);
		Bureaucrat b("Karen", 80);
		std::cout << "Before assignment - b: " << b << std::endl;
		b = a;
		std::cout << "After  assignment - b: " << b << std::endl;
	}

	printSeparator("Catch via std::exception base reference");
	{
		try
		{
			Bureaucrat b("Leo", -5);
		}
		catch (const std::exception &e)
		{
			std::cout << "Caught std::exception: " << e.what() << std::endl;
		}
	}
	return (0);
}
