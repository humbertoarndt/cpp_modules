/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:45:32 by harndt            #+#    #+#             */
/*   Updated: 2023/06/21 13:48:25 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Inlcudes
// =============================================================================

#include "AForm.hpp"
#include <cstdlib>
// #include <cstdlib>
#include <ctime>

// =============================================================================
// Macros
// =============================================================================

#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45

// =============================================================================
// Class
// =============================================================================

class RobotomyRequestForm : public AForm
{
	public:
		/* Orthodox Canonical Form Methods */
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm &operator = (RobotomyRequestForm const &rhs);
		~RobotomyRequestForm(void);

		/* Member Function */
		void	execute(Bureaucrat const &executor) const;
};