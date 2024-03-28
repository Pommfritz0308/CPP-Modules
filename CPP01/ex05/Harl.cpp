#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "Du Russelnase!" << std::endl;
}

void Harl::error( void )
{
	std::cout << "* Strong Mort attackiert Elefanten *\n";
}
void Harl::info( void )
{
	std::cout << "Gib mir sofort alle deine Erdnusse!\n";
}

void Harl::warning( void )
{
	std::cout << "Tut mir Leid, aber ich hab keine...\n";
}


void Harl::complain( std::string level )
{
	t_function functions[] = {{"debug", &Harl::debug}, {"error", &Harl::error}, {"info", &Harl::info}, {"warning", &Harl::warning}}; // declaring array of structs
	for (int i = 0; i < 4; i++) // loop through array of function pointers
	{
		if (functions[i].level == level)
		{
			(this->*functions[i].function)(); // call function
			return ;
		}
	}
	std::cout << "Error: function not found\n";
	return ;
}
