/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:12:57 by tutku             #+#    #+#             */
/*   Updated: 2026/04/24 20:24:13 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);

		void beSigned(const Bureaucrat &bureaucrat);

		int getSignGrade() const;
		int getExecGrade() const;
		std::string getName() const;
		bool getIsSigned() const;

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
std::ostream &operator<<(std::ostream &os, const AForm &other);
#endif
