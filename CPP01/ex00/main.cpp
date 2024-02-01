#include "Zombie.hpp"


int	main (int argc, char **argv)
{
	if (argc < 2)
		return (1);
	Zombie* newZombie;
	Zombie::randomChump(argv[1]);
	newZombie = Zombie::newZombie(argv[1]);
	newZombie->announce();
	delete newZombie;
	return (0);
}
