/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:56 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 20:30:25 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Diamond Trap:: Diamond Trap object
 * 
 */
DiamondTrap::DiamondTrap(void) 
			: ClapTrap("Default", 100, 50, 30), ScavTrap(), FragTrap()
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap Default constructor called" EOC);
	return ;
}

/**
 * @brief Construct a new Diamond Trap:: Diamond Trap object
 * 
 * @param name The new '_name' value.
 */
DiamondTrap::DiamondTrap(std::string const &name)
			: ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(),
			FragTrap(), _name(name)
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap String constructor called" EOC);
	return ;
}

/**
 * @brief Construct a new Diamond Trap:: Diamond Trap object
 * 
 * @param src The DiamondTrap object to be copied.
 */
DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(), FragTrap()
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap Copy constructor called" EOC);
	return ;
}

/**
 * @brief Destroy the Diamond Trap:: Diamond Trap object
 * 
 */
DiamondTrap::~DiamondTrap(void)
{
	if (SHOW_MSG == true)
		LOG(GREEN "DiamondTrap destructor called" EOC);
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return DiamondTrap& A pointer to the assigned DiamondTrap object.
 */
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

/**
 * @brief Gets '_name'
 * 
 * @return std::string '_name'
 */
std::string	DiamondTrap::getName(void) const
{
	return (_name);
}

/**
 * @brief Sets '_name'
 * 
 * @param name New name
 */
void	DiamondTrap::setName(std::string const &name)
{
	_name = name;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Call ScavTrap 'attack' function.
 * 
 * @param target The name of its target.
 */
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/**
 * @brief Prints a message with the object name and its ClapTrap name.
 * 
 */
void	DiamondTrap::whoAmI(void)
{
	LOG(GREEN << "I am " << getName() << ", grandchild of " \
		<< ClapTrap::getName() << EOC);
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
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