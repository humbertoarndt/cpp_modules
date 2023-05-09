/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:59:22 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 11:30:42 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// =============================================================================
// CONSTRUCTOR && DECONSTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Human A:: Human A object
 * 
 * @param name The HumanA name.
 * @param weapon The HumanA weapon
 */
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

/**
 * @brief Destroy the Human A:: Human A object
 * 
 */
HumanA::~HumanA(void)
{
	return ;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Makes the HumanA attack with its weapon.
 * 
 */
void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon.getType() << std::endl;
}
