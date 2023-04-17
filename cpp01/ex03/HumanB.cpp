/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:21:14 by harndt            #+#    #+#             */
/*   Updated: 2023/04/17 12:30:28 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// =============================================================================
// CONSTRUCTOR AND DESCONTRUCTOR
// =============================================================================

HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

// =============================================================================
// MEMBERS FUNCTIONS
// =============================================================================

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
