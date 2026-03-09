/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:28:26 by tutku             #+#    #+#             */
/*   Updated: 2026/03/09 04:02:22 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// (x1-x3)(y2-y3) - (x2-x3)(y1-y3)
Fixed checkSides(Point const point, Point const point1, Point const point2)
{
	Fixed x1 = point.getPoint('x');
	Fixed x2 = point1.getPoint('x');
	Fixed x3 = point2.getPoint('x');
	Fixed y1 = point.getPoint('y');
	Fixed y2 = point1.getPoint('y');
	Fixed y3 = point2.getPoint('y');

	return (((x1 - x3) * (y2 - y3)) - ((x2 - x3) * (y1 - y3)));
}

/*
	a, b, c: The vertices of our beloved triangle.
	point: The point to check.
	Returns: True if the point is inside the triangle. False otherwise.
	Thus, if the point is a vertex or on an edge, it will return False.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed side1 = checkSides(point, a, b);
	Fixed side2 = checkSides(point, b, c);
	Fixed side3 = checkSides(point, c, a);

	if (side1 > 0 && side2 > 0 && side3 > 0)
		return (true);
	else if (side1 < 0 && side2 < 0 && side3 < 0)
		return (true);
	return (false);
}
