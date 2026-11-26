/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:59:25 by tutku             #+#    #+#             */
/*   Updated: 2026/11/26 03:09:38 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <algorithm> //to sort the vector, and get max, min

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _v;

	public:
		Span();
		Span(const Span& other);
		Span &operator=(const Span &other);
		~Span();

		Span(unsigned int N);

		void addNumber(int number);
		void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		class VectorAlreadyFull : public std::exception
		{
			public:
				const char *what() const noexcept override;
				// virtual const char *what() const throw(); // Older C++ style
		};

		class NotEnoughNumbersStored : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"

#endif
