/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:04:51 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/01/15 16:37:43 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
* array of contacts
* max 8 contacts, delete oldest one and replace with new one. if you add more
* no dynamic allocation
*/


class PhoneBook {
	public:
		void add();
		void search();
		void exit();
		class Contact {
			private:
				int			index;
				std::string	first_name;
				std::string	last_name;
				std::string	nickname;
		};
	
};
