#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include "Weapon.hpp"

class HumanA
{
	public:

		void attack(void);

		HumanA(std::string newName, Weapon& newWeapon);
		~HumanA(void);

	private:

		Weapon& weapon;
		std::string name;
};

#endif
