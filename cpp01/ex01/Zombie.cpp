/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:01 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 11:28:18 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// =============================================================================
// CONSTRUCTOR AND DESCONTRUCTOR
// =============================================================================

/**
 * @brief Construct a new Zombie:: Zombie object
 * 
 */
Zombie::Zombie(void)
{
	return ;
}

/**
 * @brief Construct a new Zombie:: Zombie object
 * 
 * @param name The zombie name
 */
Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

/**
 * @brief Destroy the Zombie:: Zombie object
 * 
 */
Zombie::~Zombie(void)
{
	std::cout << this->_name << " destroyed" << std::endl;
}

// =============================================================================
// MEMBER FUNCTIONS
// =============================================================================

/**
 * @brief Makes the Zombie object announces itself.
 * 
 */
void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 * @brief Sets a name to the Zombie object.
 * 
 * @param name The Zombie name.
 */
void	Zombie::setName(std::string name)
{
	this->_name = name;
}