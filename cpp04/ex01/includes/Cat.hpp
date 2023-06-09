/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:44:52 by harndt            #+#    #+#             */
/*   Updated: 2023/06/09 18:45:05 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include "Animal.hpp"
#include "Brain.hpp"

// =============================================================================
// CLASS
// =============================================================================

class Cat : public Animal
{
	private:
		Brain	*brain;

	public:
		/* Orthodox Canonical Form methods */
		Cat(void);
		Cat(Cat const &src);
		Cat &operator = (Cat const &rhs);
		virtual	~Cat(void);

		/* Member Functions */
		void	makeSound(void) const;
};

std::ostream &operator << (std::ostream &o, Cat const &i);