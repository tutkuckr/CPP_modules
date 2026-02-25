/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:51:35 by tutku             #+#    #+#             */
/*   Updated: 2026/02/25 17:28:27 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ " << "DEBUG" << " ]" << std::endl;
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-specialketchup burger."
			  << "I really do!\n"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ " << "INFO" << " ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
			  << "You did not put enough bacon in my burger!"
			  << "If you did, I would not be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ " << "WARNING" << " ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years,"
			  << "whereas you started working here just last month.\n"
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ " << "ERROR" << " ]" << std::endl;
	std::cout << "This is unacceptable!"
			  << "I want to speak to the manager now.\n"
			  << std::endl;
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
			switch (i)
			{
				case (0):
					(this->*functions[0])();
				case (1):
					(this->*functions[1])();
				case (2):
					(this->*functions[2])();
				case (3):
					(this->*functions[3])();
			}
			return;
		}
	}
	std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
}
