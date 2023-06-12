/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:44:52 by harndt            #+#    #+#             */
/*   Updated: 2023/06/12 15:57:50 by harndt           ###   ########.fr       */
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
		Brain	*_brain;

	public:
		/* Orthodox Canonical Form methods */
		Cat(void);
		Cat(Cat const &src);
		Cat &operator = (Cat const &rhs);
		virtual	~Cat(void);

		/* Member Functions */
		void	makeSound(void) const;
		std::string	getIdea(size_t i) const;
		void	setIdea(size_t i, std::string &idea);
		Brain	*getBrain(void) const;
};

std::ostream &operator << (std::ostream &o, Cat const &i);