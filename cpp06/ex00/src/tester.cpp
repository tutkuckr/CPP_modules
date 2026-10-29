/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:41:49 by tutku             #+#    #+#             */
/*   Updated: 2026/10/28 23:57:23 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void runTest(const std::string &literal, const std::string &description)
{
	std::cout << CYAN << "----- " << description
			  << " -----" << RESET << std::endl;

	std::cout << GREEN << "Literal Input: " << RESET << "[" << literal << "]" << std::endl;

	ScalarConverter::convert(literal);

	std::cout << "--------------------------------\n"
			  << std::endl;
}

static void testSubject()
{
	std::cout << BLUE << "===== SUBJECT TESTS =====" << RESET << std::endl;

	runTest("0", "Integer zero");
	runTest("nan", "NaN");
	runTest("42.0f", "Float");
}

static void testChar()
{
	std::cout << BLUE << "===== CHAR TESTS =====" << RESET << std::endl;

	// Letters
	runTest("a", "Lowercase a");
	runTest("A", "Uppercase A");
	runTest("z", "Lowercase z");
	runTest("Z", "Uppercase Z");
	runTest("f", "Letter f - CHAR, not FLOAT");

	// Printable
	runTest("!", "Exclamation mark");
	runTest(" ", "Space");
	runTest("~", "Tilde");
	runTest("+", "Plus sign");
	runTest("-", "Minus sign");
	runTest(".", "Dot");
	runTest("@", "At sign");
	runTest("#", "Hash");
	runTest("?", "Question mark");
	runTest("\\", "Backslash");
	runTest("\"", "Double quote");
	runTest("'", "Single quote");

	// Digits
	runTest("0", "Digit 0(int)");
	runTest("9", "Digit 9(int)");

	// Invalid character input
	runTest("", "Empty input - Invalid literal");
	runTest("ab", "Multiple characters - Invalid");
	runTest("a ", "Character with space - Invalid");
	runTest(" a", "Character with space - Invalid");
}

static void testInt()
{
	std::cout << BLUE << "===== INT TESTS =====" << RESET << std::endl;

	// Normal integers
	runTest("42", "integer - char: '*'");
	runTest("65", "integer - char: 'A'");
	runTest("97", "integer - char: 'a'");
	runTest("100", "integer - char: 'd'");
	runTest("1", "integer 1 - Non displayable");

	// Zero and signs
	runTest("0", "Zero - Non displayable");
	runTest("-0", "Negative zero");
	runTest("+0", "Positive zero");
	runTest("+42", "Positive sign");
	runTest("-42", "Negative integer - char impossible");
	runTest("-1", "Negative one - char impossible");
	runTest("-10", "Negative ten - char impossible");

	// Leading zeros (decimal notation)
	runTest("00", "Multiple zeros");
	runTest("00042", "Leading zeros");
	runTest("+00042", "Positive sign and leading zeros");
	runTest("-00042", "Negative sign and leading zeros");

	// ASCII boundaries
	runTest("10", "ASCII 10 - Non displayable");
	runTest("31", "ASCII 31 - Non displayable");
	runTest("32", "ASCII 32 - Space");
	runTest("33", "ASCII 33 - '!'");
	runTest("64", "ASCII 64 - '@'");
	runTest("126", "ASCII 126 - '~'");
	runTest("127", "ASCII 127 - Non displayable");
	runTest("128", "ASCII 128 - char impossible");
	runTest("255", "ASCII range exceeded");

	// Other integers
	runTest("1000", "Large integer - char impossible");
	runTest("-1000", "Large negative integer");
	runTest("65535", "Large positive integer");

	// INT boundaries
	runTest("2147483647", "INT_MAX");
	runTest("-2147483648", "INT_MIN");
	runTest("2147483648", "Greater than INT_MAX");
	runTest("-2147483649", "Less than INT_MIN");

	// LONG LONG boundaries
	runTest("9223372036854775807", "LLONG_MAX");
	runTest("-9223372036854775808", "LLONG_MIN");
	runTest("9223372036854775808", "Greater than LLONG_MAX");
	runTest("-9223372036854775809", "Less than LLONG_MIN");

	// Precision loss
	runTest("16777216", "Exactly representable by float");
	runTest("16777217", "Float precision loss");
	runTest("9007199254740992", "Double precision boundary");
	runTest("9007199254740993", "Double precision loss");

	// Large integer that fits double but not float
	runTest("9999999999999999999999999999999999999999",
			"Very large integer - float overflow, double valid");
}

static void testFloat()
{
	std::cout << BLUE << "===== FLOAT TESTS =====" << RESET << std::endl;

	// Normal floats
	runTest("42.0f", "Float 42 - char '*'");
	runTest("65.0f", "Float 65 - char 'A'");
	runTest("97.0f", "Float 97 - char 'a'");
	runTest("1.0f", "Float one");
	runTest("100.0f", "Float 100 - char 'd'");

	// Decimal truncation
	runTest("42.5f", "42.5f - int becomes 42");
	runTest("42.9f", "42.9f - int becomes 42");
	runTest("65.9f", "65.9f - char becomes 'A'");
	runTest("-42.9f", "-42.9f - int becomes -42");
	runTest("0.5f", "0.5f - int becomes 0");
	runTest("-0.5f", "-0.5f - int becomes 0");
	runTest("127.9f", "127.9f - char Non displayable");
	runTest("128.9f", "128.9f - char impossible");

	// Zero and signs
	runTest("0.0f", "Positive zero");
	runTest("-0.0f", "Negative zero");
	runTest("+0.0f", "Explicit positive zero");
	runTest("+42.0f", "Positive sign");
	runTest("-42.0f", "Negative sign");

	// ASCII boundaries
	runTest("31.0f", "ASCII 31 - Non displayable");
	runTest("32.0f", "ASCII 32 - Space");
	runTest("126.0f", "ASCII 126 - '~'");
	runTest("127.0f", "ASCII 127 - Non displayable");
	runTest("128.0f", "ASCII 128 - impossible");

	// INT boundaries
	runTest("2147483647.0f", "INT_MAX rounds to 2147483648");
	runTest("-2147483648.0f", "INT_MIN");
	runTest("2147483648.0f", "Greater than INT_MAX");
	runTest("-2147483900.0f", "Less than INT_MIN after rounding");

	// Float precision
	runTest("3.14f", "Decimal precision");
	runTest("0.1f", "Float precision - 0.1");
	runTest("1.23456789f", "Multiple decimal digits");
	runTest("123456789.0f", "Float precision loss");
	runTest("16777217.0f", "Float rounding at 2^24");

	// Alternative decimal formats
	runTest(".5f", "No digit before decimal point");
	runTest("5.f", "No digit after decimal point");
	runTest("0.f", "Zero without decimal digits");
	runTest("-.5f", "Negative decimal without leading zero");
	runTest("+.5f", "Positive decimal without leading zero");
	runTest("42.0F", "Uppercase F suffix");
	runTest("00042.050f", "Leading zeros");

	// Large float values in decimal notation
	runTest(std::string("34") + std::string(37, '0') + ".0f",
			"Large valid float near maximum");
	runTest(std::string("35") + std::string(37, '0') + ".0f",
			"Float overflow - parsing should be handled");

	// Special values
	runTest("nanf", "Float NaN");
	runTest("+inff", "Positive float infinity");
	runTest("-inff", "Negative float infinity");
}

static void testDouble()
{
	std::cout << BLUE << "===== DOUBLE TESTS =====" << RESET << std::endl;

	// Normal doubles
	runTest("42.0", "Double 42 - char '*'");
	runTest("65.0", "Double 65 - char 'A'");
	runTest("97.0", "Double 97 - char 'a'");
	runTest("1.0", "Double one");
	runTest("100.0", "Double 100 - char 'd'");

	// Decimal truncation
	runTest("42.5", "42.5 - int becomes 42");
	runTest("42.9", "42.9 - int becomes 42");
	runTest("65.9", "65.9 - char becomes 'A'");
	runTest("-42.9", "-42.9 - int becomes -42");
	runTest("0.5", "0.5 - int becomes 0");
	runTest("-0.5", "-0.5 - int becomes 0");
	runTest("127.9", "127.9 - char Non displayable");
	runTest("128.9", "128.9 - char impossible");

	// Zero and signs
	runTest("0.0", "Positive zero");
	runTest("-0.0", "Negative zero");
	runTest("+0.0", "Explicit positive zero");
	runTest("+42.0", "Positive sign");
	runTest("-42.0", "Negative sign");

	// ASCII boundaries
	runTest("31.0", "ASCII 31 - Non displayable");
	runTest("32.0", "ASCII 32 - Space");
	runTest("126.0", "ASCII 126 - '~'");
	runTest("127.0", "ASCII 127 - Non displayable");
	runTest("128.0", "ASCII 128 - impossible");

	// INT boundaries and truncation
	runTest("2147483647.0", "INT_MAX");
	runTest("-2147483648.0", "INT_MIN");
	runTest("2147483647.9", "Truncates to INT_MAX");
	runTest("-2147483648.9", "Truncates to INT_MIN");
	runTest("2147483648.0", "Greater than INT_MAX");
	runTest("-2147483649.0", "Less than INT_MIN");

	// Double to float precision
	runTest("3.14", "Double decimal precision");
	runTest("0.1", "Double 0.1 - float loses precision");
	runTest("1.234567890123456789", "Double precision limit");
	runTest("123456789.123456789", "Large value with decimals");
	runTest("16777217.0", "Float precision loss");
	runTest("1.0000000000000001", "Rounds to 1.0 as double");

	// Double values outside finite float range
	runTest("9999999999999999999999999999999999999999.0",
			"Double valid - float overflow");

	// Very small double value
	runTest("0.0000000000000000000000000000000000000000000001",
			"Tiny double - float may round to zero");

	// Alternative decimal formats
	runTest(".5", "No leading zero");
	runTest("5.", "No trailing decimal digit");
	runTest("-.5", "Negative decimal without leading zero");
	runTest("+.5", "Positive decimal without leading zero");
	runTest("00042.050", "Leading zeros");

	// Near double maximum - decimal notation
	runTest(std::string("17") + std::string(307, '0') + ".0",
			"Large valid double near maximum");
	runTest(std::string("18") + std::string(307, '0') + ".0",
			"Double overflow - parsing should be handled");

	// Special
	runTest("nan", "Double NaN");
	runTest("+inf", "Positive double infinity");
	runTest("-inf", "Negative double infinity");
}

static void testPseudo()
{
	std::cout << BLUE << "===== PSEUDO TESTS =====" << RESET << std::endl;

	runTest("nanf", "Float NaN");
	runTest("+inff", "Positive float infinity");
	runTest("-inff", "Negative float infinity");

	runTest("nan", "Double NaN");
	runTest("+inf", "Positive double infinity");
	runTest("-inf", "Negative double infinity");

	runTest("inf", "Infinity without sign");
}

static void testInvalid()
{
	std::cout << BLUE << "===== INVALID LITERAL TESTS =====" << RESET << std::endl;

	// Empty and malformed input
	runTest("", "Empty string");
	runTest(" ", "Single space - valid CHAR, not invalid");
	runTest(" 42", "Leading whitespace");
	runTest("42 ", "Trailing whitespace");
	runTest("hello", "Multiple letters");
	runTest("12a", "Letters mixed with digits");

	// Invalid signs
	runTest("++42", "Double positive sign");
	runTest("--42", "Double negative sign");
	runTest("+-42", "Mixed signs");
	runTest("-+42", "Mixed signs reversed");

	// Invalid decimal formats
	runTest("12..3", "Multiple dots");
	runTest("12.3.4", "Multiple decimal points");
	runTest("-.", "Minus sign and dot, no digits");
	runTest(".f", "Float without digits");
	runTest("-.f", "Negative float without digits");
	runTest("12.3.4f", "Multiple decimal points - float");

	// Invalid float suffixes
	runTest("42f", "No decimal point or exponent");
	runTest("123ff", "Multiple f suffixes");
	runTest("12.3ff", "Multiple f suffixes");
	runTest("12af", "Invalid character in float");
	runTest("42.0ff", "Extra float suffix");
	runTest("42.0f0", "Digits after suffix");

	// Unsupported types / formats
	runTest("0x2A", "Hexadecimal - subject requires decimal");
	runTest("0b1010", "Binary - subject requires decimal");
	runTest("42U", "Unsigned suffix");
	runTest("42.0L", "Long double suffix");
	runTest("1_000", "Invalid underscore separator");

	// Unsupported pseudo-literal spellings
	runTest("NAN", "Uppercase NAN - not required");
	runTest("NaN", "Mixed case NaN - not required");
	runTest("infinity", "Full infinity spelling - not required");
}

static void testLimits()
{
	std::cout << BLUE << "===== SCIENTIFIC / EXTREME TESTS ====="
			  << RESET << std::endl;


	runTest("1e3", "Scientific double - 1000.0");
	runTest("1e3f", "Scientific float - 1000.0f");
	runTest("1.5e3", "Scientific double - 1500.0");
	runTest("1.5e3f", "Scientific float - 1500.0f");
	runTest("1e-3", "Small scientific double");
	runTest("1e-3f", "Small scientific float");
	runTest("-1e3", "Negative scientific double");
	runTest("+1e3f", "Positive scientific float");

	// Float range boundaries
	runTest("3.4028234663852886e38f", "FLT_MAX");
	runTest("3.5e38f", "Float overflow");
	runTest("1.17549435e-38f", "Smallest normal positive float");
	runTest("1.40129846e-45f", "Smallest positive subnormal float");
	runTest("1e-50f", "Float underflow");

	// Double range boundaries
	runTest("1.7976931348623157e308", "DBL_MAX");
	runTest("1e309", "Double overflow");
	runTest("2.2250738585072014e-308", "Smallest normal positive double");
	runTest("4.9406564584124654e-324", "Smallest positive subnormal double");
	runTest("1e-400", "Double underflow");

	// C++ digit separator - optional extension
	runTest("1'000", "C++ digit separator - parser extension");
}

void initTest()
{
	testSubject();
	testChar();
	testInt();
	testFloat();
	testDouble();
	testPseudo();
	testInvalid();
	testLimits();
}
