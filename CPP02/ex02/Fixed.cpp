#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value()
{
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &t)
{
	// std::cout << "Copy constructor called\n";
	this->value = t.value;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called\n";
	this->value = n << bits;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float constructor called\n";
	this->value = roundf(n * (1 << bits));
}

Fixed &Fixed::operator=(const Fixed &t)
{
	// std::cout << "Copy assignment operator called\n";
	if (this != &t)
	{
		this->value = t.value;
	}
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called\n";
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(value) / (1 << bits);
}

int Fixed::toInt( void ) const
{
	return (value >> bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
