/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:25:00 by harndt            #+#    #+#             */
/*   Updated: 2023/06/07 15:52:06 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include "WrongAnimal.hpp"

// =============================================================================
// CLASS
// =============================================================================

class WrongCat : public WrongAnimal
{
	public:
		/* Orthodox Canonical Form methods */
		WrongCat(void);
		WrongCat(WrongCat const &src);
		WrongCat &operator = (WrongCat const &rhs);
		~WrongCat(void);

		/* Member Functions */
		void	makeSound(void) const;
};
