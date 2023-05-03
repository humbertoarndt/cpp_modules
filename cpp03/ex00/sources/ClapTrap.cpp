/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:33:22 by harndt            #+#    #+#             */
/*   Updated: 2023/05/02 21:53:30 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS & DESTRUCTOR
// =============================================================================

ClapTrap::ClapTrap(void)
		: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (SHOW_MSG == true)
		LOG("ClapTrap Default constructor called");
	return ;
}

ClapTrap::ClapTrap(std::string const name)
		: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (SHOW_MSG == true)
		LOG("ClapTrap String constructor called");
}

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

ClapTrap::~ClapTrap(void)
{
	if (SHOW_MSG == true)
		LOG("ClapTrap Destructor called");
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

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

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

// =============================================================================
// SETTERS
// =============================================================================

void	ClapTrap::setName(std::string const &name)
{
	_name = name;
}

void	ClapTrap::setHitPoints(int const hitPoints)
{
	_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int const energyPoints)
{
	_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int const attackDamage)
{
	_attackDamage = attackDamage;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

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