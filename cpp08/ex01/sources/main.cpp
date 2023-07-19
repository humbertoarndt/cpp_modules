/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:16 by harndt            #+#    #+#             */
/*   Updated: 2023/07/19 17:43:40 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
 * @brief Tests as the subject for module 08.
 * 
 */
void	testSubject(void)
{
	LOG(YELLOW << "> Subject test >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	LOG(sp.shortestSpan());
	LOG(sp.longestSpan());
	return ;
}

/**
 * @brief Tests exceptions.
 * 
 */
void	testException(void)
{
	LOG(YELLOW << "\n> Exception test >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	Span	sp(1);

	try {sp.shortestSpan();}
	catch (Span::NoSpanFoundException &e) {ERROR(e.what());}

	sp.addNumber(42);
	try {sp.longestSpan();}
	catch (Span::NoSpanFoundException &e) {ERROR(e.what());}

	try {sp.addNumber(24);}
	catch (Span::RangeFullException &e) {ERROR(e.what());}
	return ;
}

/**
 * @brief Tests a big Span.
 * 
 */
void	test10000(void)
{
	LOG(YELLOW << "\n> 10000 test >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	Span	sp(10000);
	intv	zeroes(10000, 0);
	
	try 
	{
		sp.addNumber(zeroes.begin(), zeroes.end());
		LOG(sp);
	}
	catch (Span::RangeFullException &e) {ERROR(e.what());}
	return ;
}

int	main(void)
{
	testSubject();
	testException();
	test10000();
	return (0);
}