/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:21:48 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/23 16:21:49 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{};

Zombie::~Zombie(void)
{
	std::cout << zombieName << ": destroyed" << std::endl;
};

void Zombie::announce( void )
{
	std::cout << zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
