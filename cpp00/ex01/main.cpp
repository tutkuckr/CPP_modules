/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:25:47 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/02/01 00:11:46 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	std::string	input;
	PhoneBook	phoneBook;

	while (1)
	{
		if (!std::getline(std::cin, input)) 
			break;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			phoneBook.add();
		}
		else if (input == "SEARCH")
		{
			phoneBook.search();
		}
		else
		{
			std::cout << "Allowed inputs are\n1.ADD\n2.SEARCH\n3.EXIT\n";
		}
		std::cout << "Enter one of the following commands:\n1.ADD\n2.SEARCH\n3.EXIT\n\n";
	}
	std::cout << "Contacts are deleted!\nExited\n";
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
