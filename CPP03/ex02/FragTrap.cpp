#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << GBOLD("FragTrap constructed!\n");
}

FragTrap::FragTrap(const std::string name) : ClapTrap("Parent", 100, 100, 30)
{
    std::cout << GBOLD("FragTrap ") << GBOLD(name) << GBOLD(" constructed!\n");
}

FragTrap::FragTrap(FragTrap &old) : ClapTrap(old)
{
	std::cout << GBOLD("FragTrap ") << GBOLD(old.name) << GBOLD(" copied!\n");
}

FragTrap& FragTrap::operator= (FragTrap &old)
{
	if(this != &old)
	{
		std::cout << GBOLD("FragTrap ") << GBOLD(old.name) << GBOLD(" assigned to " ) << GBOLD(name) << std::endl;
		name = old.name;
		hitPoints = old.hitPoints;
		energyPoints = old.energyPoints;
		attackDmg = old.attackDmg;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << GBOLD("FragTrap destroyed\n");
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requested a high five!\n";
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoints)
	{
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!\n";
		energyPoints--;
	}
	else
		std::cout << "FragTrap " << name << " can't attack. Not enough energy points...\n";
}
