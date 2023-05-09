/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:44:28 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 11:32:49 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// =============================================================================
// CONSTRUCTOR && DECONSTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Weapon:: Weapon object
 * 
 * @param type The weapon type.
 */
Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

/**
 * @brief Destroy the Weapon:: Weapon object
 * 
 */
Weapon::~Weapon(void)
{
	return ;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Gets the weapon type.
 * 
 * @return std::string const& _type
 */
std::string const	&Weapon::getType(void) const
{
	return _type;
}

/**
 * @brief Sets a new type of weapon.
 * 
 * @param new_type The new weapon type.
 */
void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}
