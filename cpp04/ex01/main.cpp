/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:53:25 by tutku             #+#    #+#             */
/*   Updated: 2026/04/10 12:46:15 by tcakir-y         ###   ########.fr       */
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
	printTitle("1. BASIC TEST");

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;

	std::cout << "Sounds:" << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	std::cout << std::endl;
	std::cout << "Deleting..." << std::endl;
	delete meta;
	delete j;
	delete i;

	printTitle("2. ARRAY OF ANIMAL POINTERS TEST");

	const int size = 6;
	Animal *animals[size];

	for (int k = 0; k < size / 2; k++)
		animals[k] = new Dog();

	for (int k = size / 2; k < size; k++)
		animals[k] = new Cat();

	std::cout << std::endl;
	std::cout << "Printing types and sounds from Animal* array:" << std::endl;
	for (int k = 0; k < size; k++)
	{
		std::cout << "animals[" << k << "] type = " << animals[k]->getType() << std::endl;
		animals[k]->makeSound();
	}

	std::cout << std::endl;
	std::cout << "Deleting..." << std::endl;
	for (int k = 0; k < size; k++)
		delete animals[k];

	printTitle("3. DOG IDEA STORAGE TEST");

	Dog basicDog;
	basicDog.setIdea(0, "Chase the postman");
	basicDog.setIdea(1, "Eat food");
	basicDog.setIdea(2, "Sleep");
	std::cout << std::endl;
	std::cout << "basicDog idea[0]: " << basicDog.getIdea(0) << std::endl;
	std::cout << "basicDog idea[1]: " << basicDog.getIdea(1) << std::endl;
	std::cout << "basicDog idea[2]: " << basicDog.getIdea(2) << std::endl;

	printTitle("4. CAT IDEA STORAGE TEST");

	Cat basicCat;
	basicCat.setIdea(0, "Ignore humans");
	basicCat.setIdea(1, "Break stuff");
	basicCat.setIdea(2, "Sleep 19 hours");
	std::cout << std::endl;
	std::cout << "basicCat idea[0]: " << basicCat.getIdea(0) << std::endl;
	std::cout << "basicCat idea[1]: " << basicCat.getIdea(1) << std::endl;
	std::cout << "basicCat idea[2]: " << basicCat.getIdea(2) << std::endl;

	printTitle("5. DOG COPY CONSTRUCTOR DEEP COPY TEST");

	Dog originalDog;

	std::cout << std::endl;
	originalDog.setIdea(0, "Original dog idea 0");
	originalDog.setIdea(1, "Original dog idea 1");
	originalDog.setIdea(2, "Original dog idea 2");
	std::cout << std::endl;

	Dog copiedDog(originalDog);
	std::cout << std::endl;
	
	std::cout << "Before changing original:" << std::endl;
	std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copiedDog idea[0]:   " << copiedDog.getIdea(0) << std::endl;
	
	originalDog.setIdea(0, "Changed original dog idea 0");
	std::cout << std::endl;

	std::cout << "After changing original:" << std::endl;
	std::cout << "originalDog idea[0]: " << originalDog.getIdea(0) << std::endl;
	std::cout << "copiedDog idea[0]:   " << copiedDog.getIdea(0) << std::endl;
	std::cout << std::endl;

	printTitle("6. CAT COPY CONSTRUCTOR DEEP COPY TEST");

	Cat originalCat;

	std::cout << std::endl;
	originalCat.setIdea(0, "Original cat idea 0");
	originalCat.setIdea(1, "Original cat idea 1");
	originalCat.setIdea(2, "Original cat idea 2");
	std::cout << std::endl;

	Cat copiedCat(originalCat);
	std::cout << std::endl;

	std::cout << "Before changing original:" << std::endl;
	std::cout << "originalCat idea[1]: " << originalCat.getIdea(1) << std::endl;
	std::cout << "copiedCat idea[1]:   " << copiedCat.getIdea(1) << std::endl;

	originalCat.setIdea(1, "Changed original cat idea 1");
	std::cout << std::endl;

	std::cout << "After changing original:" << std::endl;
	std::cout << "originalCat idea[1]: " << originalCat.getIdea(1) << std::endl;
	std::cout << "copiedCat idea[1]:   " << copiedCat.getIdea(1) << std::endl; //copiedCat should keep old value
	std::cout << std::endl;

	printTitle("7. DOG COPY ASSIGNMENT DEEP COPY TEST");

	Dog dogA;
	Dog dogB;

	std::cout << std::endl;
	dogA.setIdea(0, "DogA first idea");
	dogA.setIdea(1, "DogA second idea");
	dogB.setIdea(0, "DogB old idea");
	std::cout << std::endl;
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "dogA idea[0]: " << dogA.getIdea(0) << std::endl;
	std::cout << "dogB idea[0]: " << dogB.getIdea(0) << std::endl;
	std::cout << std::endl;

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

	std::cout << std::endl;
	catA.setIdea(0, "CatA first idea");
	catA.setIdea(1, "CatA second idea");
	catB.setIdea(0, "CatB old idea");
	std::cout << std::endl;

	std::cout << "Before assignment:" << std::endl;
	std::cout << "catA idea[0]: " << catA.getIdea(0) << std::endl;
	std::cout << "catB idea[0]: " << catB.getIdea(0) << std::endl;
	std::cout << std::endl;

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

	printTitle("9. POLYMORPHIC DELETION WITH IDEAS INSIDE");

	Animal *polyDog = new Dog();
	Animal *polyCat = new Cat();

	std::cout << std::endl;
	std::cout << "Created polyDog and polyCat as Animal*" << std::endl;
	std::cout << "Deleting now..." << std::endl;
	std::cout << std::endl;
	
	delete polyDog;
	delete polyCat;

	printTitle("10. END OF TESTS");
	
	return 0;
}
