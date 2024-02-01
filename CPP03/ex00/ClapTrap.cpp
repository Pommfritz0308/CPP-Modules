#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDmg(0)
{
	std::cout << "ClapTrap " << name << " constructed!\n";
}

ClapTrap::ClapTrap(const ClapTrap &t) : name(t.name), hitPoints(t.hitPoints),
	 energyPoints(t.energyPoints), attackDmg(t.attackDmg)
{
	std::cout << "ClapTrap " << name << " copied!\n";
}

ClapTrap& ClapTrap::operator= (const ClapTrap &old)
{
	if (this != &old)
	{
		name = old.name;
		hitPoints = old.hitPoints;
		energyPoints = old.energyPoints;
		attackDmg = old.attackDmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!\n";
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount)
{

}

