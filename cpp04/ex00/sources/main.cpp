/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:25:41 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 17:38:47 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/**
 * @brief Prints polymorphism tests using classes pointers.
 * 
 */
void	pointersTest(void)
{
	std::cout << "Subject Tests Using Pointers:" << std::endl;
	std::cout << "[pointersTest] Constructors list:" << std::endl;
	
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const WrongAnimal *h = new WrongAnimal();
	const WrongAnimal *g = new WrongCat();
	
	/* Printing types */
	std::cout << "\n[pointersTest] Printing Types:" << std::endl;
	std::cout << "🧬 Animal: " << meta->getType() << " " << std::endl;
	std::cout << "🐕 Dog: " << j->getType() << " " << std::endl;
	std::cout << "🐈 Cat: " << i->getType() << " " << std::endl;
	std::cout << "❌🧬 WrongAnimal: " << h->getType() << " " << std::endl;
	std::cout << "❌🐈 WrongCat: " << g->getType() << " " << std::endl;

	/* Making Sounds */
	std::cout << "\n[pointersTest] Making Sounds:" << std::endl;
	std::cout << "❌🐈 WrongCat says: ";
	g->makeSound();
	std::cout << "❌🧬 WrongAnimal says: ";
	h->makeSound();
	std::cout << "🐈 Cat says: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "🐕 Dog says: ";
	j->makeSound();
	std::cout << "🧬 Animal says: ";
	meta->makeSound();

	std::cout << "\n[pointersTest] Destructors list:" << std::endl;

	delete g;
	delete h;
	delete i;
	delete j;
	delete meta;
}

/**
 * @brief Prints polymorphism tests using classes instances.
 * 
 */
void	noPointerTest(void)
{
	std::cout << "\nTests Without Pointers:" << std::endl;
	std::cout << "\n[noPointerTest] Constructors list:" << std::endl;
	const Animal pet1 = Animal();
	const Animal pet2 = Cat();
	const Animal pet3 = Dog();
	const WrongAnimal notPet1 = WrongAnimal();
	const WrongAnimal notPet2 = WrongCat();

	/* Printing types */
	std::cout << "\n[noPointerTest] Printing Types:" << std::endl;
	std::cout << "🧬 Animal: " << pet1.getType() << " " << std::endl;
	std::cout << "🐈 Cat: " << pet2.getType() << " " << std::endl;
	std::cout << "🐕 Dog: " << pet3.getType() << " " << std::endl;
	std::cout << "❌🧬 WrongAnimal: " << notPet1.getType() << " " << std::endl;
	std::cout << "❌🐈 WrongCat: " << notPet2.getType() << " " << std::endl;

	/* Making Sounds */
	std::cout << "\n[noPointerTest] Making Sounds:" << std::endl;
	std::cout << "🧬 Animal says: ";
	pet1.makeSound();
	std::cout << "🐈 Cat says: ";
	pet2.makeSound(); //will output the cat sound!
	std::cout << "🐕 Dog says: ";
	pet3.makeSound();
	std::cout << "❌🧬 WrongAnimal says: ";
	notPet1.makeSound();
	std::cout << "❌🐈 WrongCat says: ";
	notPet2.makeSound();

	std::cout << "\n[noPointerTest] Destructors list:" << std::endl;
}

int	main(void)
{
	/*
	Class Pointer VS Class Instance
	
	- Allocation on the heap is not as cheap as allocation on the stack.
	- Objects on the stack must be smaller, for variety of reasons 
	(cost of copy construction, locality of reference, stack overflow, etc.)
	- Using pointers and references can remove compilation dependencies and 
	consequently reduce the compilation times.
	- Objects on the stack are cleaned-up automatically in case of exceptions. 
	- Objects on the stack tend to be closer to each other in memory, 
	and this helps caching and paging.

	You can only use polymorphy with instance pointers or references, 
	not with instances.
	https://cplusplus.com/forum/general/37813/
	*/
	
	/* Subject tests */
	pointersTest();
	std::cout << "\n---------------------------" << std::endl;
	noPointerTest();

	return(0);
}