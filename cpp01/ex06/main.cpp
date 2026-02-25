/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:51:49 by tutku             #+#    #+#             */
/*   Updated: 2026/02/25 17:00:37 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return (0);
}
