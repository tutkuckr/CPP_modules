/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:10:18 by tutku             #+#    #+#             */
/*   Updated: 2026/02/23 19:37:27 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void checkArgs(int argc, char *argv[])
{
	std::string str;

	if (argc != 4)
	{
		std::cerr << "There should be 3 parameters!" << std::endl;
		exit(1);
	}
	if (!argv[1] || !argv[2] || !argv[3])
	{
		std::cerr << "Invalid arguments!" << std::endl;
		exit(1);
	}
	str = argv[2];
	if (str.empty())
	{
		std::cerr << "s1 cannot be empty!" << std::endl;
		exit(1);
	}
}

void checkFile(const std::ios &file, const std::string &message)
{
	if (!file)
	{
		std::cerr << message << std::endl;
		exit(1);
	}
}
