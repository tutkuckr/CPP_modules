/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:18:06 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/28 23:58:28 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//TODO: set TEST_MODE 0 to run as normal
int main(int argc, char *argv[])
{

	if (TEST_MODE == 0)
	{
		if (argc != 2)
		{
			std::cout << RED << "Please enter input!" << RESET << std::endl;
			return 1;
		}
		
		std::string literal(argv[1]);
		ScalarConverter::convert(literal);
	}
	else
	{
		initTest();
	}

	return 0;
}

/*
Non displayable = the value can be converted to a char, but that character cannot be visibly printed.
					0    -> '\0'   null character
					7    -> '\a'   bell
					9    -> '\t'   tab
					10   -> '\n'   newline
					31   -> control character
					127  -> DEL

Impossible = the value cannot be represented as a valid char at all.
					300
					-42
					nan
					nanf
					+inf
					-inf
					+inff
					-inff

					
if (value cannot become a char)
    "impossible"
else if (char exists but is not printable)
    "Non displayable"
else
    print the char


| Value | Result |
| `65` | `'A'` |
| `97` | `'a'` |
| `32` | `' '` — printable |
| `10` | `Non displayable` |
| `0` | `Non displayable` |
| `127` | `Non displayable` |
| `300` | `impossible` |
| `-10` | `impossible` |
| `nan` | `impossible` |
*/
