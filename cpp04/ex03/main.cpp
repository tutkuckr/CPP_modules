/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcakir-y <tcakir-y@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:28:03 by tcakir-y          #+#    #+#             */
/*   Updated: 2026/04/10 10:29:12 by tcakir-y         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

static void printTitle(const std::string &title)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main()
{
	printTitle("1. SUBJECT'S TEST");

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	printTitle("2. UNKNOWN MATERIA NAME");

	src = new MateriaSource();

	src->learnMateria(new Ice());
	tmp = src->createMateria("fire");

	if (tmp == NULL)
		std::cout << "Unknown materia type returned NULL!" << std::endl;
	else
	{
		std::cout << "Error!" << std::endl; //unknown materia should have returned NULL!
		delete tmp;
	}
	delete src;

	printTitle("3. LEARN MORE THAN 4 MATERIAS");

	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	src->learnMateria(new Ice()); //learn slot is 4

	delete src;

	printTitle("4. EQUIP AND USE INVENTORY");

	Character alice("alice");
	Character enemy("enemy");

	AMateria *ice1 = new Ice();
	AMateria *cure1 = new Cure();

	alice.equip(ice1);
	alice.equip(cure1);

	alice.use(0, enemy);
	alice.use(1, enemy);

	std::cout << "invalid indexes:" << std::endl; //0-3 is valid
	alice.use(-1, enemy);
	alice.use(4, enemy);

	printTitle("5. EQUIP FULL INVENTORY");

	Character full("full");

	full.equip(new Ice());
	full.equip(new Cure());
	full.equip(new Ice());
	full.equip(new Cure());

	// 5th item should not fit
	full.equip(new Ice());

	full.use(0, enemy);
	full.use(1, enemy);
	full.use(2, enemy);
	full.use(3, enemy);

	printTitle("6. UNEQUIP TEST");

	Character dropper("dropper");

	dropper.equip(new Ice());
	dropper.equip(new Cure());

	std::cout << "Before unequip:" << std::endl;
	dropper.use(0, enemy);
	dropper.use(1, enemy);

	dropper.unequip(0);

	std::cout << "After unequip slot 0:" << std::endl;
	dropper.use(0, enemy);
	dropper.use(1, enemy);

	std::cout << "Trying invalid unequip:" << std::endl;
	dropper.unequip(-1);
	dropper.unequip(4);

	printTitle("7. CHARACTER COPY CONSTRUCTOR DEEP COPY TEST");

	Character original("original");

	original.equip(new Ice());
	original.equip(new Cure());

	std::cout << "Original uses before copy:" << std::endl;
	original.use(0, enemy);
	original.use(1, enemy);

	Character copied(original);

	std::cout << "Copied uses after copy constructor:" << std::endl;
	copied.use(0, enemy);
	copied.use(1, enemy);

	std::cout << "Unequipping original slot 0..." << std::endl;
	original.unequip(0);

	std::cout << "Original after unequip:" << std::endl;
	original.use(0, enemy);
	original.use(1, enemy);

	std::cout << "Copied should still keep its own materias:" << std::endl;
	copied.use(0, enemy);
	copied.use(1, enemy);

	printTitle("8. CHARACTER ASSIGNMENT OPERATOR DEEP COPY TEST");

	Character first("first");
	Character second("second");

	first.equip(new Ice());
	first.equip(new Cure());

	second.equip(new Cure());

	std::cout << "Before assignment:" << std::endl;
	std::cout << "first uses:" << std::endl;
	first.use(0, enemy);
	first.use(1, enemy);

	std::cout << "second uses:" << std::endl;
	second.use(0, enemy);
	second.use(1, enemy);

	second = first;

	std::cout << "After assignment:" << std::endl;
	std::cout << "first uses:" << std::endl;
	first.use(0, enemy);
	first.use(1, enemy);

	std::cout << "second uses:" << std::endl;
	second.use(0, enemy);
	second.use(1, enemy);

	std::cout << "Unequipping first slot 1..." << std::endl;
	first.unequip(1);

	std::cout << "first after unequip:" << std::endl;
	first.use(0, enemy);
	first.use(1, enemy);

	std::cout << "second still keeps its own copy:" << std::endl;
	second.use(0, enemy);
	second.use(1, enemy);

	printTitle("9. MATERIASOURCE COPY CONSTRUCTOR TEST");

	MateriaSource sourceA;
	sourceA.learnMateria(new Ice());
	sourceA.learnMateria(new Cure());

	MateriaSource sourceB(sourceA);

	AMateria *a1 = sourceA.createMateria("ice");
	AMateria *b1 = sourceB.createMateria("ice");
	AMateria *a2 = sourceA.createMateria("cure");
	AMateria *b2 = sourceB.createMateria("cure");

	Character tester("tester");

	tester.equip(a1);
	tester.equip(b1);
	tester.equip(a2);
	tester.equip(b2);

	tester.use(0, enemy);
	tester.use(1, enemy);
	tester.use(2, enemy);
	tester.use(3, enemy);

	printTitle("10. MATERIASOURCE ASSIGNMENT TEST");

	MateriaSource sourceC;
	sourceC.learnMateria(new Ice());

	MateriaSource sourceD;
	sourceD.learnMateria(new Cure());

	sourceD = sourceC;

	AMateria *d1 = sourceD.createMateria("ice");
	AMateria *d2 = sourceD.createMateria("cure");

	Character tester2("tester2");
	tester2.equip(d1);

	if (d2 == NULL)
		std::cout << "sourceD no longer holds cure" << std::endl; //after d(cure)=c(ice)
	else
	{
		std::cout << "Error!" << std::endl; //if sourceD still has old cure value
		delete d2;
	}

	tester2.use(0, enemy);

	printTitle("11. CLONE TEST");

	AMateria *base1 = new Ice();
	AMateria *clone1 = base1->clone();

	AMateria *base2 = new Cure();
	AMateria *clone2 = base2->clone();

	std::cout << "Original ice type: " << base1->getType() << std::endl;
	std::cout << "Cloned ice type:   " << clone1->getType() << std::endl;
	std::cout << "Original cure type:" << base2->getType() << std::endl;
	std::cout << "Cloned cure type:  " << clone2->getType() << std::endl;

	Character cloneUser("cloneUser");
	cloneUser.equip(clone1);
	cloneUser.equip(clone2);
	cloneUser.use(0, enemy);
	cloneUser.use(1, enemy);

	delete base1;
	delete base2;

	printTitle("12 ");

	IMateriaSource *polySrc = new MateriaSource();
	polySrc->learnMateria(new Ice());	//polySrc creates ice and cure objs
	polySrc->learnMateria(new Cure());

	//character equips and uses AMateria objs
	ICharacter *hero = new Character("hero");
	ICharacter *villain = new Character("villain");

	AMateria *p1 = polySrc->createMateria("ice");
	AMateria *p2 = polySrc->createMateria("cure");

	hero->equip(p1); //hero equips ice and cure objs
	hero->equip(p2);

	hero->use(0, *villain);
	hero->use(1, *villain);

	delete villain;
	delete hero;
	delete polySrc;

	printTitle("13. END OF PROGRAM");

	return 0;
}

//A class is concrete if it has no unimplemented pure virtual functions left.
//If even one pure virtual function is still not implemented, that class is still abstract.
//A class is concrete if it has no unimplemented pure virtual functions left.
/*
ICharacter = abstract interface
Character = concrete implementation
Character inherits from ICharacter
*/
