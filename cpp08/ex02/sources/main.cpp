/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:50:38 by harndt            #+#    #+#             */
/*   Updated: 2023/07/19 22:29:26 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/**
 * @brief Tests as the subject.
 * 
 */
void	testSubject(void)
{
	LOG(YELLOW << "> MutantStack >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	
	LOG(mstack.top());

	mstack.pop();

	LOG(mstack.size());

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	for (; it != ite; ++it)
		LOG(*it);

	std::stack<int> s(mstack);
	return ;
}

/**
 * @brief Tests as the subject using list.
 * 
 */
void	testList(void)
{
	LOG(YELLOW << "\n> List >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	std::list<int>	list;

	list.push_back(5);
	list.push_back(17);
	
	LOG(list.back());

	list.pop_back();

	LOG(list.size());

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	for (; it != ite; ++it)
		LOG(*it);

	std::list<int> l(list);
	return ;
}

int	main(void)
{
	testSubject();
	testList();
	return (0);
}