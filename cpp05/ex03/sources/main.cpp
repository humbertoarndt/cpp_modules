/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:01 by harndt            #+#    #+#             */
/*   Updated: 2023/06/27 14:50:10 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*
	TODOS
	[x] Create tests on main.
	[x] Documment code.
	[x] Create class Intern
	[x] Create function Intern::makeForm();
	[x] Create function ShrubberyCreationForm::create();
	[x] Create function RobotomyRequestForm::create();
	[x] Create function PresidentialPardonForm::create();
*/

/**
 * @brief Copy from the subject test.
 * 
 */
void	subjectTest(void)
{
	std::cout << "\n>>Subject Test == ===========================" << std::endl;
	std::cout << "Subject Constructors ========================" << std::endl;

	/* Creating Intern and an AForm */
	Intern	someRandomIntern;
	AForm	*rrf;

	/* Using makeForm() */
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << "\nSubject Destructors =========================" << std::endl;
	delete rrf;

	return ;
}

/**
 * @brief Tests intern's makeForm().
 * 
 * @param formName The name for a new AForm object.
 * @param target The target for a new AForm object.
 */
void	testForms(std::string formName, std::string target)
{
	LOG("\n>> Creating Form: " << formName << ", using target: " << target);
	Intern		intern;
	Bureaucrat	bureaucrat("Bureaucrat", 1);
	AForm		*form;
	
	try
	{
		form = intern.makeForm(formName, target);
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

int	main(void)
{
	/* Subject Test */
	subjectTest();

	std::string const	shrubberyForm = "shrubbery creation";
	std::string const	robotomyForm = "robotomy request";
	std::string const	presidentialForm = "presidential pardon";

	testForms(shrubberyForm, "Humberto");
	testForms(robotomyForm, "Doisberto");
	testForms(presidentialForm, "Trêsberto");
	testForms("Formberto", "Quatroberto");
	testForms("", "");
	return (0);
}