#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name )
{
	Zombie*	newZombie = new(Zombie);
	newZombie->zombieName = name;
	return (newZombie);
}
