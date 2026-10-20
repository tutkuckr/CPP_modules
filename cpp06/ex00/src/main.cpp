/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:18:06 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/10/20 15:06:08 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void testSubject()
{
	std::cout << BLUE << "===== SUBJECT TESTS =====" << RESET << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;
}

void testChar()
{
	std::cout << BLUE << "===== CHAR TESTS =====" << RESET << std::endl;

	ScalarConverter::convert("a"); // 97
	std::cout << std::endl;
	ScalarConverter::convert("A"); // 65
	std::cout << std::endl;
	ScalarConverter::convert("!"); // 33
	std::cout << std::endl;
	ScalarConverter::convert(" "); // 32
	std::cout << std::endl;
	ScalarConverter::convert("~"); // 126
	std::cout << std::endl;
	ScalarConverter::convert("+"); // 43
	std::cout << std::endl;
	ScalarConverter::convert("."); // 46
	std::cout << std::endl;
	ScalarConverter::convert("");
	std::cout << std::endl;
	ScalarConverter::convert("\0"); // non displayable
	std::cout << std::endl;
	//ScalarConverter::convert("nan"); // impossible
	//std::cout << std::endl;
}

void testInt()
{
	std::cout << BLUE << "===== INT TESTS =====" << RESET << std::endl;

	// Normal positive integers
	ScalarConverter::convert("42"); // char: '*'
	std::cout << std::endl;

	ScalarConverter::convert("65"); // char: 'A'
	std::cout << std::endl;

	ScalarConverter::convert("97"); // char: 'a'
	std::cout << std::endl;

	// Zero and signs
	ScalarConverter::convert("0"); // char: Non displayable
	std::cout << std::endl;

	ScalarConverter::convert("-10"); // char: impossible
	std::cout << std::endl;

	ScalarConverter::convert("-0"); // should become 0
	std::cout << std::endl;

	ScalarConverter::convert("+42"); // char: '*'
	std::cout << std::endl;

	ScalarConverter::convert("-42"); // char: impossible
	std::cout << std::endl;

	// ASCII / displayable boundaries
	ScalarConverter::convert("10"); // Non displayable
	std::cout << std::endl;

	ScalarConverter::convert("31"); // Non displayable
	std::cout << std::endl;

	ScalarConverter::convert("32"); // char: ' '
	std::cout << std::endl;

	ScalarConverter::convert("33"); // char: '!'
	std::cout << std::endl;

	ScalarConverter::convert("126"); // char: '~'
	std::cout << std::endl;

	ScalarConverter::convert("127"); // Non displayable
	std::cout << std::endl;

	ScalarConverter::convert("128"); // char: impossible
	std::cout << std::endl;

	// Other normal integers
	ScalarConverter::convert("1000"); // char: impossible
	std::cout << std::endl;

	ScalarConverter::convert("-1000"); // char: impossible
	std::cout << std::endl;

	// int limits
	ScalarConverter::convert("2147483647"); // INT_MAX
	std::cout << std::endl;

	ScalarConverter::convert("-2147483648"); // INT_MIN
	std::cout << std::endl;

	// Overflow
	ScalarConverter::convert("2147483648"); // > INT_MAX
	std::cout << std::endl;

	ScalarConverter::convert("-2147483649"); // < INT_MIN
	std::cout << std::endl;
}

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
		testSubject();
		testChar();
		testInt();
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
