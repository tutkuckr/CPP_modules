/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:37:36 by tutku             #+#    #+#             */
/*   Updated: 2026/01/17 23:56:18 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

std::string get_input(std::string msg)
{
	std::cout << msg;
	std::string input;

	while (1)
	{
		std::getline(std::cin, input);
		if (input == "")
			std::cout << "Please enter a value!\n" << msg;
		else
			return (input);
	}
}


void	Contact::add_contact(void)
{
	firstName = get_input("Enter first name:\n");
	lastName = get_input("Enter last name:\n");
	nickname = get_input("Enter nickname:\n");
	phoneNum = get_input("Enter phone number:\n"); // TODO: validate phone number
	darkestSecret = get_input("Enter darkest secret:\n");
}

std::string Contact::getFirstName(void)
{
	return firstName;
}
std::string Contact::getLastName(void)
{
	return lastName;
}

std::string Contact::getNickname(void)
{
	return nickname;
}

std::string Contact::getPhoneNumber(void)
{
	return phoneNum;
}

std::string Contact::getDarkestSecret(void)
{
	return darkestSecret;
}

