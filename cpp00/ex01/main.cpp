/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:25:47 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/01/15 16:41:03 by tcakir-y         ###   ########.fr       */
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
		else if (input.compare("SEARCH"))
		{
			test.search();
		}
		std::cout << "Enter one of the following commands:\n1.ADD\n2.SEARCH\n3.EXIT\n";
		std::cin >> input;
	}
	std::cout << "Exited\n";
	return (0);
}

/*
anything that will always be used inside a class is private, 
and that anything that can be used outside a class is public
*/

/*
ADD:	*first name, last name, nickname, phone number, and darkest secret. 
		*A saved contact can’t have empty fields.

SEARCH:	*Display the saved contacts as a list of 4 columns: 
		index, first name, last name and nickname.
		*each column 10 characters, pipe separates, right aligned
		if text is longer, replace last displayable char by '.'
		if index entered is out of range/wrong, define relevant behaviour

EXIT: *program quits and contacts are lost!

ignore any other input
*/