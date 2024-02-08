#ifndef HARL_HPP
#define HARL_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>

class Harl
{
	private:

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:

		void complain( std::string level );
};

struct t_function
{
	std::string level;
	void (Harl::*function)( void );
};

#endif
