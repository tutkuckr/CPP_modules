/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 17:40:18 by tutku             #+#    #+#             */
/*   Updated: 2026/11/21 03:33:34 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T> class Array {
	private:
		T *_arr;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array &operator=(const Array &other);
		Array(const Array &other);
		~Array();

		T& operator[](int index) const;
		unsigned int size() const;

		class OutOfBoundException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};

#include "Array.tpp"

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"

#endif
