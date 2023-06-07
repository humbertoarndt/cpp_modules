/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:14:57 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 18:02:45 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 * 
 */
FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30)
{
	if (SHOW_MSG == true)
		LOG("🔴 FragTrap Default constructor called");
	return ;
}

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 * 
 * @param name 
 */
FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30)
{
	if (SHOW_MSG == true)
		LOG("🔴 FragTrap String constructor called");
	return ;
}

/**
 * @brief Construct a new Frag Trap:: Frag Trap object
 * 
 * @param src The FragTrap object to be copied.
 */
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	if (SHOW_MSG == true)
		LOG("🔴 FragTrap Copy construtor called");
	return ;
	
}

/**
 * @brief Destroy the Frag Trap:: Frag Trap object
 * 
 */
FragTrap::~FragTrap(void)
{
	if (SHOW_MSG == true)
		LOG("🔴 FragTrap destructor called");
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

/**
 * @brief Overload for the '=' operator.
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return FragTrap& A pointer to the assigned FragTrap object.
 */
FragTrap & FragTrap::operator = (FragTrap const &rhs)
{
	if (SHOW_MSG == true)
		LOG("🔴 FragTrap Assignment operator called");
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief The FragTrap prints a message asking for a high five
 * 
 */
void	FragTrap::highFivesGuy(void)
{
	LOG("FragTrap requests a high five!");
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
std::ostream & operator << (std::ostream  &o, FragTrap const &i)
{
	o << "+---" << std::endl;
	o << "| FragTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getEnergyPoints() << std::endl;
	o << "| Attack Damage: " << i.getAttackDamage() << std::endl;
	o << "+---" << std::endl;
	return (o);
}