/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:19:15 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 18:06:18 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	LOG("\nCalling Constructors");
	ClapTrap	clap;
	ScavTrap	scav;
	FragTrap	frag;
	FragTrap	frag1("Marvin");
	FragTrap	frag2("Wall-E");
	FragTrap	frag3 = frag;
	FragTrap	frag4 = frag3 = frag;

	LOG("\nShow Traps' Status");
	LOG(clap);
	LOG(scav);
	LOG(frag1);
	LOG(frag2);

	LOG("High Five Time");
	frag2.highFivesGuy();

	LOG("\nCalling Destructors");
	return (0);
}