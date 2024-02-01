#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string newName, Weapon& newWeapon ) : weapon(newWeapon)
{
	name = newName;
}

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
