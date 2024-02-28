#include "ClapTrap.hpp"
#include <limits>

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDmg(1) , dead(0)
{
	std::cout << GBOLD("ClapTrap ") << GBOLD(name) << GBOLD(" constructed!\n");
}

ClapTrap::ClapTrap(const ClapTrap &t) : name(t.name), hitPoints(t.hitPoints),
	 energyPoints(t.energyPoints), attackDmg(t.attackDmg), dead(t.dead)
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
		dead = old.dead;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << GBOLD("ClapTrap ") << GBOLD(name) << GBOLD(" destroyed!\n");
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints && hitPoints)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDmg << " points of damage!\n";
		energyPoints--;
	}
	else
		std::cout << "ClapTrap " << name << " can't attack.\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
if (amount >= hitPoints)
	{
		if (hitPoints && !dead)
		{
			std::cout << "ClapTrap " << name << " took " << hitPoints << " points of damage!\n";
			std::cout << "ClapTrap " << name << " hit the dust...\n";
		}
		else
			std::cout  << "ClapTrap " << name << " is already dead!\n";
		hitPoints = 0;
		dead = 1;
	}
	else
	{
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage!\n";
		hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints && energyPoints)
	{
		for (unsigned int i = 0; i < amount && i + hitPoints < 10; i++)
		{
			std::cout << "ClapTrap " << name << " repaired " << amount << " points of health!\n";	
			energyPoints--;
			hitPoints++;
		}
		if (hitPoints == 10)
			std::cout << "ClapTrap " << name << " is at full health!\n";
	}
	else
		std::cout << "ClapTrap " << name << " can't repair itself.\n";
}

