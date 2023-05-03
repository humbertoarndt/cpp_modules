/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:14:57 by harndt            #+#    #+#             */
/*   Updated: 2023/05/03 15:41:02 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define SHOW_MSG true

// =============================================================================
// CONSTRUCTORS AND DESTRUCTOR
// =============================================================================

FragTrap::FragTrap(void) : ClapTrap("Default", 100, 100, 30)
{
	if (SHOW_MSG == true)
		LOG(YELLOW "FragTrap Default constructor called" EOC);
	return ;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name, 100, 100, 30)
{
	if (SHOW_MSG == true)
		LOG(YELLOW "FragTrap String constructor called" EOC);
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	if (SHOW_MSG == true)
		LOG(YELLOW "FragTrap Copy construtor called" EOC);
	return ;
	
}

FragTrap::~FragTrap(void)
{
	if (SHOW_MSG == true)
		LOG(YELLOW "FragTrap destructor called" EOC);
	return ;
}

// =============================================================================
// OPERATORS
// =============================================================================

FragTrap & FragTrap::operator = (FragTrap const &rhs)
{
	if (SHOW_MSG == true)
		LOG(YELLOW "ScavTrap Assignment operator called" EOC);
	if (this != &rhs)
		this->ClapTrap::operator = (rhs);
	return (*this);
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

void	FragTrap::highFivesGuy(void)
{
	LOG(YELLOW "FragTrap requests a high five!" EOC);
}

std::ostream & operator << (std::ostream  &o, FragTrap const &i)
{
	o << YELLOW << "+---" << std::endl;
	o << "| FragTrap" << std::endl;
	o << "| Name: " << i.getName() << std::endl;
	o << "| Hit Points: " << i.getHitPoints() << std::endl;
	o << "| Energy Points: " << i.getEnergyPoints() << std::endl;
	o << "| Attack Damage: " << i.getAttackDamage() << std::endl;
	o << "+---" << EOC << std::endl;
	return (o);
}