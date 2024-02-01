/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:30 by fbohling          #+#    #+#             */
/*   Updated: 2024/02/01 10:43:40 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//init private static member
int PhoneBook::contact_count = 0;

//getter definitions
const Contact& PhoneBook::GetContact(int index) const
{
	return (contacts[index]);
}

int PhoneBook::GetContactCount(void) const
{
	return (contact_count);
}

//setter definitions
void PhoneBook::SetContact(int index, const Contact& newContact)
{
	contacts[index] = newContact;
}

void PhoneBook::SetContactCount(int value)
{
	contact_count = value;
}

void DisplayEntry(const std::string& entry)
{
	if (entry.length() > 10)
		std::cout << entry.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << entry;
	std::cout << "|";
}

void AddContact(PhoneBook& phonebook)
{
	std::string input;
	Contact newContact;

	std::cout << "Enter first name: ";
	ReadInput(input, 1);
	newContact.SetFirstName(input);
	std::cout << "Enter last name: ";
	ReadInput(input, 1);
	newContact.SetLastName(input);
	std::cout << "Enter phone number: ";
	ReadInput(input, 2);
	newContact.SetPhoneNumber(input);
	std::cout << "Enter nickname: ";
	ReadInput(input, 1);
	newContact.SetNickname(input);
	std::cout << "Enter darkest secret: ";
	ReadInput(input, 0);
	newContact.SetDarkestSecret(input);
	if (phonebook.GetContactCount() == MAX_CONTACTS)
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			phonebook.SetContact(i, phonebook.GetContact(i + 1));
		phonebook.SetContact(MAX_CONTACTS - 1, newContact);
	}
	else
	{
		phonebook.SetContact(phonebook.GetContactCount(), newContact);
		phonebook.SetContactCount(phonebook.GetContactCount() + 1);
	}
	std::cout << BGRN("+ + + Contact added + + +") << std::endl << std::endl;
}


void SearchContact(PhoneBook& phonebook)
{
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << BOLD("|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|") << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
	for (int i = 0; i < phonebook.GetContactCount(); i++)
	{
		std::stringstream ss;
		std::string	number;
		ss << i + 1;
		ss >> number;
		std::cout << "|";
		DisplayEntry(number);
		DisplayEntry(phonebook.GetContact(i).GetFirstName());
		DisplayEntry(phonebook.GetContact(i).GetLastName());
		DisplayEntry(phonebook.GetContact(i).GetNickname());
		std::cout << std::endl;
		std::cout << "+-------------------------------------------+" << std::endl;
	}
	std::cout << "Enter index: ";
	std::string input;
	std::cin >> input;
	int index = atoi(input.c_str());
	if (index > 0 && index <= phonebook.GetContactCount() && index <= MAX_CONTACTS)
	{
		std::cout << std::endl;
		std::cout << BOLD("First name: ") << phonebook.GetContact(index - 1).GetFirstName() << std::endl;
		std::cout << BOLD("Last name: ") << phonebook.GetContact(index - 1).GetLastName() << std::endl;
		std::cout << BOLD("Phone number: ") << phonebook.GetContact(index - 1).GetPhoneNumber() << std::endl;
		std::cout << BOLD("Nickname: ") << phonebook.GetContact(index - 1).GetNickname() << std::endl;
		std::cout << BOLD("Darkest secret: ") << phonebook.GetContact(index - 1).GetDarkestSecret() << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << FRED("Invalid index") << std::endl;
}
