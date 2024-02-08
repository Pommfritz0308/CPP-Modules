#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main ()
{
    DiamondTrap a ("Freddy");

    a.attack("Zombie");
    a.takeDamage(120);
    a.whoAmI();
}