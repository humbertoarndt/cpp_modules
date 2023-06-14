/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:34 by harndt            #+#    #+#             */
/*   Updated: 2023/06/14 17:51:46 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include <iostream>

// =============================================================================
// MACROS
// =============================================================================

#define	H_GRADE 1
#define	L_GRADE 150
#define	LOG(x) std::cout << x << std::endl;

// =============================================================================
// CLASS
// =============================================================================

class Bureaucrat
{
	private:
		std::string const	_name;
		unsigned int		_grade;
	
	public:
		/* Orthodox Canonical Form methods */
		Bureaucrat(void);
		Bureaucrat(std::string const &name, unsigned int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator = (Bureaucrat const &rhs);
		~Bureaucrat(void);

		/* Member Functions */
		unsigned int	getGrade(void) const;
		std::string		getName(void) const;
		void			decrementGrade(void);
		void			incrementGrade(void);
		
};

std::ostream &operator << (std::ostream &o, Bureaucrat const &i);