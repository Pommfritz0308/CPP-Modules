#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include "Weapon.hpp"

class HumanB
{
	public:

		void attack(void);
		void setWeapon(Weapon& newWeapon);

		HumanB(std::string name);
		~HumanB(void);

	private:

		Weapon* weapon;
		std::string name;
};

#endif
