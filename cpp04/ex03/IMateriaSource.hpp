/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:26:38 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/07 15:42:49 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource();
		IMateriaSource(const IMateriaSource &other);
		IMateriaSource &operator=(const IMateriaSource &other);
		virtual ~IMateriaSource();

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif