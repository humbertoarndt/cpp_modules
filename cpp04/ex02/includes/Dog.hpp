/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:42:24 by harndt            #+#    #+#             */
/*   Updated: 2023/06/13 17:04:37 by harndt           ###   ########.fr       */
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

class Dog : public AAnimal
{
	private:
		Brain	*_brain;

	public:
		/* Orthodox Canonical Form methods */
		Dog(void);
		Dog(Dog const &src);
		Dog &operator = (Dog const &rhs);
		virtual	~Dog(void);

		/* Member Functions */
		void makeSound(void) const;
		std::string	getIdea(size_t i) const;
		void	setIdea(size_t i, std::string &idea);
		Brain	*getBrain(void) const;
};

std::ostream &operator << (std::ostream &o, Dog const &i);