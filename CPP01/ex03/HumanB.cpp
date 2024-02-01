#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string newName )
{
	name = newName;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}
