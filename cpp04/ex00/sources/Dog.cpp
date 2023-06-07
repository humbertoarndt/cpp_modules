/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:44:46 by harndt            #+#    #+#             */
/*   Updated: 2023/06/06 13:58:41 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

Dog::Dog(void) : Animal("Dog")
{
	if (SHOW_MSG == true)
		LOG("🐕 Default constructor called")
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	if (SHOW_MSG == true)
		LOG("🐕 Copy constructor called")
	this->_type = src.getType();
	return ;
}

Dog::~Dog(void)
{
	if (SHOW_MSG == true)
		LOG("🐕 Destructor called")
}

// =============================================================================
// OPERATORS
// =============================================================================

Dog & Dog::operator = (Dog const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🐕 Assignment operator called")
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

std::ostream &operator << (std::ostream &o, Dog const &i)
{
	(void)i;
	o << "Dog";
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	Dog::makeSound(void) const
{
	LOG("Barking~~ wink wink~~")
}