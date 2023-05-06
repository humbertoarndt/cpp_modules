/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:56 by harndt            #+#    #+#             */
/*   Updated: 2023/05/06 12:12:00 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

DiamondTrap::DiamondTrap(void) 
			: ClapTrap("Default", 100, 50, 30), ScavTrap(), FragTrap()
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap Default constructor called" EOC);
	return ;
}

DiamondTrap::DiamondTrap(std::string const &name)
			: ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(),
			FragTrap(), _name(name)
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap String constructor called" EOC);
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(), FragTrap()
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap Copy constructor called" EOC);
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap destructor called" EOC);
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

DiamondTrap & DiamondTrap::operator = (DiamondTrap const &rhs)
{
	if (SHOW_MSG)
		LOG(GREEN "DiamondTrap Assignment operator called" EOC);
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return (*this);
}

// =============================================================================
// GET / SET
// =============================================================================

std::string	DiamondTrap::getName(void) const
{
	return (_name);
}

void	DiamondTrap::setName(std::string const &name)
{
	_name = name;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	LOG(GREEN << "I am " << getName() << ", grandchild of " \
		<< ClapTrap::getName() << EOC);
}

std::ostream & operator << (std::ostream &o, DiamondTrap const &i)
{
	o << GREEN << "+---" << std::endl;
	o << "| ClapTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getEnergyPoints() << std::endl;
	o << "| Attack Damage: " << i.getAttackDamage() << std::endl;
	o << "+---" << EOC << std::endl;
	return (o);
}