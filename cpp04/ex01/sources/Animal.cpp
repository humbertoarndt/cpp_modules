/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:33:53 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 17:42:43 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTORS
// =============================================================================

/**
 * @brief Construct a new Animal:: Animal object
 * 
 */
Animal::Animal(void) : _type("Undefined")
{
	if (SHOW_MSG == true)
		LOG("🧬 Default constructor called");
	return ;
}

/**
 * @brief Construct a new Animal:: Animal object
 * 
 * @param type The Animal '_type'
 */
Animal::Animal(std::string const &type) : _type(type)
{
	if (SHOW_MSG == true)
		LOG("🧬 String constructor called");
	return ;
}

/**
 * @brief Construct a new Animal:: Animal object
 * 
 * @param src The Animal object to be copied.
 */
Animal::Animal(Animal const &src)
{
	if (SHOW_MSG == true)
		LOG("🧬 Copy constructor called");
	this->_type = src.getType();
	return ;
}

/**
 * @brief Destroy the Animal:: Animal object
 * 
 */
Animal::~Animal(void)
{
	if (SHOW_MSG == true)
		LOG("🧬 Destructor called");
	return ;
}

// =============================================================================
// OPERATOR
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Animal& A pointer to the assigned Animal object.
 */
Animal & Animal::operator = (Animal const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🧬 Assignment operator called");
	if (this != &rhs)
		_type = rhs._type;
	return (*this);
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream &operator << (std::ostream &o, Animal const &i)
{
	(void)i;
	o << "Animal";
	return (o);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Gets the '_type' attributes.
 * 
 * @return std::string '_type'
 */
std::string	Animal::getType(void) const
{
	return (_type);
}

/**
 * @brief Prints a string.
 * 
 */
void	Animal::makeSound(void) const
{
	LOG("ahah.wav");
}
