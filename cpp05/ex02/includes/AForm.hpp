/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:23:26 by harndt            #+#    #+#             */
/*   Updated: 2023/06/19 12:21:15 by harndt           ###   ########.fr       */
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

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeSign;
		int const			_gradeExec;
		std::string const	_target;

	protected:
		void	setName(std::string const name);
		void	setSign(bool const sign);
		void	setGradeSign(int const grade);
		void	setGradeExec(int const grade);
		void	setTarget(std::string const target);

	public:
		/* Orthodox Canonical Form Methods */
		AForm(void);
		AForm(std::string const &name, int const &gradeSign, int const &gradeExec);
		AForm(AForm const &src);
		AForm &operator = (AForm const &rhs);
		~AForm(void);

		/* Member Functions */
		std::string	getName(void) const;
		bool		getSign(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		std::string	getTarget(void) const;
		void		beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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
		class	FormNotSignedException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

std::ostream &operator << (std::ostream &o, AForm const &i);