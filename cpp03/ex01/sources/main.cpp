/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/05/03 13:33:14 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	LOG(PURPLE << "\nCalling Constructors" << EOC);
	ClapTrap	trap;
	ScavTrap	scav;
	ScavTrap	scav1("Marvin");
	ScavTrap	scav2("Wall-E");
	ScavTrap	scav3 = scav;
	ScavTrap	scav4 = scav3 = scav;

	LOG(PURPLE << "\nShow Traps' Status" << EOC);
	LOG(trap);
	LOG(scav1);
	LOG(scav2);

	LOG(PURPLE << "ScavTraps Showing Off" << EOC);
	for (int i = 0; i < 3; i++)
	{
		scav1.attack("Wall-E");
		scav2.takeDamage(scav1.getAttackDamage());
	}

	LOG(PURPLE << "\nShow ScavTraps' Status" << EOC);
	LOG(scav1);
	LOG(scav2);

	LOG(PURPLE << "Repairing Time" << EOC);
	for (int i = 0; i < 3; i++)
		scav2.beRepaired(20);

	LOG(PURPLE << "\nShow ClapTraps' Status" << EOC);
	LOG(scav1);
	LOG(scav2);

	LOG(PURPLE << "\nCalling Destructor" << EOC);
	return (0);
}