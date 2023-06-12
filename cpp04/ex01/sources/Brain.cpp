/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:55:36 by harndt            #+#    #+#             */
/*   Updated: 2023/06/12 16:42:09 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Brain:: Brain object
 * 
 */
Brain::Brain(void)
{
	if (SHOW_MSG == true)
		LOG("🧠 Default constructor called");
	std::string ideas[MAX_IDEAS] = {
									"zeroBerto", "umBerto", "doisBerto",
									"trêsBerto", "quatroBerto", "cincoBerto",
									"seisBerto", "seteBerto", "oitoBerto",
									"noveBerto", "dezBerto", "onzeBerto",
									"dozeBerto", "trezeBerto", "quatorzeBerto",
									"quinzeBerto", "dezesseisBerto", "dezesseteBerto",
									"dezoitoBerto", "dezenoveBerto", "vinteBerto",
									"vinte e umBerto", "vinte e doisBerto",
									"vinte e trêsBerto", "vinte e quatroBerto",
									"vinte e cincoBerto", "vinte e seisBerto",
									"vinte e seteBerto", "vinte e oitoBerto",
									"vinte e noveBerto", "trintaBerto",
									"trinta e umBerto", "trinta e doisBerto",
									"trinta e trêsBerto", "trinta e quatroBerto",
									"trinta e cincoBerto", "trinta e seisBerto",
									"trinta e seteBerto", "trinta e oitoBerto",
									"trinta e noveBerto", "quarentaBerto",
									"quarenta e umBerto", "quarenta e doisBerto",
									"quarenta e trêsBerto", "quarenta e quatroBerto",
									"quarenta e cincoBerto", "quarenta e seisBerto",
									"quarenta e seteBerto", "quarenta e oitoBerto",
									"quarenta e noveBerto", "cinquentaBerto",
									"cinquenta e umBerto", "cinquenta e doisBerto",
									"cinquenta e trêsBerto", "cinquenta e quatroBerto",
									"cinquenta e cincoBerto", "cinquenta e seisBerto",
									"cinquenta e seteBerto", "cinquenta e oitoBerto",
									"cinquenta e noveBerto", "sessentaBerto",
									"sessenta e umBerto", "sessenta e doisBerto",
									"sessenta e trêsBerto", "sessenta e quatroBerto",
									"sessenta e cincoBerto", "sessenta e seisBerto",
									"sessenta e seteBerto", "sessenta e oitoBerto",
									"sessenta e noveBerto", "setentaBerto",
									"setenta e umBerto", "setenta e doisBerto",
									"setenta e trêsBerto", "setenta e quatroBerto",
									"setenta e cincoBerto", "setenta e seisBerto",
									"setenta e seteBerto", "setenta e oitoBerto",
									"setenta e noveBerto", "oitentaBerto",
									"oitenta e umBerto", "oitenta e doisBerto",
									"oitenta e trêsBerto", "oitenta e quatroBerto",
									"oitenta e cincoBerto", "oitenta e seisBerto",
									"oitenta e seteBerto", "oitenta e oitoBerto",
									"oitenta e noveBerto", "noventaBerto",
									"noventa e umBerto", "noventa e doisBerto",
									"noventa e trêsBerto", "noventa e quatroBerto",
									"noventa e cincoBerto", "noventa e seisBerto",
									"noventa e seteBerto", "noventa e oitoBerto",
									"noventa e noveBerto"
									};
	for (size_t i = 0; i < MAX_IDEAS; i++)
		this->_ideas[i] = ideas[i];
	return ;
}

/**
 * @brief Construct a new Brain:: Brain object
 * 
 * @param src The Brain object to be copied.
 */
Brain::Brain(Brain const &src)
{
	if (SHOW_MSG == true)
		LOG("🧠 Copy constructor  called")
	for (size_t i = 0; i < MAX_IDEAS; i++)
		this->_ideas[i] = src._ideas[i];
	return ;
}

/**
 * @brief Destroy the Brain:: Brain object
 * 
 */
Brain::~Brain(void)
{
	if (SHOW_MSG == true)
		LOG("🧠 Destructor called");
	return ;
}

// =============================================================================
// OPERATORS OVERLOAD
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Brain& A pointer to the assigned Brain object.
 */
Brain & Brain::operator = (Brain const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🧠 Assignment operator called");
	if (this != &rhs)
		for (size_t i = 0; i < MAX_IDEAS; i++)
			this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Gets an idea from the '_ideas[MAX_IDEAS]' array.
 * 
 * @param i size_t index.
 * @return std::string.
 */
std::string	Brain::getIdea(size_t i) const
{
	return (this->_ideas[i]);
}

/**
 * @brief Sets an idea in the '_ideas[MAX_IDEAS]' array.
 * 
 * @param i size_t index.
* @param idea the idea to write in the 'i' postion.
 */
void	Brain::setIdea(size_t i, std::string idea)
{
	this->_ideas[i] = idea;
}