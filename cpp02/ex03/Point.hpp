/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:28:49 by tutku             #+#    #+#             */
/*   Updated: 2026/03/09 04:09:55 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point 
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();								//default constructor
		Point(const Point &other);				//copy constructor
		Point(const float x, const float y);
		~Point();								//destructor
		const Fixed getPoint(char axis) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
