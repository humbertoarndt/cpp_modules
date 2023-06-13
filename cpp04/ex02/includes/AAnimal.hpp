/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:27:38 by harndt            #+#    #+#             */
/*   Updated: 2023/06/13 17:04:19 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include <iostream>

// =============================================================================
// MACROS
// =============================================================================

#define LOG(x) std::cout << x << std::endl;

// =============================================================================
// CLASS
// =============================================================================


/*
 What is an Abstract Class?
 
 An abstract class is a class that is designed to be specifically used as a base
 class. An abstract class contains at least one pure virtual function. You 
 declare a pure virtual function by using a pure specifier ( = 0 ) in the 
 declaration of a virtual member function in the class declaration.

 https://www.ibm.com/docs/en/zos/2.4.0?topic=only-abstract-classes-c
*/
class AAnimal
{
	protected:
		std::string	_type;

	public:
		/* Orthodox Canonical Form methods */
		AAnimal(void);
		AAnimal(std::string const &type);
		AAnimal(AAnimal const &src);
		AAnimal &operator = (AAnimal const &rhs);
		virtual	~AAnimal(void);

		/* Member Functions */
		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
		
		/*
		What is a virtual function in inheritance?
		
		A virtual function allows derived classes to replace the 
		implementation provided by the base class. The compiler makes 
		sure the replacement is always called whenever the object in 
		question is actually of the derived class, even if the object 
		is accessed by a base pointer rather than a derived pointer.
		https://isocpp.org/wiki/faq/virtual-functions
		*/
};

std::ostream &operator << (std::ostream &o, AAnimal const &i);