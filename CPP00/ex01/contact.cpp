/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:11 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/19 11:50:12 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
//Constructors
Contact::Contact(void)
{
}

//Setters
void Contact::SetFirstName(const std::string& value)
{
	first_name = value;
}

void Contact::SetLastName(const std::string& value)
{
	last_name = value;
}

void Contact::SetPhoneNumber(const std::string& value)
{
	phone_number = value;
}

void Contact::SetNickname(const std::string& value)
{
	nickname = value;
}

void Contact::SetDarkestSecret(const std::string& value)
{
	darkest_secret = value;
}

// getters
std::string Contact::GetFirstName() const
{
	return (first_name);
}

std::string Contact::GetLastName() const
{
	return (last_name);
}

std::string Contact::GetPhoneNumber() const
{
	return (phone_number);
}

std::string Contact::GetNickname() const
{
	return (nickname);
}

std::string Contact::GetDarkestSecret() const
{
	return (darkest_secret);
}
