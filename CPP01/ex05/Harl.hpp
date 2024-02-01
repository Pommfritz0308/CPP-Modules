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

#endif
