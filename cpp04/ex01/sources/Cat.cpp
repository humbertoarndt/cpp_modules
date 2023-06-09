/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:52:30 by harndt            #+#    #+#             */
/*   Updated: 2023/06/09 19:20:57 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTORS
// =============================================================================

Cat::Cat(void) : Animal("Cat")
{
	if (SHOW_MSG == true)
		LOG("🐈 Default constructor called");
	this->brain = new Brain();
	return ;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	if (SHOW_MSG == true)
		LOG("🐈 Copy constructor called");
	this->_type = src.getType();
	this->brain = src.brain;
	return ;
}

Cat::~Cat(void)
{
	if (SHOW_MSG == true)
		LOG("🐈 Destructor called");
	delete this->brain;
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

Cat & Cat::operator = (Cat const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🐈 Assignment operator called");
	if (this != &rhs)
	{
		_type = rhs.getType();
		brain = new Brain(*rhs.brain);
	}
	return (*this);
}

std::ostream &operator << (std::ostream &o, Cat const &i)
{
	(void)i;
	o << "Cat";
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	Cat::makeSound(void) const
{
	LOG("Meow~~");
}
