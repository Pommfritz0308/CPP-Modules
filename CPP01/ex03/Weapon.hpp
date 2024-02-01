/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:17 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/23 17:41:52 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>

class Weapon
{
	public:

	const	std::string getType( void );
	void	setType( std::string newType);

	Weapon(std::string type);
	~Weapon();

	private:

	std::string type;
};

#endif
