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
