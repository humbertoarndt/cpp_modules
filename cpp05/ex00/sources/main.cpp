/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:01 by harndt            #+#    #+#             */
/*   Updated: 2023/06/14 17:51:29 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
	TODOS
	[ ] Study Throw Exception.
	[ ] Create Bureaucrat::GradeTooHighException.
	[ ] Create Bureaucrat::GradeTooLowException.
	[ ] Create tests on main.
	[ ] Documment code.
	[ ] Study 'const' and 'this'
*/

int	main(void)
{
	std::cout << "\nBureaucrats Constructors ====================" << std::endl;
	Bureaucrat	a;
	Bureaucrat	b("Humberto", 3);
	Bureaucrat	c(a);
	Bureaucrat	d("Doisberto", H_GRADE);

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << d;

	std::cout << "\nBureaucrats Destructors =====================" << std::endl;
	return (0);
}