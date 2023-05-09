/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:33:22 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 19:50:37 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS & DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 * 
 */
ClapTrap::ClapTrap(void)
		: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (SHOW_MSG == true)
		LOG("ClapTrap Default constructor called");
	return ;
}

/**
 * @brief Construct a new Clap Trap:: Clap Trap object
 * 
 * @param name The '_name' value.
 */
ClapTrap::ClapTrap(std::string const name)
		: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (SHOW_MSG == true)
		LOG("ClapTrap String constructor called");
}

/**
 * @brief Construct a new ClapTrap:: ClapTrap object
 * 
 * @param src The ClapTrap object to be copied.
 */
ClapTrap::ClapTrap(ClapTrap const &src)
{
	if(SHOW_MSG == true)
		LOG("ClapTrap Copy constructor called");
	setName(src.getName());
	setHitPoints(src.getHitPoints());
	setEnergyPoints(src.getEnergyPoints());
	setAttackDamage(src.getAttackDamage());
	return ;
}

/**
 * @brief Destroy the Clap Trap:: Clap Trap object
 * 
 */
ClapTrap::~ClapTrap(void)
{
	if (SHOW_MSG == true)
		LOG("ClapTrap Destructor called");
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return ClapTrap& A pointer to the assigned ClapTrap object.
 */
ClapTrap & ClapTrap::operator = (ClapTrap const &rhs)
{
	if (SHOW_MSG == true)
		LOG("Copy Assignment operator called");
	if (this != &rhs)
	{
		setName(rhs.getName());
		setHitPoints(rhs.getHitPoints());
		setEnergyPoints(rhs.getEnergyPoints());
		setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

// =============================================================================
// GETTERS
// =============================================================================

/**
 * @brief Gets '_name'
 * 
 * @return std::string '_name'
 */
std::string	ClapTrap::getName(void) const
{
	return (_name);
}

/**
 * @brief Gets '_hitPoints'
 * 
 * @return int '_hitPoints'
 */
int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

/**
 * @brief Gets '_energyPoints'
 * 
 * @return int '_energyPoints'
 */
int	ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

/**
 * @brief Gets '_attackDamage'
 * 
 * @return int '_attackDamage'
 */
int	ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

// =============================================================================
// SETTERS
// =============================================================================

/**
 * @brief Sets '_name'
 * 
 * @param name New name.
 */
void	ClapTrap::setName(std::string const &name)
{
	_name = name;
}

/**
 * @brief Sets '_hitPoints'
 * 
 * @param hitPoints New value to '_hitPoints'
 */
void	ClapTrap::setHitPoints(int const hitPoints)
{
	_hitPoints = hitPoints;
}

/**
 * @brief Sets '_energyPoints'
 * 
 * @param energyPoints New value to '_energyPoints'
 */
void	ClapTrap::setEnergyPoints(int const energyPoints)
{
	_energyPoints = energyPoints;
}

/**
 * @brief Sets '_attackDamage'
 * 
 * @param attackDamage New value to '_attackDamage'
 */
void	ClapTrap::setAttackDamage(int const attackDamage)
{
	_attackDamage = attackDamage;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Checks if the ClapTrap has energyPoints, then attacks its target
 and prints a log message.
 * 
 * @param target The name of its target.
 */
void	ClapTrap::attack(const std::string &target)
{
	if (!getEnergyPoints())
	{
		LOG("ClapTrap " << getName() << \
			" doesn't have any more energy!");
		return ;
	}
	LOG("ClapTrap " << getName() << " attacks " << target << \
		", causing " << getAttackDamage() << " points of damage!");
	setEnergyPoints(getEnergyPoints() - 1);
}

/**
 * @brief Checks if the ClapTrap has hitPoints, then reduces it, and prints
 prints a log message.
 * 
 * @param amount The amount of damage taken.
 */
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!getHitPoints())
	{
		LOG("ClapTrap " << getName() << \
			" is beyond repair and can't sustain any more damage!");
		return ;
	}
	if ((unsigned int)getHitPoints() > amount)
	{
		setHitPoints(getHitPoints() - amount);
		LOG("ClapTrap " << getName() << \
			" takes " << amount << " damage! HP: " << getHitPoints());
	}
	else
	{
		LOG("ClapTrap " << getName() << \
			" takes " << getHitPoints() << " damage! HP: 0 ");
		setHitPoints(0);
	}
}

/**
 * @brief Checks if the ClapTrap still has energyPoint and can be repaired,
 then repairs it, and prints a log message
 * 
 * @param amount The amount of damage to repair.
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!getEnergyPoints())
	{
		LOG("ClapTrap " << getName() << \
			" doesn't have any more energy!");
		return ;
	}
	setHitPoints(getHitPoints() + amount);
	setEnergyPoints(getEnergyPoints() - 1);
	LOG("ClapTrap " << getName() << \
			" repairs " << amount << " hitpoints! HP: " << getHitPoints());
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream & operator << (std::ostream &o, ClapTrap const &i)
{
	o << "+---" << std::endl;
	o << "| ClapTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getEnergyPoints() << std::endl;
	o << "| Attack Damage: " << i.getAttackDamage() << std::endl;
	o << "+---" << std::endl;
	return (o);
}