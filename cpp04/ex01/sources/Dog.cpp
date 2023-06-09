/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:44:46 by harndt            #+#    #+#             */
/*   Updated: 2023/06/09 19:21:01 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Dog:: Dog object
 * 
 */
Dog::Dog(void) : Animal("Dog")
{
	if (SHOW_MSG == true)
		LOG("🐕 Default constructor called")
	this->brain = new Brain();
	return ;
}

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * @param src The Dog object to be copied.
 */
Dog::Dog(Dog const &src) : Animal(src)
{
	if (SHOW_MSG == true)
		LOG("🐕 Copy constructor called")
	this->_type = src.getType();
	this->brain = src.brain;
	return ;
}

/**
 * @brief Destroy the Dog:: Dog object
 * 
 */
Dog::~Dog(void)
{
	if (SHOW_MSG == true)
		LOG("🐕 Destructor called")
	delete this->brain;
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Dog& A pointer to the assigned Dog object.
 */
Dog & Dog::operator = (Dog const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🐕 Assignment operator called")
	if (this != &rhs)
	{
		_type = rhs.getType();
		brain = new Brain(*rhs.brain);
	}
	return (*this);
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream &operator << (std::ostream &o, Dog const &i)
{
	(void)i;
	o << "Dog";
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Prints a string.
 * 
 */
void	Dog::makeSound(void) const
{
	LOG("Barking~~ wink wink~~")
}