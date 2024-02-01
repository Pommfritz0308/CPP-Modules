/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:21:53 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/23 16:21:54 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int	main (int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int n = 5;
	Zombie* horde = Zombie::zombieHorde(n, argv[1]);
	delete [] horde;
	return (0);
}
