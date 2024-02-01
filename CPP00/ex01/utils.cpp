/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:38 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/19 11:50:39 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int UserPrompt(void)
{
	std::string prompt;

	while (true)
	{
		std::getline(std::cin, prompt);
		if (std::cin.eof())
		{
			std::cout << FRED("EOF detected. Exiting...") << std::endl;
			exit(0);
		}
		else if (prompt == "ADD")
			return 1;
		else if (prompt == "SEARCH")
			return 2;
		else if (prompt == "EXIT")
			return 3;
	}
}

void ReadInput(std::string& input, int flag)
{
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof() || !(std::cin.good()))
		{
			std::cout << std::endl << FRED("EOF detected. Exiting...") << std::endl;
			exit(0);
		}
		else if (input.empty() || isspace(input[0]))
		{
			std::cout << FRED("Input cannot be empty. Try again!") << std::endl;
			continue ;
		}
		else if (flag == 1 && !IsStrAlpha(input))
		{
			std::cout << FRED("Input needs to be alphabetical. Try again!") << std::endl;
			continue ;
		}
		else if (flag == 2 && !IsStrInRange(input, '0', '9'))
		{
			std::cout << FRED("Input needs to be numerical. Try again!") << std::endl;
			continue ;
		}
		else
		{
			std::cout << FGRN("Input accepted") << std::endl;
			return ;
		}
	}
}

bool IsStrInRange(std::string& str, int start_ascii, int end_ascii)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < start_ascii || str[i] > end_ascii)
			return (false);
	}
	return (true);
}

bool IsStrAlpha(std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isalpha(str[i]) && !std::isspace(str[i]))
			return (false);
	}
	return (true);
}
