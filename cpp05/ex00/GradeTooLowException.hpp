/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:26:23 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/14 14:12:08 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

	#include <iostream>
	
	class GradeTooLowException : public std::exception
	{

		private:
			int _grade;
			std::string _message;

		public:
			//GradeTooLowException();
			//~GradeTooLowException();

			GradeTooLowException(int grade);
			
			using exception::what;
			const char *what();
			int getGrade();
	};

#endif