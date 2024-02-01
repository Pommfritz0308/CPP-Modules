#ifndef FIXED_HPP
# define FIXED_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>

class Fixed
{
	private:

		int value;
		static const int bits;

	public:

		Fixed(); // Default constructor
		Fixed(const Fixed &t); // Copy constructor
		Fixed& operator= (const Fixed &t); // Copy assignment operator overload
		~Fixed(); // Default destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
