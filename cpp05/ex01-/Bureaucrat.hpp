/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:55:54 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/24 17:59:43 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#include "Form.hpp"
class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade; //highest:1, lowest:150

	public:

		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(Form &form);

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);

#endif
