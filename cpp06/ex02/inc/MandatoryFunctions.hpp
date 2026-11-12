/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MandatoryFunctions.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 03:32:37 by tutku             #+#    #+#             */
/*   Updated: 2026/11/12 04:04:05 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MANDATORYFUNCTIONS_HPP
#define MANDATORYFUNCTIONS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <exception>

#include <ctime>
#include <cstdlib>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
