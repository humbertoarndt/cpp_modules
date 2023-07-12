/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:10:28 by harndt            #+#    #+#             */
/*   Updated: 2023/07/12 15:19:43 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

#define SHOW_MSG true

// =============================================================================
// Exceptions
// =============================================================================

template<typename T>
const char	*Array<T>::OutOfBoundException::what(void) const throw()
{
	return ("Index out of bounds");
}

// =============================================================================
// Constructors and Destructor
// =============================================================================

/**
 * @brief Construct a new Array< T>:: Array object
 * 
 */
template<typename T>
Array<T>::Array(void) : _n(0), _ptr(NULL)
{
	if (SHOW_MSG == true)
		LOG("⛓️ Default Constructor Called")
	return ;
}

/**
 * @brief Construct a new Array< T>:: Array object
 * 
 * @param n The size of the Array<T>.
 */
template<typename T>
Array<T>::Array(unsigned int n) : _n(n), _ptr(NULL)
{
	if (SHOW_MSG == true)
		LOG("⛓️ Parameter Constructor Called");
	if (n > 0)
		this->_ptr = new T[n];
	
	return ;
}

/**
 * @brief Construct a new Array< T>:: Array object
 * 
 * @param src The Array<T> object to be copied.
 */
template<typename T>
Array<T>::Array(Array<T> const &src) : _n(src.size()), _ptr(NULL)
{
	if (SHOW_MSG == true)
		LOG("⛓️ Copy Constructor Called");
	if (src.size() > 0)
	{
		this->_ptr = new T[src.size()];
		for (unsigned int i = 0; i < src._n; i++)
			this->_ptr[i] = src._ptr[i];
	}
	return ;
}

/**
 * @brief Destroy the Array< T>:: Array object
 * 
 */
template<typename T>
Array<T>::~Array(void)
{
	if (SHOW_MSG == true)
		LOG("⛓️ Destructor Called");
	delete [] this->_ptr;
	return ;
}

// =============================================================================
// Overload
// =============================================================================

/**
 * @brief Overload for the '=' operator
 * 
 * @param rhs The right hand side varible to be assigned.
 * @return Array<T>& A pointer to the assigned Array<T> object.
 */
template<typename T>
Array<T> & Array<T>::operator = (Array<T> const &rhs)
{
	if (SHOW_MSG == true)
		LOG("⛓️ Assignment operator called");
	if (this != &rhs)
	{
		if (_ptr)
			delete[] this->_ptr;
		this->_n = rhs.size();
		this->_ptr = new T[rhs.size()];
		for (unsigned int i = 0; i < rhs._n; i++)
			this->_ptr[i] = rhs[i];
	}
	return (*this);
}

/**
 * @brief Overload for the '[]' operator
 * 
 * @param index The index to access.
 * @return T& A pointer to the position at the gieven index.
 */
template<typename T>
T &Array<T>::operator [] (unsigned int index) const
{
	if (index >= this->_n)
		throw Array<T>::OutOfBoundException();
	return (this->_ptr[index]);
}

/**
 * @brief Overload for the 'std::onstream <<' operator.
 * 
 * @param o Output stream
 * @param i Input stream
 * @return std::ostream& Reference to the output.
 */
template<typename T>
std::ostream & operator << (std::ostream &o, Array<T> const &array)
{
	o << "[";
	if (array.size())
	{
		unsigned int i = 0;
		for (; i < array.size() - 1; i++)
			o << array[i] << ", ";
		o << array[i];
	}
	o << "]";
	return (o);
}

// =============================================================================
// Member Functions
// =============================================================================

/**
 * @brief Returns the number of elementes in the array.
 * 
 * @return unsigned int Number of elements in the array.
 */
template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_n);
}