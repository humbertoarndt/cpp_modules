/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:33:53 by harndt            #+#    #+#             */
/*   Updated: 2023/06/13 17:01:46 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTORS
// =============================================================================

/**
 * @brief Construct a new AAnimal:: AAnimal object
 * 
 */
AAnimal::AAnimal(void) : _type("Undefined")
{
	if (SHOW_MSG == true)
		LOG("🧬 Default constructor called");
	return ;
}

/**
 * @brief Construct a new AAnimal:: AAnimal object
 * 
 * @param type The AAnimal '_type'
 */
AAnimal::AAnimal(std::string const &type) : _type(type)
{
	if (SHOW_MSG == true)
		LOG("🧬 String constructor called");
	return ;
}

/**
 * @brief Construct a new AAnimal:: AAnimal object
 * 
 * @param src The AAnimal object to be copied.
 */
AAnimal::AAnimal(AAnimal const &src)
{
	if (SHOW_MSG == true)
		LOG("🧬 Copy constructor called");
	this->_type = src.getType();
	return ;
}

/**
 * @brief Destroy the AAnimal:: AAnimal object
 * 
 */
AAnimal::~AAnimal(void)
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
 * @return AAnimal& A pointer to the assigned AAnimal object.
 */
AAnimal & AAnimal::operator = (AAnimal const &rhs)
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
std::ostream &operator << (std::ostream &o, AAnimal const &i)
{
	(void)i;
	o << "Abstract Animal";
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
std::string	AAnimal::getType(void) const
{
	return (_type);
}

/**
 * @brief Prints a string.
 * 
 */
void	AAnimal::makeSound(void) const
{
	LOG("ahah.wav");
}
