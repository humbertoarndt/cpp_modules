/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 18:08:02 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	LOG("\nCalling Constructors");
	ClapTrap	trap;
	ClapTrap	trap1("Marvin");
	ClapTrap	trap2("Wall-E");
	ClapTrap	trap3 = trap;
	ClapTrap	trap4 = trap3 = trap1;

	LOG("\nShow ClapTraps' Status");
	LOG(trap1);
	LOG(trap2);

	LOG("Update Marvins's Attack Damage");
	trap1.setAttackDamage(1);
	LOG(trap1);

	LOG("ClapTraps Showing Off");
	for (int i = 0; i < 3; i++)
	{
		trap1.attack("Wall-E");
		trap2.takeDamage(trap1.getAttackDamage());
	}

	LOG("\nShow ClapTraps' Status");
	LOG(trap1);
	LOG(trap2);

	LOG("Repairing Time");
	for (int i = 0; i < 3; i++)
		trap2.beRepaired(1);

	LOG("\nShow ClapTraps' Status");
	LOG(trap1);
	LOG(trap2);

	LOG("Calling Destructors");
	return (0);
}