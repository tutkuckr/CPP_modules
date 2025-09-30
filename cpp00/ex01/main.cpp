/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:25:47 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/09/30 19:55:37 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add()
{
	std::cout << "will add it!";
}

int	main(void)
{
	std::string input;
	PhoneBook test;

	std::cout << "Enter one of the following commands:\n1.ADD\n2.SEARCH\n3.EXIT\n";
	std::cin >> input;
	while (input.compare("EXIT") != 0)
	{
		if (input.compare("ADD"))
		{
			test.add();
		}
		std::cout << "Enter one of the following commands:\n1.ADD\n2.SEARCH\n3.EXIT\n";
		std::cin >> input;
	}
	std::cout << "Exited\n";
	return (0);
}