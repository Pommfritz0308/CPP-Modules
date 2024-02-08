/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:21:39 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/23 16:21:40 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name )
{
	Zombie* horde;

	horde = new Zombie[N];
	if (!horde)
		return (NULL);
	for (int i = 0; i < N; i++)
	{
		horde[i].zombieName = name;
		horde[i].announce();
	}
	return (horde);
}
