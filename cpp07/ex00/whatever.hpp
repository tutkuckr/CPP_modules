/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 05:12:47 by tutku             #+#    #+#             */
/*   Updated: 2026/11/12 05:21:36 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T &a, T &b)
{
	T temp = a;

	a = b;
	b = temp;
}

template <typename T> T min(T &a, T &b)
{
	return ((a < b) ? a : b);
}

template <typename T> T max(T &a, T &b)
{
	return ((a > b) ? a : b);
}

#endif
// https://www.geeksforgeeks.org/cpp/templates-cpp/
