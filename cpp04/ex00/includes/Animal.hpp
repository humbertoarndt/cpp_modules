/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:27:38 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 15:51:11 by harndt           ###   ########.fr       */
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

class Animal
{
	protected:
		std::string	_type;

	public:
		/* Orthodox Canonical Form methods */
		Animal(void);
		Animal(std::string const &type);
		Animal(Animal const &src);
		Animal &operator = (Animal const &rhs);
		virtual	~Animal(void);

		/* Member Functions */
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		
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

std::ostream &operator << (std::ostream &o, Animal const &i);