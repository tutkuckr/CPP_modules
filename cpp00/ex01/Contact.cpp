/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:37:36 by tutku             #+#    #+#             */
/*   Updated: 2026/01/24 17:39:26 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNum = "";
	darkestSecret = "";
}

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
	setFirstName("Enter first name:\n");
	setLastName("Enter last name:\n");
	setNickname("Enter nickname:\n");
	setPhoneNumber("Enter phone number:\n");
	setDarkestSecret("Enter darkest secret:\n");
}

void Contact::setFirstName(std::string message)
{
	firstName = get_input(message);
}

std::string Contact::getFirstName(void)
{
	return firstName;
}

void Contact::setLastName(std::string message)
{
	lastName = get_input(message);
}

std::string Contact::getLastName(void)
{
	return lastName;
}

void Contact::setNickname(std::string message)
{
	nickname = get_input(message);
}

std::string Contact::getNickname(void)
{
	return nickname;
}

void Contact::setPhoneNumber(std::string message)
{
	bool flag = true;

	while (1)
	{
		phoneNum = get_input(message);
		if (phoneNum.size() != 10)
		{
			message = "Please enter a valid phone number(10 digits)!\n";
			continue;
		}
		for (size_t i = 0; i < phoneNum.size(); i++)
		{
			if (isdigit(phoneNum[i]) != 1)
			{
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag != true)
		{
			message = "Phone number must contain only digits!\n";
			continue;
		}
		break;
	}
}

std::string Contact::getPhoneNumber(void)
{
	return phoneNum;
}

void Contact::setDarkestSecret(std::string message)
{
	darkestSecret = get_input(message);
}

std::string Contact::getDarkestSecret(void)
{
	return darkestSecret;
}
