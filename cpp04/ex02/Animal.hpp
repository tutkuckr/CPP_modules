/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:56:53 by tutku             #+#    #+#             */
/*   Updated: 2026/03/27 22:36:28 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	private:

	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void makeSound() const = 0;
		std::string getType() const;
};
// https://www.geeksforgeeks.org/cpp/pure-virtual-functions-and-abstract-classes/
#endif

/*
A class becomes abstract if it has at least one pure virtual function
= 0 prevents instantiation.

Animal requires derived classes to provide makeSound behavior
*/
