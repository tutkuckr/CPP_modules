/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:12:27 by tutku             #+#    #+#             */
/*   Updated: 2026/09/14 22:02:30 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX02_BUREAUCRAT_HPP
#define EX02_BUREAUCRAT_HPP

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"

#define EX02_TEST 1

#include <iostream>
#include <exception>
#include <string>

#include "AForm.hpp"
class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		// ========================CONSTRUCTORS============================
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		Bureaucrat(const std::string name, int grade);

		// ========================MEMBER FUNCTIONS========================
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void signForm(AForm &form);
		void executeForm(AForm const &form) const;

		// ========================EXCEPTIONS==============================
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
