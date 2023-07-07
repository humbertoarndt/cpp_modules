/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:39:09 by harndt            #+#    #+#             */
/*   Updated: 2023/07/07 20:06:11 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// =============================================================================
// Includes
// =============================================================================

#include <cstdlib>	//std::rand(); std::srand()
#include <ctime>	//std::time();
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << RESET_COLOR<< std::endl;
#define ERROR(x) std::cerr << x << std::endl;
#define RESET_COLOR	"\033[0m"
#define MAGENTA		"\033[0;35m"
#define YELLOW		"\033[0;33m"
#define CYAN		"\033[0;36m"

// =============================================================================
// Functions
// =============================================================================

/**
 * @brief It randonly instanciates A, B, or C and returns.
 * 
 * @return Base* the instance as a Base pointer.
 */
Base	*generate(void)
{
	Base	*random;
	int		type = std::rand() % 3;
	
	switch (type)
	{
		case 0 : random = new A; break;
		case 1 : random = new B; break;
		case 2 : random = new C; break;
	}
	return (random);
}

/**
 * @brief Prints the actual type of the object pointed to by p: "A", "B" or "C"
 * 
 * @param p the Base pointer to check.
 */
void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		LOG(MAGENTA << "Class A.");
	}
	else if (dynamic_cast<B *>(p))
	{
		LOG(YELLOW<< "Class B.");
	}
	else if (dynamic_cast<C *>(p))
	{
		LOG(CYAN << "Class C.");
	}
	else
	{
		LOG("Invalid type.")
	}
}

/**
 * @brief Prints the actual type of the object referenced by p: "A", "B" or "C"
 * 
 * @param p the Base reference to check.
 */
void	identify(Base &p)
{
	try {(void)dynamic_cast<A &>(p);LOG(MAGENTA << "Class A.");}
	catch(std::exception &e) {}
	try {(void)dynamic_cast<B &>(p);LOG(YELLOW<< "Class B.");}
	catch(std::exception &e) {}
	try {(void)dynamic_cast<C &>(p);LOG(CYAN << "Class C.");}
	catch(std::exception &e) {}
}

/* dynamic_cast<type>
   Use dynamic_cast for converting pointers/references within an inheritance hierarchy.

   https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
*/

int	main(void)
{
	/* Set seed for random number generator */
	std::srand(std::time(0));
	Base *random;

	for (int i = 0; i < 10; i++)
	{
		LOG("======== Test [" << i << "] ========");
		random = generate();
		LOG(">identify(Base *p)");
		identify(random);
		LOG("\n>identify(Base &p)");
		identify(*random);
		delete (random);
		LOG("");
	}
	return (0);
}
