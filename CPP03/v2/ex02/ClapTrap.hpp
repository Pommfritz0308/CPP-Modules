#ifndef CLAPP_TRAP_HPP
# define CLAPP_TRAP_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

class ClapTrap
{
	protected:

		std::string			name;
		static unsigned int	maxHitPoints;
		unsigned int		hitPoints;
		unsigned int		energyPoints;
		unsigned int		attackDmg;
		unsigned int		dead;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDmg);
		ClapTrap(const ClapTrap &t);
		ClapTrap& operator= (const ClapTrap &old);
		~ClapTrap();
		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
};

#endif
