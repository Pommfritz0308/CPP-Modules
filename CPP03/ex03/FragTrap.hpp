#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    protected:
    
		unsigned int		hitPoints;
		unsigned int		attackDmg;

    public:

        FragTrap();
        FragTrap(const std::string name);
        FragTrap(FragTrap &old);
        FragTrap& operator= (FragTrap &old);
        ~FragTrap();
        void highFivesGuys(void);
        void attack(const std::string& name);
};

#endif