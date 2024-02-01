#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value()
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &t)
{
	std::cout << "Copy constructor called\n";
	this->value = t.value;
}

Fixed &Fixed::operator=(const Fixed &t)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &t)
	{
		this->value = t.value;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
