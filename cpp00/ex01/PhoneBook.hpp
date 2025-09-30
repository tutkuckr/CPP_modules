/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:04:51 by tcakir-y          #+#    #+#             */
/*   Updated: 2025/09/30 19:45:30 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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