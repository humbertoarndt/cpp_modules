/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:38:13 by harndt            #+#    #+#             */
/*   Updated: 2023/07/15 12:38:48 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/**
 * @brief Prints each Deque position.
 * 
 * @param d The Deque to be printed.
 */
void	showDeque(std::deque<int> d)
{
	std::deque<int>::iterator	it;
	
	std::cout << "Deque: ";
	for (it = d.begin(); it != d.end(); ++it)
		std::cout << "[" << *it << "]";
	LOG("\n");
}

/**
 * @brief Tests easyfind() in a Deque.
 * 
 */
void	testDeque(void)
{
	LOG("> Testing Deque " << std::setw(44) << std::setfill('>') << "");
	std::deque<int>	ideque;
	
	for (int i = -2; i < 3; i++)
		ideque.push_back(i);
	showDeque(ideque);

	try
	{
		LOG(YELLOW << ">> Test I - Value found")
		int	needle = 0;
		
		LOG(GRAY << "Looking for: " << needle);
		std::deque<int>::iterator it = easyfind(ideque, needle);
		LOG(GRAY << "Needle [" << *it << "] was found.");
	}
	catch(const std::exception& e){ERROR(e.what());}

	try
	{
		LOG(YELLOW << "\n>> Test II - Value not found");
		int	needle = 5;
		
		LOG(GRAY << "Looking for: " << needle);
		std::deque<int>::iterator it = easyfind(ideque, needle);
		LOG(GRAY << "Needle [" << *it << "] found.");
	}
	catch(const std::exception& e){ERROR(e.what());}
	LOG("");
	return ;
}

/**
 * @brief Prints each List position.
 * 
 * @param l The List to be printed.
 */
void	showList(std::list<int> l)
{
	std::list<int>::iterator	it;
	
	std::cout << GRAY << "List: ";
	for (it = l.begin(); it != l.end(); ++it)
		std::cout << "[" << *it << "]";
	LOG("\n");
}

/**
 * @brief Tests easyfind() in a List.
 * 
 */
void	testList(void)
{
	LOG("> Testing List " << std::setw(45) << std::setfill('>') << "");
	std::list<int>	ilist;

	for (int i = -2; i < 3; i++)
		ilist.push_back(i);
	showList(ilist);

	try
	{
		LOG(YELLOW << ">> Test III - Value found")
		int	needle = 0;
		
		LOG(GRAY << "Looking for: " << needle);
		std::list<int>::iterator it = easyfind(ilist, needle);
		LOG(GRAY << "Needle [" << *it << "] was found.");
	}
	catch(const std::exception& e){ERROR(e.what());}

	try
	{
		LOG(YELLOW << "\n>> Test IV - Value not found");
		int	needle = 5;
		
		LOG(GRAY << "Looking for: " << needle);
		std::list<int>::iterator it = easyfind(ilist, needle);
		LOG(GRAY << "Needle [" << *it << "] found.");
	}
	catch(const std::exception& e){ERROR(e.what());}
	LOG("");
	return ;
}

/**
 * @brief Prints each Vector<int> position.
 * 
 * @param l The Vector<int> to be printed.
 */
void	showVector(std::vector<int> v)
{
	std::vector<int>::iterator	it;
	
	std::cout << GRAY << "Vector: ";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << "[" << *it << "]";
	LOG("");
}

/**
 * @brief Prints each Vector<char> position.
 * 
 * @param l The Vector<char> to be printed.
 */
void	showVector(std::vector<char> v)
{
	std::vector<char>::iterator	it;
	
	std::cout << GRAY << "Vector: ";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << "[" << *it << "]";
	LOG("\n");
}

/**
 * @brief Tests easyfind() in a Vector.
 * 
 */
void	testVector(void)
{
	LOG("> Testing Vector " << std::setw(43) << std::setfill('>') << "");
	std::vector<int>	ivector;
	std::vector<char>	cvector;

	for (int i = 0; i < 5; i++)
	{
		ivector.push_back(i);
		cvector.push_back(i + 'a');
	}
	showVector(ivector);
	showVector(cvector);

	try
	{
		LOG(YELLOW << ">> Test V - Value found")
		int	needle = 0;
		
		LOG(GRAY << "Looking for: " << needle);
		std::vector<int>::iterator it = easyfind(ivector, needle);
		LOG(GRAY << "Needle [" << *it << "] was found.");
	}
	catch(const std::exception& e){ERROR(e.what());}

	try
	{
		LOG(YELLOW << "\n>> Test VI - Value found")
		char	needle = 'c';
		
		LOG(GRAY << "Looking for: " << needle);
		std::vector<char>::iterator it = easyfind(cvector, needle);
		LOG(GRAY << "Needle [" << *it << "] was found.");
	}
	catch(const std::exception& e){ERROR(e.what());}

	try
	{
		LOG(YELLOW << "\n>> Test VII - Value not found");
		int	needle = 5;
		
		LOG(GRAY << "Looking for: " << needle);
		std::vector<int>::iterator it = easyfind(ivector, needle);
		LOG(GRAY << "Needle [" << *it << "] found.");
	}
	catch(const std::exception& e){ERROR(e.what());}

	try
	{
		LOG(YELLOW << "\n>> Test VIII - Value not found");
		char	needle = 'h';
		
		LOG(GRAY << "Looking for: " << needle);
		std::vector<char>::iterator it = easyfind(cvector, needle);
		LOG(GRAY << "Needle [" << *it << "] found.");
	}
	catch(const std::exception& e){ERROR(e.what());}
	return ;
}

int	main(void)
{
	testDeque();
	testList();
	testVector();
	return (0);
}