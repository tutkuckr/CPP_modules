/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:12:37 by tutku             #+#    #+#             */
/*   Updated: 2026/08/20 00:42:27 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void expect(bool condition, const std::string &testName)
{
	if (condition)
		std::cout << GREEN << "[PASS] " << RESET << testName << std::endl;
	else
		std::cout << RED << "[FAIL] " << RESET << testName << std::endl;
}

static void testConstructor()
{
	const std::string name = "Tutku";
	int grade = 50;
	
	Bureaucrat a;
	Bureaucrat b(name, grade);

	expect((b.getName() == name), "constructor created");
	expect((b.getName() == name), "constructor stores name");
	expect((b.getGrade() == 50), "constructor stores grade");

}

static void testIncrementGrade()
{
	int grade = 50;

	Bureaucrat b("Tutku", grade);
	b.incrementGrade();

	expect((b.getGrade() == (grade - 1)), "grade incremented ");
}

static void testDecrementGrade()
{
	int grade = 50;

	Bureaucrat b("Tutku", grade);
	b.decrementGrade();

	expect((b.getGrade() == (grade + 1)), "grade decremented ");
}

static void testIncrementException()
{
	int grade = 1;

	try
	{
		Bureaucrat high("High", grade);
		expect((high.getGrade() != (grade - 1)), "throw error ");
		high.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main ()
{
	Bureaucrat b("Tutku", 50);

	std::cout << BLUE << "\n=== Bureaucrat Tests ===\n" << RESET << std::endl;

	testConstructor();
	testIncrementGrade();
	testDecrementGrade();
	testIncrementException();

	

	return 0;
}

