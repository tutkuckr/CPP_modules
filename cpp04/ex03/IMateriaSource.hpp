/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:26:38 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/08 20:15:48 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#define TOTAL_SLOT 4

class AMateria;

class IMateriaSource
{
	public:
		IMateriaSource(); //check
		IMateriaSource(const IMateriaSource &other);
		IMateriaSource &operator=(const IMateriaSource &other);
		virtual ~IMateriaSource() {};

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
