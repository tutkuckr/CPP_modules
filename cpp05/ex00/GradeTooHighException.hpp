/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:15:43 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/14 14:12:19 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP

	#include <iostream>
	
	class GradeTooHighException : public std::exception
	{
		private:
			int _grade;
			std::string _message;

		public:
			//GradeTooHighException();
			//~GradeTooHighException();

			GradeTooHighException(int grade);
			using exception::what;
			const char *what();
			int getGrade();
		};
#endif

/*
https://stackoverflow.com/questions/18515183/c-overloaded-virtual-function-warning-by-clang
*/