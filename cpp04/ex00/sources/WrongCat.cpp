/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:27:28 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 15:46:39 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Default constructor called");
	return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Copy constructor called");
	this->_type = src.getType();
	return ;
}

WrongCat::~WrongCat(void)
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Destructor called");
	return ;
}

// =============================================================================
// OPERATORS OVERLOAD
// =============================================================================

WrongCat & WrongCat::operator = (WrongCat const &rhs)
{
	if (SHOW_MSG == true)
		LOG("❌🐈 Assignment operator called");
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	WrongCat::makeSound(void) const
{
	LOG("Not a meow");
}
