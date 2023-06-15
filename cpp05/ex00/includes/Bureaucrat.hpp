/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:33:34 by harndt            #+#    #+#             */
/*   Updated: 2023/06/15 11:44:58 by harndt           ###   ########.fr       */
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
#define ERROR(x) std::cerr << x << std::endl;

// =============================================================================
// CLASS
// =============================================================================

class Bureaucrat
{
	private:
		std::string const	_name;
		int		_grade;
	
	public:
		/* Orthodox Canonical Form methods */
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator = (Bureaucrat const &rhs);
		~Bureaucrat(void);

		/* Member Functions */
		int	getGrade(void) const;
		std::string		getName(void) const;
		void			decrementGrade(void);
		void			incrementGrade(void);

		/*
		How to create throw execptions in cpp

		https://linuxhint.com/throw-cpp-exception/
		https://www.geeksforgeeks.org/exception-handling-using-classes-in-cpp/
		*/
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

std::ostream &operator << (std::ostream &o, Bureaucrat const &i);