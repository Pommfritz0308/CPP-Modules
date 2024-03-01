#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main ()
{
    DiamondTrap a ("Freddy");

    a.attack("Zombie");
    a.takeDamage(80);
    a.beRepaired(100);
    a.guardGate();
    a.highFivesGuys();
    a.whoAmI();
}