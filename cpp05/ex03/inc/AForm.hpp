/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 17:34:36 by tutku             #+#    #+#             */
/*   Updated: 2026/09/22 11:06:49 by tcakir-y         ###   ########.fr       */
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
		const std::string	_name;
		bool		_signed;
		const int	_signGrade;
		const int	_executeGrade;

	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		AForm(const std::string name, const int signGrade, const int execGrade);
		virtual ~AForm();

		// ========================MEMBER FUNCTIONS========================
		void			beSigned(Bureaucrat b);
		virtual void	execute(Bureaucrat const &executor) const;
		virtual void	executeFormAction() const = 0;

		// ========================GETTERS========================
		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecuteGrade() const;

		// ========================EXCEPTIONS========================
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};

		class NotSignedException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};
	std::ostream &operator<<(std::ostream &os, const AForm &form);
	
	#endif

//overload insertion(<<)
// https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170

//exception
// https://www.geeksforgeeks.org/cpp/exceptionwhat-in-c-with-examples/
