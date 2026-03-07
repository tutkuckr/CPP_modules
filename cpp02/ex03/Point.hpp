/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 23:28:49 by tutku             #+#    #+#             */
/*   Updated: 2026/03/08 00:10:09 by tutku            ###   ########.fr       */
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
		Point &operator=(const Point &other);	//copy assignment operator overload
		Point(const float x, const float y);
		~Point();								//destructor
		const float getPointX();
};

#endif
