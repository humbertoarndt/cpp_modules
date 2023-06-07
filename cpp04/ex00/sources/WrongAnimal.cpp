/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:39:57 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 15:59:49 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

WrongAnimal::WrongAnimal(void) : _type("WrongUndefined")
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Default constructor called");
	return ;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 String constructor called");
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Copy constructor called");
	this->_type = src.getType();
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Destructor called");
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

WrongAnimal & WrongAnimal::operator = (WrongAnimal const &rhs)
{
	if (SHOW_MSG == true)
		LOG("❌🧬 Assignment operator called");
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	LOG("Not ahah.wav");
}
