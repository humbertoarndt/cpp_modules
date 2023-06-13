/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:44:52 by harndt            #+#    #+#             */
/*   Updated: 2023/06/13 17:04:31 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include "AAnimal.hpp"
#include "Brain.hpp"

// =============================================================================
// CLASS
// =============================================================================

class Cat : public AAnimal
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