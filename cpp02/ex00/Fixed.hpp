/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:23:48 by harndt            #+#    #+#             */
/*   Updated: 2023/04/24 14:43:28 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

#define LOG(x) std::cout << x << std::endl;

class	Fixed
{
	private:
		int					_raw;
		static const int	_fractionBits = 8;
	
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		
		Fixed &operator= (Fixed const &rhs);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
		
};

#endif