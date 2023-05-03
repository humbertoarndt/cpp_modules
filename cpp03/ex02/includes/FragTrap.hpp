/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:11:19 by harndt            #+#    #+#             */
/*   Updated: 2023/05/03 15:35:17 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		/* Orthodox Canonical Form methods */
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);
		FragTrap &operator = (FragTrap const &rhs);

		/* Member Functions */
		void	highFivesGuy(void);
};

std::ostream & operator << (std::ostream  &o, FragTrap const &i);
