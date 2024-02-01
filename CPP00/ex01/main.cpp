/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:18 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/19 11:50:19 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	std::cout << "TYPE \"" << FGRN("ADD") << "\" TO ADD A NEW CONTACT" << std::endl;
	std::cout << "TYPE \"" << FCYN("SEARCH") << "\" TO SEARCH FOR A CONTACT" << std::endl;
	std::cout << "TYPE \"" << FRED("EXIT") << "\" TO CLOSE THE PHONEBOOK" << std::endl << std::endl;
	while (1)
	{
		int	i = UserPrompt();

		if (i == 1)
			AddContact(phonebook);
		else if (i == 2)
			SearchContact(phonebook);
		else if (i == 3)
			break ;

	}
	return (0);
}
