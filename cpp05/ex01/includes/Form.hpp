/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:23:26 by harndt            #+#    #+#             */
/*   Updated: 2023/06/15 19:56:35 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// INCLUDES
// =============================================================================

#include <iostream>
#include "Bureaucrat.hpp"

// =============================================================================
// CLASS
// =============================================================================

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeSign;
		int const			_gradeExec;

	public:
		/* Orthodox Canonical Form Methods */
		Form(void);
		Form(std::string const &name, int const &gradeSign, int const &gradeExec);
		Form(Form const &src);
		Form &operator = (Form const &rhs);
		~Form(void);

		/* Member Functions */
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		void		beSigned(Bureaucrat &bureaucrat);

		/* Throw Exceptions */
		class	GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

std::ostream &operator << (std::ostream &o, Form const &i);