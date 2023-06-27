/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:37:34 by harndt            #+#    #+#             */
/*   Updated: 2023/06/27 14:53:53 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include "AForm.hpp"

// =============================================================================
// Macros
// =============================================================================

#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5

// =============================================================================
// Class
// =============================================================================

class PresidentialPardonForm : public AForm
{
	public:
		/* Orthodox Canonical Form Methods */
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm &operator = (PresidentialPardonForm const &rhs);
		~PresidentialPardonForm(void);

		/* Member Functions */
		void			execute(Bureaucrat const &executor) const;
		static AForm	*create(std::string const &target);
};