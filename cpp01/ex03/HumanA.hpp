/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:52:43 by harndt            #+#    #+#             */
/*   Updated: 2023/04/17 12:21:01 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

# include <iostream>
# include "Weapon.hpp"

// =============================================================================
// HUMAN A CLASS
// =============================================================================

class	HumanA
{
	private:
		std::string	_name;
		Weapon	&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		
		void	attack(void);
};

#endif