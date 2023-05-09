/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:21:14 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 11:31:32 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// =============================================================================
// CONSTRUCTOR AND DESCONTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Human B:: Human B object
 * 
 * @param name The HumanB's name.
 */
HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

/**
 * @brief Destroy the Human B:: Human B object
 * 
 */
HumanB::~HumanB(void)
{
	return ;
}

// =============================================================================
// MEMBERS FUNCTIONS
// =============================================================================

/**
 * @brief Makes the HumanB attack with its weapon.
 * 
 */
void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}

/**
 * @brief Sets a weapon to HumanB
 * 
 * @param weapon The weapon to be setted.
 */
void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
