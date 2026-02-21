/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:37:41 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/02/21 14:59:06 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <climits>

static int checkDigits(std::string input)
{
	for (char c : input)
	{
		if (!isdigit(c))
			return 0;
	}
	return 1;
}

static int getZombieAmount()
{
	std::string	input;
	int			zombieAmount = 0;
	long int	enteredVal = 0;

	std::cout << "How many zombies would you like to create?" << std::endl;
	while (1)
	{
		if (!std::getline(std::cin, input))
			exit(0);
		if (input.empty() || !checkDigits(input))
		{
			std::cout << "Please enter a valid value!" << std::endl;
			continue;
		}
		try
		{
			enteredVal = stol(input);
		}
		catch(const std::exception& e)
		{
			std::cout << "Please enter a valid value :D!" << std::endl;
			continue;
		}
		if (enteredVal <= 0 || enteredVal > INT_MAX)
		{
			std::cout << "Please enter a valid value!" << std::endl;
			continue;
		}
		zombieAmount = enteredVal;
		break;
	}
	return (zombieAmount);
}

static std::string getZombieName()
{
	std::string input;

	std::cout << "Please enter the name for the zombies:" << std::endl;
	while (1)
	{
		if (!std::getline(std::cin, input))
			exit(0);
		if (input.empty())
		{
			std::cout << "Please enter zombie name!" << std::endl;
			continue;
		}
		break;
	}
	return (input);
}

int	main()
{
	int			zombieAmount = getZombieAmount();
	std::string	zombieName = getZombieName();
	Zombie		*horde = zombieHorde(zombieAmount, zombieName);
	int			i = 0;

	while (i < zombieAmount)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
