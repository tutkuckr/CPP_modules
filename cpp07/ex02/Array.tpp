/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:59:12 by tutku             #+#    #+#             */
/*   Updated: 2026/11/21 01:52:11 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//create an empty array
template <typename T>
Array<T>::Array()
{
	_arr = nullptr;
	_size = 0;
}

// Creates an array of n elements initialized by default
template <typename T>
Array<T>::Array(unsigned int n)
{
	_arr = new T[n]();
	_size = n;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _arr;
		_size = other._size;
		_arr = new T[_size]();

		for (unsigned int i = 0; i < other._size; i++)
		{
			this->_arr[i] = other._arr[i];
		}
	}
	return (*this);
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	_arr = nullptr;
	_size = 0;
	(*this) = other;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T> unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
T& Array<T>::operator[](int index) const
{
	if (!((index >= 0) && (static_cast<unsigned int>(index) < _size)))
	{
		throw OutOfBoundException();
	}
	return (_arr[index]);
}

template <typename T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
	return "Array index out of bounds";
}
