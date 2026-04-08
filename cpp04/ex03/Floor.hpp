/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:37:04 by tutku             #+#    #+#             */
/*   Updated: 2026/04/08 20:08:58 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "MateriaSource.hpp"
#define TOTAL_DROP 10
class AMateria;

class Floor
{
	private:
		AMateria *dropped[TOTAL_DROP];
		unsigned int totalDropped;

	public:
		Floor();
		Floor(const Floor &other);
		Floor &operator=(const Floor &other);
		~Floor();

		void deleteDropped();
		void drop(AMateria *materia);
		void setDroppedToNull();
};

#endif
