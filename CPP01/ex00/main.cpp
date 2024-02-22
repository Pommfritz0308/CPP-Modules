#include "Zombie.hpp"


int	main (int argc, char **argv)
{
	if (argc < 2)
		return (1);
	Zombie* newZombie;
	Zombie::randomChump(argv[1]); //lost after function call -> stack allocated
	newZombie = Zombie::newZombie(argv[1]); //available after function call -> heap allocated
	if (newZombie == NULL)
	{
		std::cerr << "Error: newZombie returned NULL" << std::endl;
		return (1);
	}
	newZombie->announce();
	delete newZombie;
	return (0);
}
