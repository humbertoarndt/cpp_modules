/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:03:43 by harndt            #+#    #+#             */
/*   Updated: 2023/04/14 15:03:44 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a new Zombie object.
 * 
 * @param name The Zombie's name.
 * @return Zombie* Pointer to the create object.
 */
Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}
