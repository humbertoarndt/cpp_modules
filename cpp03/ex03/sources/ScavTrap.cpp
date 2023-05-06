/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:14:36 by harndt            #+#    #+#             */
/*   Updated: 2023/05/06 11:39:31 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20)
{
	if (SHOW_MSG == true)
		LOG(WHITE "ScavTrap Default constructor called" EOC);
	return ;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20)
{
	if (SHOW_MSG == true)
		LOG(WHITE "ScavTrap String constructor called" EOC);
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	if (SHOW_MSG == true)
		LOG(WHITE "ScavTrap Copy constructor called" EOC);
	return ;
}

ScavTrap::~ScavTrap(void)
{
	if (SHOW_MSG == true)
		LOG(WHITE "ScavTrap Destructor called" EOC);
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

ScavTrap & ScavTrap::operator = (ScavTrap const &rhs)
{
	if (SHOW_MSG == true)
		LOG(WHITE "ScavTrap Assignment operator called" EOC);
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	ScavTrap::attack(const std::string &target)
{
	if (!getEnergyPoints())
	{
		LOG(WHITE "ScavTrap " << getName() << \
			" doesn't have any more energy!" EOC);
		return ;
	}
	LOG(WHITE "ScavTrap " << getName() << " attacks " << target << \
		", causing " << getAttackDamage() << " points of damage!" EOC);
	setEnergyPoints(getEnergyPoints() - 1);
}

void	ScavTrap::guardGate(void)
{
	LOG(WHITE "ScavTrap is now in keeper mode.");
}

std::ostream & operator << (std::ostream &o, ScavTrap const &i)
{
	o << WHITE << "+---" << std::endl;
	o << "| ScavTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getEnergyPoints() << std::endl;
	o << "| Attack Damage: " << i.getAttackDamage() << std::endl;
	o << "+---" << EOC << std::endl;
	return (o);
}