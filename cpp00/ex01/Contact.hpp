/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:52:22 by tutku             #+#    #+#             */
/*   Updated: 2026/01/24 17:42:38 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string	firstName;
		std::string lastName;
		std::string	nickname;
		std::string	phoneNum;
		std::string	darkestSecret;
	public:
		Contact();
		void		add_contact();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getPhoneNumber();
		std::string	getDarkestSecret();
		void		setFirstName(std::string message);
		void		setLastName(std::string message);
		void		setNickname(std::string message);
		void		setPhoneNumber(std::string message);
		void		setDarkestSecret(std::string message);
};
#endif
