/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:39:29 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/07 17:34:53 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{

}

MateriaSource::MateriaSource(const MateriaSource &other)  : IMateriaSource(other)
{

}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{

}

MateriaSource::~MateriaSource()
{

}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}
