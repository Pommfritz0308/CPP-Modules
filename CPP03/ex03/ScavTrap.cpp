#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20)
{
	std::cout << "ScavTrap default constructed!\n";
}

ScavTrap::ScavTrap(const std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDmg = 20;
    std::cout << "ScavTrap " << name << " constructed!\n";
}

ScavTrap::ScavTrap(ScavTrap &old) : ClapTrap(old)
{
	std::cout << "ScavTrap " << old.name << " copied!\n";
}

ScavTrap& ScavTrap::operator= (ScavTrap &old)
{
	if(this != &old)
	{
		std::cout << "ScavTrap " << old.name << " assigned to " << name << std::endl;
		name = old.name;
		hitPoints = old.hitPoints;
		energyPoints = old.energyPoints;
		attackDmg = old.attackDmg;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destroyed\n";
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
