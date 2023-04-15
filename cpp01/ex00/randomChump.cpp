/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:03:45 by harndt            #+#    #+#             */
/*   Updated: 2023/04/14 15:03:46 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief Creates a new Zombie object and announces its name.
 * 
 * @param name The Zombie's name.
 */
void	randomChump(std::string name)
{
	Zombie	z(name);
	z.announce();
}
