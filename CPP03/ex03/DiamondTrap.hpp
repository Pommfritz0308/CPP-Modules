#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        
        std::string _name;

    public:

        DiamondTrap();
        DiamondTrap(const std::string& name);
        DiamondTrap(const DiamondTrap &old);
        DiamondTrap& operator= (const DiamondTrap &old);
        ~DiamondTrap();
        void whoAmI();
        void attack(const std::string& name);

};

#endif