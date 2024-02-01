/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:33 by fbohling          #+#    #+#             */
/*   Updated: 2024/02/01 10:41:29 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include "contact.hpp"
# include "colors.hpp"
# include <sstream>
# define MAX_CONTACTS 8

class PhoneBook
{
	private:
	static int	contact_count;
	Contact 	contacts[MAX_CONTACTS];

	public:
	//getter
	const Contact& GetContact(int index) const;
	int GetContactCount(void) const;

	// Setter
	void SetContact(int index, const Contact& newContact);
	void SetContactCount(int value);
};

int		UserPrompt(void);
void	ReadInput(std::string& input, int flag);
void	AddContact(PhoneBook& phonebook);
void	SearchContact(PhoneBook& phonebook);
bool	IsStrInRange(std::string& str, int start_ascii, int end_ascii);
bool	IsStrAlpha(std::string& str);

#endif
