/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutku <tutku@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 16:53:25 by tutku             #+#    #+#             */
/*   Updated: 2026/03/22 20:19:11 by tutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	// const Animal *meta = new Animal();
// 	// const Animal *i = new Cat();
// 	// const Animal *j = new Dog();

// 	// std::cout << i->getType() << " " << std::endl;
// 	// std::cout << j->getType() << " " << std::endl;
	
// 	// i->makeSound(); // will output the cat sound!
// 	// j->makeSound();
// 	// meta->makeSound();

// 	const WrongAnimal *meta = new WrongAnimal();
// 	const WrongAnimal *i = new WrongCat();

// 	std::cout << i->getType() << std::endl;

// 	i->makeSound();
// 	meta->makeSound();

// 	delete i;
// 	delete meta;
// }

static void line(std::string title)
{
	std::cout << "\n========================================\n";
	std::cout << title << std::endl;
	std::cout << "========================================\n";
}

int main()
{
	line("1. BASIC CONSTRUCTION OF DIRECT OBJECTS");

	Animal a;
	std::cout << "Animal type: " << a.getType() << std::endl;
	a.makeSound();

	std::cout << std::endl;

	Dog dog;
	std::cout << "Dog type: " << dog.getType() << std::endl;
	dog.makeSound();

	std::cout << std::endl;

	Cat cat;
	std::cout << "Cat type: " << cat.getType() << std::endl;
	cat.makeSound();

	line("2. DIRECT OBJECT CALLS");
	std::cout << "Calling makeSound():" << std::endl;

	a.makeSound();
	dog.makeSound();
	cat.makeSound();

	line("3. POLYMORPHISM WITH BASE CLASS POINTERS");

	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "j type: " << j->getType() << std::endl;
	std::cout << "i type: " << i->getType() << std::endl;

	std::cout << "\nCalling makeSound() through Animal pointers:" << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	line("4. POLYMORPHISM WITH BASE CLASS REFERENCES");

	const Animal &refDog = dog;
	const Animal &refCat = cat;
	const Animal &refAnimal = a;

	std::cout << "refAnimal type: " << refAnimal.getType() << std::endl;
	refAnimal.makeSound();

	std::cout << "refDog type: " << refDog.getType() << std::endl;
	refDog.makeSound();

	std::cout << "refCat type: " << refCat.getType() << std::endl;
	refCat.makeSound();

	line("5. ARRAY OF BASE CLASS POINTERS");

	const Animal *animals[6];

	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	animals[4] = new Animal();
	animals[5] = new Dog();

	for (int idx = 0; idx < 6; idx++)
	{
		std::cout << "animals[" << idx << "] type: " << animals[idx]->getType() << std::endl;
		animals[idx]->makeSound();
	}

	line("6. TESTING DESTRUCTOR ORDER WITH LOCAL SCOPE");

	{
		std::cout << "Entering local scope..." << std::endl;

		Dog localDog;
		Cat localCat;
		Animal localAnimal;

		std::cout << "Inside scope:" << std::endl;
		localDog.makeSound();
		localCat.makeSound();
		localAnimal.makeSound();

		std::cout << "Leaving local scope..." << std::endl;
	}

	std::cout << "Local scope ended." << std::endl;

	line("7. TESTING DESTRUCTOR CHAINING THROUGH BASE POINTERS");

	const Animal *ptr1 = new Dog();
	const Animal *ptr2 = new Cat();
	const Animal *ptr3 = new Animal();

	std::cout << "Deleting ptr1" << std::endl;
	delete ptr1;

	std::cout << "Deleting ptr2" << std::endl;
	delete ptr2;

	std::cout << "Deleting ptr3" << std::endl;
	delete ptr3;

	line("8. WRONG ANIMAL / WRONG CAT TEST");

	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();

	std::cout << "WrongAnimal type: " << wa->getType() << std::endl;
	std::cout << "WrongCat through WrongAnimal* type: " << wc->getType() << std::endl;

	std::cout << "\nCalling makeSound() for wrong:" << std::endl;
	wa->makeSound();
	wc->makeSound();

	//WrongAnimal::makeSound() is NOT virtual
	//then wc->makeSound() should call WrongAnimal's sound, not WrongCat's

	line("9. DIRECT WRONGCAT OBJECT CALL");

	WrongCat wrongCat;
	std::cout << "WrongCat direct object type: " << wrongCat.getType() << std::endl;
	wrongCat.makeSound();

	//Direct object call uses WrongCat::makeSound() normally,
	//because the object itself is a WrongCat

	line("10. WRONG EXAMPLE WITH REFERENCES");

	const WrongAnimal &wrongRef = wrongCat;

	std::cout << "wrongRef type: " << wrongRef.getType() << std::endl;
	wrongRef.makeSound();

	//If makeSound() is not virtual in WrongAnimal,
	//this should still call WrongAnimal::makeSound()

	line("11. MORE MIXED POLYMORPHIC TESTS");

	const Animal *zoo[4];
	zoo[0] = new Cat();
	zoo[1] = new Dog();
	zoo[2] = new Cat();
	zoo[3] = new Dog();

	for (int idx = 0; idx < 4; idx++)
	{
		std::cout << "\nZoo animal #" << idx << std::endl;
		std::cout << "Type: " << zoo[idx]->getType() << std::endl;
		zoo[idx]->makeSound();
	}

	line("12. CLEANING REMAINING ANIMALS");

	delete meta;
	delete j;
	delete i;

	for (int idx = 0; idx < 6; idx++)
		delete animals[idx];

	delete wa;
	delete wc;

	for (int idx = 0; idx < 4; idx++)
		delete zoo[idx];

	line("END OF TESTS");
	return 0;
}
