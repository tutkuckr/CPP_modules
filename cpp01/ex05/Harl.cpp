/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:51:35 by tutku             #+#    #+#             */
/*   Updated: 2026/02/25 16:47:53 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Welcome to Harl's place!" << std::endl;
}

Harl::~Harl()
{
	std::cout << "See you!" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-specialketchup burger."
	<< "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money."
	<< "You did not put enough bacon in my burger!"
	<< "If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	<< "I’ve been coming for years,"
	<< "whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable!" 
	<< "I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[LEVELS])() =
		{
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};

	for (int i = 0; i < LEVELS; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cerr << "There is no such level!" << std::endl;
}
