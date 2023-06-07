/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 18:07:17 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	LOG("\nCalling Constructors");
	ClapTrap	trap;
	ScavTrap	scav;
	ScavTrap	scav1("Marvin");
	ScavTrap	scav2("Wall-E");
	ScavTrap	scav3 = scav;
	ScavTrap	scav4 = scav3 = scav;

	LOG("\nShow Traps' Status");
	LOG(trap);
	LOG(scav1);
	LOG(scav2);

	LOG("ScavTraps Showing Off");
	for (int i = 0; i < 3; i++)
	{
		scav1.attack("Wall-E");
		scav2.takeDamage(scav1.getAttackDamage());
	}

	LOG("\nShow ScavTraps' Status");
	LOG(scav1);
	LOG(scav2);

	LOG("Guard Stance");
	scav2.guardGate();

	LOG("\nRepairing Time");
	for (int i = 0; i < 3; i++)
		scav2.beRepaired(20);

	LOG("\nShow ClapTraps' Status");
	LOG(scav1);
	LOG(scav2);

	LOG("Calling Destructors");
	return (0);
}