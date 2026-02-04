/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:40:52 by tutku             #+#    #+#             */
/*   Updated: 2026/02/04 12:02:03 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
	index = 0;
	total_contacts = 0;
	std::cout << "Enter one of the following commands:\n1.ADD\n2.SEARCH\n3.EXIT\n";
}

void PhoneBook::add(void)
{
	std::string	input;
	int			contactIndex;
	std::cout << "Adding new contact\n";
	contactIndex = index % 8;
	contact[contactIndex].add_contact();
	if (total_contacts != 8)
		total_contacts++;
	contactIndex++;
	index++;
}

std::string shortenStr(std::string str)
{
	if (str.size() > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	return (str);
}

// index, first name, last name, nickname
void PhoneBook::printContacts(void)
{
	int	i = 0;

	std::cout << "|" << std::setw(10) << std::right << "index"
			  << "|" << std::setw(10) << std::right << "first name"
			  << "|" << std::setw(10) << std::right << "last name"
			  << "|" << std::setw(10) << std::right << "nickname"
			  << std::endl;
	while(i < total_contacts)
	{
		std::cout << "|" << std::setw(10) << std::right << (i + 1)
				  << "|" << std::setw(10) << std::right << shortenStr(contact[i].getFirstName())
				  << "|" << std::setw(10) << std::right << shortenStr(contact[i].getLastName())
				  << "|" << std::setw(10) << std::right << shortenStr(contact[i].getNickname())
				  << std::endl;
		i++;
	}
}

void PhoneBook::printContactInfo(int index)
{
	std::cout << "First name: " << contact[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contact[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contact[index].getNickname() << std::endl;
	std::cout << "Phone number: " << contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact[index].getDarkestSecret() << std::endl;
}

int PhoneBook::get_index()
{
	std::string	index;

	std::cout << "Please enter the index\n";
	while (1)
	{
		if (!std::getline(std::cin, index))
			break;
		if (index.size() != 1 || !((index[0] - '0') > 0 && (index[0] - '0') <= total_contacts))
		{
			std::cout << "Digit is out of range!" << std::endl;
			continue;
		}
		if ((index[0] - '0') > total_contacts)
		{
			std::cout << "There are " << total_contacts << "contacts\n";
			continue;
		}
		return (index[0] - '0');
	}
}

void PhoneBook::search()
{
	int	index;

	if (total_contacts != 0)
	{
		printContacts();
		index = get_index() - 1;
		printContactInfo(index);
	}
	else
	{
		std::cout << "There are no saved contacts!\n\n";
	}
}
