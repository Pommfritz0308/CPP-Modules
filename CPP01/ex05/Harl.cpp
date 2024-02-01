#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "Du Russelnase!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "Gib mir sofort alle deine Erdnusse!\n";
}

void Harl::warning( void )
{
	std::cout << "Tut mir Leid, aber ich hab keine...\n";
}

void Harl::error( void )
{
	std::cout << "* Strong Mort attackiert Elefanten *\n";
}

void Harl::complain( std::string level )
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "Error: function not found\n";
	return ;
}
