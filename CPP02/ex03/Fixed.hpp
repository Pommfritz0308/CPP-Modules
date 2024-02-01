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

		Fixed(); // Default constructor
		Fixed(const Fixed &t); // Copy constructor
		Fixed(const int);
		Fixed(const float);
		Fixed& operator= (const Fixed &t); // Copy assignment operator overload
		~Fixed(); // Default destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		void setValue( int value);
		float toFloat( void ) const;
		int toInt( void ) const;
		bool operator > (Fixed const &b) const;
		bool operator < (Fixed const &b) const;
		bool operator >= (Fixed const &b) const;
		bool operator <= (Fixed const &b) const;
		bool operator == (Fixed const &b) const;
		bool operator != (Fixed const &b) const;
		Fixed operator + (Fixed const &b);
		Fixed operator - (Fixed const &b);
		Fixed operator * (Fixed const &b);
		Fixed operator / (Fixed const &b);
		Fixed operator ++ (void);
		Fixed operator -- (void);
		Fixed operator ++ (int);
		Fixed operator -- (int);
		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(Fixed const &a, Fixed const &b);
		static const Fixed& max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
