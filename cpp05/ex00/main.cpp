/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:00:20 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/14 16:12:55 by tcakir-y         ###   ########.fr       */
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

static void printTitle(const std::string& title)
{
	std::cout << "\n========================================\n";
	std::cout << title << std::endl;
	std::cout << "========================================\n";
}

int main()
{
	printTitle("1. VALID BUREAUCRAT CREATION");
	try
	{
		Bureaucrat a("Alice", 75);
		std::cout << a << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	printTitle("2. GRADE TOO HIGH ON CONSTRUCTION");
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch(GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch(GradeTooLowException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	printTitle("3. GRADE TOO LOW ON CONSTRUCTION");
	try
	{
		Bureaucrat c("Charlie", 151);
		std::cout << c << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch(GradeTooLowException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	printTitle("4. NORMAL INCREMENT");
	try
	{
		Bureaucrat d("David", 42);
		std::cout << "Before increment: " << d << std::endl;
		d.incrementGrade();
		std::cout << "After increment:  " << d << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 5. Decrement grade normally
	printTitle("5. NORMAL DECREMENT");
	try
	{
		Bureaucrat e("Emma", 42);
		std::cout << "Before decrement: " << e << std::endl;
		e.decrementGrade();
		std::cout << "After decrement:  " << e << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 6. Increment at highest grade (should throw)
	printTitle("6. INCREMENT FROM GRADE 1");
	try
	{
		Bureaucrat f("Frank", 1);
		std::cout << "Before increment: " << f << std::endl;
		f.incrementGrade();
		std::cout << "After increment:  " << f << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 7. Decrement at lowest grade (should throw)
	printTitle("7. DECREMENT FROM GRADE 150");
	try
	{
		Bureaucrat g("Grace", 150);
		std::cout << "Before decrement: " << g << std::endl;
		g.decrementGrade();
		std::cout << "After decrement:  " << g << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 8. Multiple increments until exception
	printTitle("8. MULTIPLE INCREMENTS UNTIL EXCEPTION");
	try
	{
		Bureaucrat h("Helen", 3);
		std::cout << h << std::endl;
		h.incrementGrade();
		std::cout << h << std::endl;
		h.incrementGrade();
		std::cout << h << std::endl;
		h.incrementGrade(); // should throw
		std::cout << h << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 9. Multiple decrements until exception
	printTitle("9. MULTIPLE DECREMENTS UNTIL EXCEPTION");
	try
	{
		Bureaucrat i("Ian", 148);
		std::cout << i << std::endl;
		i.decrementGrade();
		std::cout << i << std::endl;
		i.decrementGrade();
		std::cout << i << std::endl;
		i.decrementGrade(); // should throw
		std::cout << i << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 10. Copy constructor
	printTitle("10. COPY CONSTRUCTOR");
	try
	{
		Bureaucrat original("Jack", 10);
		Bureaucrat copy(original);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 11. Copy assignment operator
	printTitle("11. COPY ASSIGNMENT OPERATOR");
	try
	{
		Bureaucrat first("Kevin", 20);
		Bureaucrat second("Laura", 100);

		std::cout << "Before assignment:" << std::endl;
		std::cout << "First:  " << first << std::endl;
		std::cout << "Second: " << second << std::endl;

		second = first;

		std::cout << "After assignment:" << std::endl;
		std::cout << "First:  " << first << std::endl;
		std::cout << "Second: " << second << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// 12. Stack object lifetime test
	printTitle("12. STACK OBJECT TEST");
	try
	{
		Bureaucrat z("Zara", 50);
		std::cout << z << std::endl;
	}
	catch (GradeTooHighException &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	printTitle("END OF TESTS");
	return 0;
}
