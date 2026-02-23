/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 18:54:10 by tutku             #+#    #+#             */
/*   Updated: 2026/02/23 20:40:59 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

//copy the part until str1
//then copy str2
//move currPos str1.len() + found forward
//when out of the loop copy the rest
//add a new line
// void replaceFile(std::ifstream &file, std::ofstream &fileReplace, char **argv)
// {
// 	std::string line;
// 	size_t found;
// 	size_t currPos;
// 	std::string str1 = argv[2];
// 	std::string str2 = argv[3];

// 	while (std::getline(file, line)) 
// 	{
// 		currPos = 0;
// 		found = line.find(str1, currPos);
// 		while (found != std::string::npos)
// 		{
// 			fileReplace << line.substr(currPos, found - currPos);
// 			fileReplace<< str2;
// 			currPos = found + str1.length();
// 			found = line.find(str1, currPos);
// 		}
// 		fileReplace << line.substr(currPos) << "\n";
// 	}
// }

void replaceFile(std::ifstream &file, std::ofstream &fileReplace, char **argv)
{
	char c;
	std::string input = "";
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	size_t found;
	size_t currPos = 0;
	
	while (file.get(c))
	{
		input += c;
	}
	while ((found = input.find(str1, currPos)) != std::string::npos)
	{
		fileReplace << input.substr(currPos, found - currPos);
		fileReplace << str2;
		currPos = found + str1.length();
	}
	fileReplace << input.substr(currPos);
	
}

int main(int argc, char *argv[])
{
	checkArgs(argc, argv);
	std::string filename = argv[1];

	std::ifstream file(filename); // file to read from
	checkFile(file, "Error opening file!");

	std::ofstream fileReplace(filename + ".replace"); //file to write
	checkFile(fileReplace, "Error opening replace file!");
	replaceFile(file, fileReplace, argv);
	file.close();
	fileReplace.close();
	return (0);
}

/*
			TEST CASES
	./ex04 "tests/test1.txt" hello hi
	./ex04 "tests/test2.txt" aaa X
	./ex04 "tests/test3.txt" aa b
	./ex04 "tests/test4.txt" xyz 123		//s1 not found
	./ex04 "tests/test5.txt" remove ""		//deletion
	./ex04 "tests/test6.txt" world earth
	./ex04 "tests/test7.txt" a b
	./ex04 "tests/test8.txt" match replaced
	./ex04 "tests/test9.txt" a X
	./ex04 "tests/test10.txt" abc abcX
	./ex04 "tests/test11.txt" "\n" REPLACED
	./ex04 "tests/test12.txt" $'\n' X
	./ex04 "tests/test13.txt" abc xyz		//large size
	./ex04 "tests/test14.txt" same same		//s1==s2


	add a line without newline:
		printf "hello\nworld" > test6.txt
	empty file:
		touch test7.txt
	large input:
		yes "abc" | head -n 10000 > test13.txt
*/
/*
https://www.geeksforgeeks.org/cpp/cpp-string-functions/
ofstream: write
ifstream: read
fstream : read+write
*/
