/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:53:25 by tutku             #+#    #+#             */
/*   Updated: 2026/03/27 22:44:48 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

static void printTitle(const std::string &title)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main()
{
	printTitle("1. BASIC POLYMORPHISM TEST");

	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "Sounds:" << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	std::cout << "Deleting through Animal pointers..." << std::endl;
	delete dog;
	delete cat;

	printTitle("2. ARRAY OF ANIMAL POINTERS");

	const int size = 6;
	Animal *animals[size];

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	std::cout << "Printing all animal types and sounds:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "animals[" << i << "] type: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	std::cout << std::endl;
	std::cout << "Deleting all animals from array..." << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];

	printTitle("3. DOG IDEAS TEST");

	Dog basicDog;
	basicDog.setIdea(0, "Chase cat");
	basicDog.setIdea(1, "Eat food");
	basicDog.setIdea(2, "Sleep");

	std::cout << "basicDog idea[0]: " << basicDog.getIdea(0) << std::endl;
	std::cout << "basicDog idea[1]: " << basicDog.getIdea(1) << std::endl;
	std::cout << "basicDog idea[2]: " << basicDog.getIdea(2) << std::endl;

	printTitle("4. CAT IDEAS TEST");

	Cat basicCat;
	basicCat.setIdea(0, "Ignore human");
	basicCat.setIdea(1, "Knock glass");
	basicCat.setIdea(2, "Sleep on keyboard");

	std::cout << "basicCat idea[0]: " << basicCat.getIdea(0) << std::endl;
	std::cout << "basicCat idea[1]: " << basicCat.getIdea(1) << std::endl;
	std::cout << "basicCat idea[2]: " << basicCat.getIdea(2) << std::endl;

	printTitle("5. DOG COPY CONSTRUCTOR DEEP COPY TEST");

	Dog originalDog;
	originalDog.setIdea(0, "Original dog idea 0");
	originalDog.setIdea(1, "Original dog idea 1");

	Dog copiedDog(originalDog);

	std::cout << "Before change:" << std::endl;
	std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copiedDog idea[0]:   " << copiedDog.getIdea(0) << std::endl;

	originalDog.setIdea(0, "Changed original dog idea 0");

	std::cout << std::endl;
	std::cout << "After changing originalDog:" << std::endl;
	std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copiedDog idea[0]:   " << copiedDog.getIdea(0) << std::endl;

	std::cout << std::endl;

	printTitle("6. CAT COPY CONSTRUCTOR DEEP COPY TEST");

	Cat originalCat;
	originalCat.setIdea(0, "Original cat idea 0");
	originalCat.setIdea(1, "Original cat idea 1");

	Cat copiedCat(originalCat);

	std::cout << "Before change:" << std::endl;
	std::cout << "originalCat idea[0]: " << originalCat.getIdea(0) << std::endl;
	std::cout << "copiedCat idea[0]:   " << copiedCat.getIdea(0) << std::endl;

	originalCat.setIdea(0, "Changed original cat idea 0");

	std::cout << std::endl;
	std::cout << "After changing originalCat:" << std::endl;
	std::cout << "originalCat idea[0]: " << originalCat.getIdea(0) << std::endl;
	std::cout << "copiedCat idea[0]:   " << copiedCat.getIdea(0) << std::endl;

	std::cout << std::endl;

	printTitle("7. DOG COPY ASSIGNMENT DEEP COPY TEST");

	Dog dogA;
	Dog dogB;

	dogA.setIdea(0, "DogA first idea");
	dogA.setIdea(1, "DogA second idea");
	dogB.setIdea(0, "DogB old idea");

	std::cout << "Before assignment:" << std::endl;
	std::cout << "dogA idea[0]: " << dogA.getIdea(0) << std::endl;
	std::cout << "dogB idea[0]: " << dogB.getIdea(0) << std::endl;

	dogB = dogA;

	std::cout << std::endl;
	std::cout << "After assignment:" << std::endl;
	std::cout << "dogA idea[0]: " << dogA.getIdea(0) << std::endl;
	std::cout << "dogB idea[0]: " << dogB.getIdea(0) << std::endl;

	dogA.setIdea(0, "DogA changed after assignment");

	std::cout << std::endl;
	std::cout << "After changing dogA again:" << std::endl;
	std::cout << "dogA idea[0]: " << dogA.getIdea(0) << std::endl;
	std::cout << "dogB idea[0]: " << dogB.getIdea(0) << std::endl;

	std::cout << std::endl;
	
	printTitle("8. CAT COPY ASSIGNMENT DEEP COPY TEST");

	Cat catA;
	Cat catB;

	catA.setIdea(0, "CatA first idea");
	catA.setIdea(1, "CatA second idea");
	catB.setIdea(0, "CatB old idea");

	std::cout << "Before assignment:" << std::endl;
	std::cout << "catA idea[0]: " << catA.getIdea(0) << std::endl;
	std::cout << "catB idea[0]: " << catB.getIdea(0) << std::endl;

	catB = catA;

	std::cout << std::endl;
	std::cout << "After assignment:" << std::endl;
	std::cout << "catA idea[0]: " << catA.getIdea(0) << std::endl;
	std::cout << "catB idea[0]: " << catB.getIdea(0) << std::endl;

	catA.setIdea(0, "CatA changed after assignment");

	std::cout << std::endl;
	std::cout << "After changing catA again:" << std::endl;
	std::cout << "catA idea[0]: " << catA.getIdea(0) << std::endl;
	std::cout << "catB idea[0]: " << catB.getIdea(0) << std::endl;

	std::cout << std::endl;

	printTitle("9. POLYMORPHIC DELETE TEST");

	Animal *polyDog = new Dog();
	Animal *polyCat = new Cat();

	std::cout << "Deleting polyDog and polyCat through Animal*..." << std::endl;
	delete polyDog;
	delete polyCat;

	printTitle("10. END OF TESTS");

	return 0;
}
