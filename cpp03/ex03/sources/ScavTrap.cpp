/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:14:36 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 18:00:54 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Scav Trap:: Scav Trap object
 * 
 */
ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20)
{
	if (SHOW_MSG == true)
		LOG("⚫ ScavTrap Default constructor called");
	return ;
}

/**
 * @brief Construct a new Scav Trap:: Scav Trap object
 * 
 * @param name The new '_name'
 */
ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name, 100, 50, 20)
{
	if (SHOW_MSG == true)
		LOG("⚫ ScavTrap String constructor called");
	return ;
}

/**
 * @brief Construct a new Scav Trap:: Scav Trap object
 * 
 * @param src The ScavTrap object to be copied.
 */
ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	if (SHOW_MSG == true)
		LOG("⚫ ScavTrap Copy constructor called");
	return ;
}

/**
 * @brief Destroy the Scav Trap:: Scav Trap object
 * 
 */
ScavTrap::~ScavTrap(void)
{
	if (SHOW_MSG == true)
		LOG("⚫ ScavTrap Destructor called");
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return ScavTrap& A pointer to the assigned ScavTrap object.
 */
ScavTrap & ScavTrap::operator = (ScavTrap const &rhs)
{
	if (SHOW_MSG == true)
		LOG("⚫ ScavTrap Assignment operator called");
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Checks if the ScavTrap has energyPoints, then attacks its target
 and prints a log message.
 * 
 * @param target The name of its target.
 */
void	ScavTrap::attack(const std::string &target)
{
	if (!getEnergyPoints())
	{
		LOG("ScavTrap " << getName() << \
			" doesn't have any more energy!");
		return ;
	}
	LOG("ScavTrap " << getName() << " attacks " << target << \
		", causing " << getAttackDamage() << " points of damage!");
	setEnergyPoints(getEnergyPoints() - 1);
}

/**
 * @brief Turns the ScavTrap into keeper mode and prints a log message.
 * 
 */
void	ScavTrap::guardGate(void)
{
	LOG("ScavTrap is now in keeper mode.");
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream & operator << (std::ostream &o, ScavTrap const &i)
{
	o << "+---" << std::endl;
	o << "| ScavTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getEnergyPoints() << std::endl;
	o << "| Attack Damage: " << i.getAttackDamage() << std::endl;
	o << "+---" << std::endl;
	return (o);
}