/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:49:58 by harndt            #+#    #+#             */
/*   Updated: 2023/04/18 15:14:54 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

# include <iostream>	// std::cout
# include <string>		// std::string

# define PRINT(msg) std::cout << msg << std::endl;
# define ERROR(error) std::cout << "Error: " << error << std::endl;

// =============================================================================
// HARL CLASS
// =============================================================================

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);

};

#endif