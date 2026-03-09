/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 17:54:42 by tutku             #+#    #+#             */
/*   Updated: 2026/03/09 04:19:02 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// int main(void)
// {
// 	Point A(0.0f, 0.0f);
// 	Point B(10.0f, 0.0f);
// 	Point C(0.0f, 10.0f);
// 	Point P1(3.0f, 3.0f);
// 	Point P2(20.0f, 30.0f);

// 	bool point1 = bsp(A, B, C, P1);
// 	bool point2 = bsp(A, B, C, P2);

// 	if (point1)
// 		std::cout << "Point 1 is inside the triangle" << std::endl;
// 	else
// 		std::cout << "Point 1 is NOT inside the triangle" << std::endl;
// 	if (point2)
// 		std::cout << "Point 1 is inside the triangle" << std::endl;
// 	else
// 		std::cout << "Point 1 is NOT inside the triangle" << std::endl;
// 	return (0);
// }

int main(void)
{
	Point A(0.0f, 0.0f);
	Point B(10.0f, 0.0f);
	Point C(0.0f, 10.0f);

	Point P1(3.0f, 3.0f);	// inside - true
	Point P2(20.0f, 30.0f); // clearly outside
	Point P3(5.0f, 0.0f);	// on edge AB
	Point P4(0.0f, 0.0f);	// exactly vertex A
	Point P5(1.0f, 8.0f);	// inside near edge
	Point P6(-1.0f, -1.0f); // outside negative
	Point P7(4.0f, 6.0f);	// on the line - false
	Point P8(6.0f, 6.0f);	// outside but near triangle
	Point P9(5.0f, 5.0f);

	std::cout << "P1: " << bsp(A, B, C, P1) << std::endl;
	std::cout << "P2: " << bsp(A, B, C, P2) << std::endl;
	std::cout << "P3: " << bsp(A, B, C, P3) << std::endl;
	std::cout << "P4: " << bsp(A, B, C, P4) << std::endl;
	std::cout << "P5: " << bsp(A, B, C, P5) << std::endl;
	std::cout << "P6: " << bsp(A, B, C, P6) << std::endl;
	std::cout << "P7: " << bsp(A, B, C, P7) << std::endl;
	std::cout << "P8: " << bsp(A, B, C, P8) << std::endl;
	std::cout << "P8: " << bsp(A, B, C, P9) << std::endl;

	return 0;
}
