/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:01 by harndt            #+#    #+#             */
/*   Updated: 2023/07/10 19:53:09 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
	TODOS
	[ ] Create tests on main.
	[ ] Documment code.
	[x] From class Form, create class AForm
	[x] Create class ShrubberyCreationForm
	[x] Create class RobotomyRequestForm
	[x] Create class PresidentialPardonForm
*/

int	main(void)
{
	std::cout << "\nForm Constructors ===========================" << std::endl;
	ShrubberyCreationForm shrubbery("1berto");
	Bureaucrat b1("Humberto", 138);

	RobotomyRequestForm robotomy("2berto");
	Bureaucrat b2("Doisberto", 46);

	PresidentialPardonForm presidential("3berto");
	Bureaucrat b3("Trê3berto", 6);
	LOG("");
	
	try 
	{
		LOG(">Try/Catch Block");
		b1.signForm(shrubbery);
		b1.signForm(shrubbery);
		b1.executeForm(shrubbery);
		LOG("");
	}
	catch (AForm::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	b1.incrementGrade();
	b1.signForm(shrubbery);
	b1.executeForm(shrubbery);

	/* RobotomyRequestForm testing simple */
	try 
	{
		LOG("\n>Try/Catch Block");
		b2.signForm(robotomy);
		b2.executeForm(robotomy);
		LOG("");
	}
	catch (AForm::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	b2.incrementGrade();
	b2.signForm(robotomy);
	b2.executeForm(robotomy);

	try 
	{
		LOG("\n>Try/Catch Block");
		b3.signForm(presidential);
		b3.executeForm(presidential);
		LOG("");
	}
	catch (AForm::GradeTooLowException &e)
	{
		ERROR(e.what());
	}

	b3.incrementGrade();
	b3.signForm(presidential);
	b3.executeForm(presidential);

	std::cout << "\nForm Destructors ===========================" << std::endl;
	return (0);
}