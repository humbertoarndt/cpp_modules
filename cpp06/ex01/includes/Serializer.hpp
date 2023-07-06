/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:06:34 by harndt            #+#    #+#             */
/*   Updated: 2023/07/05 21:00:37 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// =============================================================================
// Includes
// =============================================================================

#include <stdint.h> // uintptr_t
#include "Data.hpp"

// =============================================================================
// Class
// =============================================================================

class Serializer
{
	private:
		/* Orthodox Canonical Form Methods */
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer &operator = (Serializer const &rhs);
		~Serializer(void);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	/* What is the uintptr_t data type?
	'uintptr_t' is an unsigned integer type that is capable of storing a data
	pointer (whether it can hold a function pointer is unspecified). Which 
	typically means that it's the same size as a pointer.

	https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type
	*/

	/* reinterpret_cast<type>
	Use reinterpret_cast for low-level reinterpreting of bit patterns. 
	Use with extreme caution.

	https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used
	*/
};