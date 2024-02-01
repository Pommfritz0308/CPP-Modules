#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap("Parent", 100, 50, 20)
{
    std::cout << GBOLD("ScavTrap ") << GBOLD(name) << GBOLD(" constructed!\n");
}

ScavTrap::~ScavTrap()
{
    std::cout << GBOLD("ScavTrap destroyed\n");
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode!\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!\n";
		energyPoints--;
	}
	else
		std::cout << "ScavTrap " << name << " can't attack. Not enough energy points...\n";
}
