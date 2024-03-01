#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main ()
{
    FragTrap a ("Child");

    a.attack("Zombie");
    a.highFivesGuys();
    a.takeDamage(90);
    a.beRepaired(50);

    FragTrap b (a);
    b.attack("Zombie");
    b.takeDamage(100);
    b.beRepaired(50);
    b.highFivesGuys();

}