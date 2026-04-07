/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:39:51 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/07 15:44:39 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
