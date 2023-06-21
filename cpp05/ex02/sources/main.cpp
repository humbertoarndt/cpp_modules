/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:01 by harndt            #+#    #+#             */
/*   Updated: 2023/06/21 14:35:24 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

/*
	TODOS
	[ ] Create tests on main.
	[ ] Documment code.
	[x] From class Form, create class AForm
	[x] Create class ShrubberyCreationForm
	[x] Create class RobotomyRequestForm
	[ ] Create class PresidentialPardonForm
*/

int	main(void)
{
	std::cout << "\nForm Constructors ===========================" << std::endl;
	/* ShrubberyCreationForm testing simple */
	ShrubberyCreationForm form1("arvore");
	Bureaucrat b1("humberto", 1);

	/* RobotomyRequestForm testing simple */
	RobotomyRequestForm form2("robô");
	Bureaucrat b2("humberto", 1);

	/* Signing forms */
	form1.beSigned(b1);
	form2.beSigned(b2);

	/* Execute form functions */
	LOG(" ");
	form1.execute(b1);
	form2.execute(b2);

	std::cout << "\nForm Destructors ===========================" << std::endl;
	return (0);
}