/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harndt <harndt@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:22:17 by harndt            #+#    #+#             */
/*   Updated: 2023/07/05 21:08:26 by harndt           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	LOG("=== Constructor List ===");
	// Serializer foo; // Static Class, so this don't work
	Data		*dataOriginal = new Data();
	uintptr_t	dataSerialized;
	Data		*dataDeserialized;

	LOG("\n>Original Data:\t\t" << dataOriginal->getQuote());
	dataSerialized = Serializer::serialize(dataOriginal);
	LOG(">Serialized Data:\t" << dataSerialized);
	dataDeserialized = Serializer::deserialize(dataSerialized);
	
	if (dataOriginal == dataDeserialized)
	{
		LOG(">Deserialized Data:\t" << dataDeserialized->getQuote());
	}
	else
	{
		ERROR(">Data not deserialized!");
	}
	
	LOG("\n=== Destructor List ===");
	delete dataOriginal;
	return (0);
}