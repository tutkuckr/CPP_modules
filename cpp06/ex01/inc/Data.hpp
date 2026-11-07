/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 16:06:43 by tutku             #+#    #+#             */
/*   Updated: 2026/11/07 17:15:44 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

struct Data
{
	int numVar = 0;
	double doubleVar = 0.0;
	std::string strVar = "";

	Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();
};

#endif
