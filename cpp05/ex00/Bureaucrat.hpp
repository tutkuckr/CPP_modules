/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:55:54 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/14 15:34:04 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade; //highest:1, lowest:150
		//GradeTooHighException _high;
		//GradeTooLowException _low;
	public:

		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(int grade);
		Bureaucrat(std::string const name);
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);

/*
Functions:
*with grade, name
*with grade , noName
*with noGrade, name
*with noGrade, noName
*/

#endif