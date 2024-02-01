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

	Zombie(void);
	~Zombie(void);

	private:

	std::string zombieName;
};

#endif

