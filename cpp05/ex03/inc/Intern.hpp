/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 22:09:00 by tutku             #+#    #+#             */
/*   Updated: 2026/09/14 23:08:23 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

class Intern
{
	private:

	public:
		// ========================CONSTRUCTORS============================
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);

		// ========================MEMBER FUNCTIONS========================
		AForm*makeForm(std::string formName, std::string target);
		void printMsg(std::string formName);
		int getFormIndex(std::string formName);

		// ========================EXCEPTIONS==============================
		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};

#endif
