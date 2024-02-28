#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("ClapTrap"), FragTrap("FragTrap"), ScavTrap("ScavTrap")
{
    std::cout << GBOLD("DiamondTrap has been created\n");
}

DiamondTrap::DiamondTrap(const std::string& name) :
    FragTrap(name), ScavTrap(name)
{
    _name = name;
    ClapTrap::name = name + "_clap_name";
    std::cout << GBOLD("DiamondTrap ") << GBOLD(_name) << GBOLD(" has been created\n");
    std::cout << GBOLD("DiamondTrap hitpoints: ") << FragTrap::hitPoints << std::endl;
    std::cout << GBOLD("DiamondTrap energy points: ") << ScavTrap::energyPoints << std::endl;
    std::cout << GBOLD("DiamondTrap attack damage: ") << FragTrap::attackDmg << std::endl;
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap &old)
{
    _name = old._name;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << GBOLD("DiamondTrap ") << GBOLD(_name) << GBOLD(" has been destroyed\n");
}   

void DiamondTrap::whoAmI()
{
    std::cout << GBOLD("I am ") << GBOLD(_name) <<
        GBOLD(" and my ClapTrap name is ") << GBOLD(ClapTrap::name) << std::endl;
}

void DiamondTrap::attack(const std::string& name)
{
    ScavTrap::attack(name);
}
