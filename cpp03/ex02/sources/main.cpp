/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/05/03 15:44:53 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	LOG(PURPLE << "\nCalling Constructors" << EOC);
	ClapTrap	clap;
	ScavTrap	scav;
	FragTrap	frag;
	FragTrap	frag1("Marvin");
	FragTrap	frag2("Wall-E");
	FragTrap	frag3 = frag;
	FragTrap	frag4 = frag3 = frag;

	LOG(PURPLE << "\nShow Traps' Status" << EOC);
	LOG(clap);
	LOG(scav);
	LOG(frag1);
	LOG(frag2);

	LOG(PURPLE << "High Five Time" << EOC);
	frag2.highFivesGuy();

	LOG(PURPLE << "\nCalling Destructors" << EOC);
	return (0);
}