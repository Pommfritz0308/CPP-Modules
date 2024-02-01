#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:

        ScavTrap(const std::string name);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& name);
};

#endif