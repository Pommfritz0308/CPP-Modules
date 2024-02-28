#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ()
{
    FragTrap a ("Child");

    a.attack("Zombie");
    a.highFivesGuys();
    a.takeDamage(120);
    a.beRepaired(50);

    FragTrap b (a);
    b.attack("Zombie");
    b.takeDamage(120);
    b.beRepaired(50);
    b.highFivesGuys();

}