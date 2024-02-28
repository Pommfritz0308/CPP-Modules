#include "ClapTrap.hpp"

int main ()
{
    ClapTrap a("Wayne");
    ClapTrap b( a );
    b = a;
    for (int i = 0; i < 5; i++)
        a.attack("Freddy");
    for (int i = 0; i < 5; i++)
        a.takeDamage(1);
    for (int i = 0; i < 5; i++)
        a.beRepaired(1);
}