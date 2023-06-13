/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:44:46 by harndt            #+#    #+#             */
/*   Updated: 2023/06/13 17:05:39 by harndt           ###   ########.fr       */
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
Dog::Dog(void) : AAnimal("Dog")
{
	if (SHOW_MSG == true)
		LOG("🐕 Default constructor called")
	this->_brain = new Brain();
	return ;
}

/**
 * @brief Construct a new Dog:: Dog object
 * 
 * @param src The Dog object to be copied.
 */
Dog::Dog(Dog const &src) : AAnimal(src)
{
	if (SHOW_MSG == true)
		LOG("🐕 Copy constructor called")
	this->_type = src.getType();
		/*
	Deep copy
	It's necessary to create a new Brain pointer, 
	otherwise all Dogs will share the same brain. Since 
	Dogs don't have a hive mind this is a problem, also 
	when using 'delete' to free memory the code will try 
	to free n times the same allocated memory.

	https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/
	*/
	this->_brain = new Brain(*src._brain);
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
	delete this->_brain;
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
		_brain = new Brain(*rhs._brain);
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
	o << "Type: " << i.getType() << std::endl;
	o << "Brain: " << i.getBrain() << std::endl;
	i.makeSound();
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

/**
 * @brief Gets an idea from the '_ideas[MAX_IDEAS]' array.
 * 
 * @param i size_t index.
 * @return std::string.
 */
std::string	Dog::getIdea(size_t i) const
{
	return(this->_brain->getIdea(i));
}

/**
 * @brief Sets an idea in the '_ideas[MAX_IDEAS]' array.
 * 
 * @param i size_t index.
* @param idea the idea to write in the 'i' postion.
 */
void	Dog::setIdea(size_t i, std::string &idea)
{
	this->_brain->setIdea(i, idea);
}

/**
 * @brief Gets the address to the '_brain' attribute
 * 
 * @return Brain* 
 */
Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}