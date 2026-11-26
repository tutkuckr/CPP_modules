/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 16:59:52 by tutku             #+#    #+#             */
/*   Updated: 2026/11/26 03:09:34 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{
}


Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_v = other._v;
	}
	return (*this);
}

Span::Span(unsigned int N) : _N(N)
{
	
}

Span::~Span()
{
}

/*
adds the variable number to the vector
Any attempt to add a new element if there
are already N elements stored should throw an exception.
*/
void Span::addNumber(int number)
{
	if (this->_v.size() >= _N)
	{
		throw VectorAlreadyFull();
	}
	this->_v.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (static_cast<size_t>(std::distance(start, end)) > _N - _v.size())
	{
		throw VectorAlreadyFull();
	}
	auto it = start;

	while (it != end)
	{
		addNumber(*it);
		++it;
	}
}

int Span::shortestSpan()
{
	if (this->_v.size() <= 1)
		throw NotEnoughNumbersStored();

	std::vector<int> sortedVector = this->_v;

	sort(sortedVector.begin(), sortedVector.end());

	auto it = sortedVector.begin();
	it++;
	int shortest = (*it) - (*(it - 1));

	while (it != sortedVector.end())
	{
		if ((*it) - (*(it - 1)) < shortest)
		{
			shortest = (*it) - (*(it - 1));
		}
		++it;
	}
	return shortest;
}

int Span::longestSpan()
{
	if (this->_v.size() <= 1)
		throw NotEnoughNumbersStored();

	std::vector<int> sortedVector = this->_v;
	sort(sortedVector.begin(), sortedVector.end());

	return (sortedVector.back() - sortedVector.front());
}

const char *Span::VectorAlreadyFull::what() const noexcept
{
	return ("Vector is full!");
}

const char *Span::NotEnoughNumbersStored::what() const noexcept
{
	return ("You dont have enough numbers stored !");
}
