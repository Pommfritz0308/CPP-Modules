#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDmg(0)
{
	std::cout << GBOLD("ClapTrap ") << GBOLD(name) << GBOLD(" constructed!\n");
}

ClapTrap::ClapTrap(const ClapTrap &t) : name(t.name), hitPoints(t.hitPoints),
	 energyPoints(t.energyPoints), attackDmg(t.attackDmg)
{
	std::cout << GBOLD("ClapTrap ") << GBOLD(name) << GBOLD(" copied!\n");
}

ClapTrap& ClapTrap::operator= (const ClapTrap &old)
{
	if (this != &old)
	{
		std::cout << GBOLD("ClapTrap ") << GBOLD(old.name) << GBOLD(" assigned to " ) << GBOLD(name) << std::endl;
		name = old.name;
		hitPoints = old.hitPoints;
		energyPoints = old.energyPoints;
		attackDmg = old.attackDmg;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << GBOLD("ClapTrap ") << GBOLD(name) << GBOLD(" destroyed!\n");
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!\n";
		energyPoints--;
	}
	else
		std::cout << "ClapTrap " << name << " can't attack. Not enough energy points...\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage!\n";	
	if (amount >= hitPoints)
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " hit the dust...\n";
	}
	else
		hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints)
	{
		if (hitPoints > std::numeric_limits<unsigned int>::max() - amount && amount + hitPoints >= 10)
		{
			std::cout << "ClapTrap " << name << " repaired " << amount << " points of health!\n";	
			hitPoints += amount;
			energyPoints--;
		}
		else
		{
			hitPoints = 10;
			std::cout << "ClapTrap " << name << " is at full health!\n";
		}
	}
	else
		std::cout << "ClapTrap " << name << " can't repair itself. Not enough energy points...\n";
}

