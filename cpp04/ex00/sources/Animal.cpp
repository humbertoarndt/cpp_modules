/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:33:53 by harndt            #+#    #+#             */
/*   Updated: 2023/06/06 14:50:54 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTORS
// =============================================================================

Animal::Animal(void) : _type("Undefined")
{
	if (SHOW_MSG == true)
		LOG("🧬 Default constructor called");
	return ;
}

Animal::Animal(std::string const &type) : _type(type)
{
	if (SHOW_MSG == true)
		LOG("🧬 String constructor called");
	return ;
}

Animal::Animal(Animal const &src)
{
	if (SHOW_MSG == true)
		LOG("🧬 Copy constructor called");
	this->_type = src.getType();
	return ;
}

Animal::~Animal(void)
{
	if (SHOW_MSG == true)
		LOG("🧬 Destructor called");
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

Animal & Animal::operator = (Animal const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🧬 Assignment operator called");
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

std::ostream &operator << (std::ostream &o, Animal const &i)
{
	(void)i;
	o << "Animal";
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	LOG("ahah.wav");
}
