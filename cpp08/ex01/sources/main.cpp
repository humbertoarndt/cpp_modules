/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 19:16:16 by harndt            #+#    #+#             */
/*   Updated: 2023/07/18 20:43:36 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	testSubject(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	LOG(sp.shortestSpan());
	LOG(sp.longestSpan());
}

int	main(void)
{
	testSubject();
	// Span	sp1(1);

	// sp1.addNumber(8);
	// LOG(sp1);
	// sp1.addNumber(12);
	// LOG(sp1);
	// sp1.addNumber(88);
	// LOG(sp1);
	// sp1.addNumber(0);
	// LOG(sp1);
	return (0);
}