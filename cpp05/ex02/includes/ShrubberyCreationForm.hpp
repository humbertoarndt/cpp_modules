/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:41:25 by harndt            #+#    #+#             */
/*   Updated: 2023/06/19 19:21:15 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include "AForm.hpp"
#include <fstream>

// =============================================================================
// Macros
// =============================================================================

#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137
#define SHRUBBERY \
"\
              * *    \n\
           *    *  *\n\
      *  *    *     *  *\n\
     *     *    *  *    *\n\
 * *   *    *    *    *   *\n\
 *     *  *    * * .#  *   *\n\
 *   *     * #.  .# *   *\n\
  *     #.  #: # * *    *\n\
 *   * * #. ##       *\n\
   *       ###\n\
             ##\n\
              ##.\n\
              .##:\n\
              :###\n\
              ;###\n\
            ,####.\n\
VVVVVVVVVVV.######.VVVVVVVVV\n\
"


// =============================================================================
// Class
// =============================================================================

class ShrubberyCreationForm : public AForm
{
	public:
		/* Orthodox Canonical Form Methods */
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm &operator = (ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm(void);

		/* Throw Exceptions */
		class	FileCreateErrorException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};

		void	execute(Bureaucrat const &executor) const;
};