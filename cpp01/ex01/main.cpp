/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:04:01 by harndt            #+#    #+#             */
/*   Updated: 2023/04/14 15:39:22 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies, zombie("Stack");

	zombies = zombieHorde(HORDE_SIZE, "Heap");
	for (int i = 0; i < HORDE_SIZE; i++)
		(zombies + i)->announce();
	zombie.announce();
	std::cout << std::endl;
	delete [] zombies;
	return (0);
}