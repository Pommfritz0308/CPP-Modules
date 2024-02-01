#ifndef FIXED_HPP
# define FIXED_HPP
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>

class Fixed
{
	private:

		int value;
		static const int bits;

		public:
			Fixed(); // Default Constructor
			Fixed(const Fixed &t); // Copy constructor
			Fixed(const int);
			Fixed(const float);
			Fixed& operator= (const Fixed &t); // Copy assignment operator overload
			~Fixed(); // Default destructor
			int getRawBits( void ) const;
			void setRawBits( int const raw );
			float toFloat( void ) const;
			int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
