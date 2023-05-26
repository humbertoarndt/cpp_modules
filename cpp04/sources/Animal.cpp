/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:33:53 by harndt            #+#    #+#             */
/*   Updated: 2023/05/17 15:57:45 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTORS
// =============================================================================

Animal::Animal(void)
{
	if (SHOW_MSG == true)
		LOG("Animal constructor called");
	return ;
}

Animal::Animal(Animal const &src)
{
	if (SHOW_MSG == true)
		LOG("Animal Copy constructor called");
	*this = src;
	return ;
}

Animal::~Animal(void)
{
	if (SHOW_MSG == true)
		LOG("Animal destructor called");
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

Animal & Animal::operator = (Animal const &rhs)
{
	if (SHOW_MSG == true)
		LOG("Animal Assignment operator called");
	if (this != &rhs)
		type = rhs.type;
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
	return (type);
}

void	Animal::makeSound(void) const
{
	LOG("Humberto");
}