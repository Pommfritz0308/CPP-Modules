/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbohling <fbohling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:21:44 by fbohling          #+#    #+#             */
/*   Updated: 2024/01/23 16:21:45 by fbohling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>

class Zombie
{
	public:

	void announce( void );
	static Zombie* newZombie( std::string name );
	static void randomChump( std::string name );
	static Zombie* zombieHorde( int N, std::string name );

	Zombie(void);
	~Zombie(void);

	private:

	std::string zombieName;
};

#endif

