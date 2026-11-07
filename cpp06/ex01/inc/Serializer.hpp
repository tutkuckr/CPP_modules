/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 15:36:48 by tutku             #+#    #+#             */
/*   Updated: 2026/11/07 18:11:43 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define GREEN "\033[1;32m"
#define RED "\033[31m"
#define PINK "\033[95m"
#define CYAN "\033[36m"
#define PURPLE "\033[35m"
#define BLUE "\033[34m"

class Serializer
{

	public:
		Serializer() = delete;
		Serializer &operator=(const Serializer &other) = delete;
		Serializer(const Serializer &other) = delete;
		~Serializer() = delete;

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
