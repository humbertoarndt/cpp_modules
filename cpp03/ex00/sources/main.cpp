/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/05/03 15:42:16 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	LOG(PURPLE << "\nCalling Constructors" << EOC);
	ClapTrap	trap;
	ClapTrap	trap1("Marvin");
	ClapTrap	trap2("Wall-E");
	ClapTrap	trap3 = trap;
	ClapTrap	trap4 = trap3 = trap1;

	LOG(PURPLE << "\nShow ClapTraps' Status" << EOC);
	LOG(trap1);
	LOG(trap2);

	LOG(PURPLE << "Update Marvins's Attack Damage" << EOC);
	trap1.setAttackDamage(1);
	LOG(trap1);

	LOG(PURPLE << "ClapTraps Showing Off" << EOC);
	for (int i = 0; i < 3; i++)
	{
		trap1.attack("Wall-E");
		trap2.takeDamage(trap1.getAttackDamage());
	}

	LOG(PURPLE << "\nShow ClapTraps' Status" << EOC);
	LOG(trap1);
	LOG(trap2);

	LOG(PURPLE << "Repairing Time" << EOC);
	for (int i = 0; i < 3; i++)
		trap2.beRepaired(1);

	LOG(PURPLE << "\nShow ClapTraps' Status" << EOC);
	LOG(trap1);
	LOG(trap2);

	LOG(PURPLE << "Calling Destructors" << EOC);
	return (0);
}