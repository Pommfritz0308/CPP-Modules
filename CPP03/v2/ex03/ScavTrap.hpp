#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    protected:

        unsigned int		energyPoints;

    public:

        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap(const ScavTrap &old);
        ScavTrap& operator= (const ScavTrap &old);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& name);
};

#endif