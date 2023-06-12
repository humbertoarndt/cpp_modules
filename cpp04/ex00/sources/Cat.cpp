/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:52:30 by harndt            #+#    #+#             */
/*   Updated: 2023/06/12 16:43:51 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTORS
// =============================================================================

/**
 * @brief Construct a new Cat:: Cat object
 * 
 */
Cat::Cat(void) : Animal("Cat")
{
	if (SHOW_MSG == true)
		LOG("🐈 Default constructor called");
	return ;
}

/**
 * @brief Construct a new Cat:: Cat object
 * 
 * @param src The Cat object to be copied.
 */
Cat::Cat(Cat const &src) : Animal(src)
{
	if (SHOW_MSG == true)
		LOG("🐈 Copy constructor called");
	this->_type = src.getType();
	return ;
}

/**
 * @brief Destroy the Cat:: Cat object
 * 
 */
Cat::~Cat(void)
{
	if (SHOW_MSG == true)
		LOG("🐈 Destructor called");
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Cat& A pointer to the assigned Cat object.
 */
Cat & Cat::operator = (Cat const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🐈 Assignment operator called");
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream &operator << (std::ostream &o, Cat const &i)
{
	(void)i;
	o << "Cat";
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Prints a string.
 * 
 */
void	Cat::makeSound(void) const
{
	LOG("Meow~~");
}
