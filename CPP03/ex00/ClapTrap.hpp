#ifndef CLAPP_TRAP_HPP
# define CLAPP_TRAP_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>

class ClapTrap
{
	private:

		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDmg;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &t);
		ClapTrap& operator= (const ClapTrap &old);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
