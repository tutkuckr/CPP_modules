/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:34:36 by tutku             #+#    #+#             */
/*   Updated: 2026/09/01 16:25:28 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	_name;
		bool		_signed;
		const int	_signGrade;
		const int	_executeGrade;

	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		AForm(const std::string name, const int signGrade, const int execGrade);
		~AForm();

		// ========================MEMBER FUNCTIONS========================
		void		beSigned(Bureaucrat b);

		// ========================GETTERS========================
		std::string	getName() const;
		bool		getSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		// ========================EXCEPTIONS========================
		class GradeTooLowException : std::exception
		{
			public:
				const char *what() const noexcept override;
		};

		class GradeTooHighException : std::exception
		{
		public:
			const char *what() const noexcept override;
		};
};
	std::ostream &operator<<(std::ostream &os, const Form &form);
	
	#endif

//overload insertion(<<)
// https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170

//exception
// https://www.geeksforgeeks.org/cpp/exceptionwhat-in-c-with-examples/
