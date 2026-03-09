/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:28:41 by tutku             #+#    #+#             */
/*   Updated: 2026/03/09 04:06:07 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0), y(0)
{

}

Point::Point(const Point &other):x(other.x), y(other.y)
{

}


Point::Point(const float x, const float y): x(x), y(y)
{

}

const Fixed Point::getPoint(char axis) const
{
	if (axis == 'x')
	{
		return (this->x);
	}
	return (this->y);
}

Point::~Point()
{

}
