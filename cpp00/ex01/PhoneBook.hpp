/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:04:51 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/01/24 17:10:36 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <string>

/*
* array of contacts
* max 8 contacts, delete oldest one and replace with new one. if you add more
* no dynamic allocation
*/

class PhoneBook {
	private:
		Contact	contact[8];
		int		index;
		int		total_contacts;

	public:
		PhoneBook();
		void	search();
		void	add();
		void	exit();
		void	printContacts();
		void	printContactInfo(int index);
		int		get_index();
};

#endif

