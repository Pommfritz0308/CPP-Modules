/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:05:18 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/24 11:20:06 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newWeapon)
{
	type = newWeapon;
}

Weapon::~Weapon()
{
}

const	std::string Weapon::getType( void )
{
	const std::string newType = type;
	return (newType);
}

void	Weapon::setType( std::string newType)
{
	type = newType;
}
