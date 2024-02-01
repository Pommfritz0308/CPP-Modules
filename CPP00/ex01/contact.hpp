/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:50:15 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/19 11:50:16 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>

class Contact
{
	private:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string nickname;
	std::string darkest_secret;

	public:
	Contact(void);
	//Getters
	std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetPhoneNumber() const;
    std::string GetNickname() const;
    std::string GetDarkestSecret() const;

	//Setters
	void SetFirstName(const std::string& value);
	void SetLastName(const std::string& value);
	void SetPhoneNumber(const std::string& value);
	void SetNickname(const std::string& value);
	void SetDarkestSecret(const std::string& value);
};
#endif
