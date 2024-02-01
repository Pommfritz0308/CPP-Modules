/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:36:33 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/24 10:07:11 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>

int	main( void )

{
	std::string str = "HI THIS IS BRAIN";

	std::string*	stringPTR = &str;
	std::string&		stringREF = str;

	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
}
