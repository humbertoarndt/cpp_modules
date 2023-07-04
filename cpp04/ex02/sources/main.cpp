/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:25:41 by harndt            #+#    #+#             */
/*   Updated: 2023/07/04 11:14:07 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

/**
 * @brief Testing what the subject asked.
 * 
 */
void	testSubject(void)
{
	size_t			count = 3;
	
	/*
	Can a pointer to abstract class be created?
	
	Yes we can create a pointer to an abstract class, which could be actually 
	pointing to the objects of its derived classes. In this way, a container 
	of base class pointers can be created which can also store derived class 
	objects.

	https://www.geekinterview.com/question_details/87951
	https://stackoverflow.com/questions/5019046/reference-to-abstract-class
	*/
	const AAnimal	*animals[count];

	std::cout << "\nCalling Constructors=====================" << std::endl;
	for (size_t i = 0; i <= count; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	
	std::cout << "\nChecking Classes=========================" << std::endl;
	for (size_t i = 0; i <= count; i++)
	{
		if (i % 2)
		{
			std::cout << "Class Cat" << std::endl;
			std::cout << "Type: ";
			LOG(animals[i]->getType());
			std::cout << "makeSound: ";
			animals[i]->makeSound();
		}
		else
		{
			std::cout << "Class Dog" << std::endl;
			std::cout << "Type: ";
			LOG(animals[i]->getType());
			std::cout << "makeSound: ";
			animals[i]->makeSound();
		}
		std::cout << std::endl;
	}

	std::cout << "Calling Destructors======================" << std::endl;
	for (size_t i = 0; i <= count; ++i)
		delete animals[i];
}

int	main(void)
{
	testSubject();

	std::cout << "\nCalling Cat Constructors=================" << std::endl;
	Cat	cat;
	Cat	cat2;
	Cat	copyCat(cat);
	cat = cat2;

	std::cout << "\nDisplay Cats=============================" << std::endl;
	LOG(cat);
	LOG(copyCat);

	std::cout << "Change Cats Ideas========================" << std::endl;
	std::cout << "[cat]Idea number 42" << std::endl;
	LOG(cat.getIdea(42));
	std::string	empty("testing copy...");
	cat.setIdea(42, empty);
	LOG(cat.getIdea(42));

	std::cout << "[copyCat]Idea number 42" << std::endl;
	LOG(copyCat.getIdea(42));

	std::cout << "\nCalling Dog Constructors=================" << std::endl;
	Dog	dog;
	Dog	dog2;
	Dog	copyDog = dog;
	dog = dog2;

	std::cout << "\nDisplay Dogs=============================" << std::endl;
	LOG(dog);
	LOG(copyDog);

	std::cout << "Change Dogs Ideas========================" << std::endl;
	std::cout << "[dog]Idea number 42" << std::endl;
	LOG(dog.getIdea(42));
	empty = "testing assignment...";
	dog.setIdea(42, empty);
	LOG(dog.getIdea(42));

	std::cout << "[copyDog]Idea number 42" << std::endl;
	LOG(copyDog.getIdea(42));

	std::cout << "\nCalling Destructors======================" << std::endl;

	return(0);
}