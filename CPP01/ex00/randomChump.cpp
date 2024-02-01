#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
	Zombie randomChump;

	randomChump.zombieName = name;
	randomChump.announce();
}
