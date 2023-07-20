/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:50:56 by harndt            #+#    #+#             */
/*   Updated: 2023/07/19 22:27:43 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <iostream>
#include <list>
#include <stack>

// =============================================================================
// Macros
// =============================================================================

#define LOG(x) std::cout << x << RESET_COLOR << std::endl;
#define ERROR(x) std::cerr << x << RESET_COLOR << std::endl;
#define RESET_COLOR	"\033[0m"
#define YELLOW		"\033[0;33m"

// =============================================================================
// Class
// =============================================================================

/* Why std::stack doesn't have an iterator?

https://www.fluentcpp.com/2018/05/08/std-iterator-deprecated/
https://stackoverflow.com/questions/38136137/does-stack-have-iterators-in-c
https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators
*/

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		/* Orthodox Canonical Form Methods */
		MutantStack(void) {LOG("🔋 Default Constructor Called"); return ;}
		MutantStack(MutantStack const &src) {LOG("🔋 Copy Constructor Called"); *this = src; return ;};
		MutantStack &operator = (MutantStack const &rhs) 
		{
			LOG("🔋 Assignment Operator Called"); 
			if (this != &rhs)
				std::stack<T>::operator = (rhs);
			return (*this);
		};
		~MutantStack(void) {LOG("🔋 Destructor Called"); return ;};
	
		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin(void) {return (this->c.begin());};
		iterator	end(void) {return (this->c.end());};

		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
		iterator	rbegin(void) {return (this->c.rbegin());};
		iterator	rend(void) {return (this->c.rend());};

		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		iterator	cbegin(void) {return (this->c.cbegin());};
		iterator	cend(void) {return (this->c.cend());};

		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		iterator	crbegin(void) {return (this->c.crbegin());};
		iterator	crend(void) {return (this->c.crend());};
};