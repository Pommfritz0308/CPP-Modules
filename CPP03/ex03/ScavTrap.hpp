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
        ScavTrap(ScavTrap &old);
        ScavTrap& operator= (ScavTrap &old);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& name);
};

#endif