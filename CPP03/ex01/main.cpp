#include "ScavTrap.hpp"

int main ()
{
    ScavTrap a ("Child");

    a.attack("Zombie");
    a.takeDamage(120);
    a.beRepaired(50);
    a.guardGate();

    ScavTrap b (a);
    b.attack("Zombie");
    b.takeDamage(120);
    b.beRepaired(50);
    b.guardGate();

}