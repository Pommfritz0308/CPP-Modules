#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30)
{
	std::cout << "FragTrap default constructed!\n";
}

FragTrap::FragTrap(const std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDmg = 30;
    std::cout << "FragTrap " << name << " constructed!\n";
}

FragTrap::FragTrap(FragTrap &old) : ClapTrap(old)
{
	std::cout << "FragTrap " << old.name << " copied!\n";
}

FragTrap& FragTrap::operator= (FragTrap &old)
{
	if(this != &old)
	{
		std::cout << "FragTrap " << old.name << " assigned to " << name << std::endl;
		name = old.name;
		hitPoints = old.hitPoints;
		energyPoints = old.energyPoints;
		attackDmg = old.attackDmg;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destroyed\n";
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
