/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:23:48 by harndt            #+#    #+#             */
/*   Updated: 2023/05/09 12:46:41 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
#define __FIXED_H__

#include <cmath>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;

/* Understanding and Using Floating Point Numbers
https://www.cprogramming.com/tutorial/floating_point/
understanding_floating_point.html */

class	Fixed
{
	private:
		int					_raw;
		static const int	_fractionBits = 8;
	
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const &src);
		~Fixed(void);
		
		Fixed &operator= (Fixed const &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		// Overload of logic operators
		bool	operator > (const Fixed &rhs) const;
		bool	operator < (const Fixed &rhs) const;
		bool	operator >= (const Fixed &rhs) const;
		bool	operator <= (const Fixed &rhs) const;
		bool	operator == (const Fixed &rhs) const;
		bool	operator != (const Fixed &rhs) const;

		// Overload of arithmetic operators
		Fixed	operator + (const Fixed &rhs) const;
		Fixed	operator - (const Fixed &rhs) const;
		Fixed	operator * (const Fixed &rhs) const;
		Fixed	operator / (const Fixed &rhs) const;

		// Overload of increment/decrement operators
		Fixed	& operator ++ (void);
		Fixed	operator ++ (int);
		Fixed	& operator -- (void);
		Fixed	operator -- (int);

		// // Overload member functions
		static Fixed	&min(Fixed &lhs, Fixed &rhs);
		static Fixed	&min(Fixed const &lhs, Fixed const &rhs);
		static Fixed	&max(Fixed &lhs, Fixed &rhs);
		static Fixed	&max(Fixed const &lhs, Fixed const &rhs);
};

std::ostream & operator << (std::ostream & o, Fixed const & i);

#endif