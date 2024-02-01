#include "Fixed.hpp"

bool Fixed::operator > (Fixed const &b) const
{
	return (this->value > b.value);
}

bool Fixed::operator < (Fixed const &b) const
{
	return (this->value < b.value);
}

bool Fixed::operator <= (Fixed const &b) const
{
	return (this->value <= b.value);
}

bool Fixed::operator >= (Fixed const &b) const
{
	return (this->value >= b.value);
}

bool Fixed::operator == (Fixed const &b) const
{
	return (this->value == b.value);
}

bool Fixed::operator != (Fixed const &b) const
{
		return (this->value != b.value);
}

Fixed Fixed::operator + (Fixed const &b)
{
	Fixed temp;
	temp.value = this->value + b.value;
	return (temp);
}

Fixed Fixed::operator - (Fixed const &b)
{
	Fixed temp;
	temp.value = this->value - b.value;
	return (temp);
}

Fixed Fixed::operator * (Fixed const &b)
{
	Fixed temp;
	temp.value = this->value * b.toFloat();
	return (temp);
}

Fixed Fixed::operator / (Fixed const &b)
{
	Fixed temp;
	temp.value = this->value / b.toFloat();
	return (temp);
}

Fixed Fixed::operator ++ (void)
{
	this->value += 1;
	return (*this);
}

Fixed Fixed::operator -- (void)
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed old = *this;

	operator++();
	return (old);
}

Fixed Fixed::operator -- (int)
{
	Fixed old = *this;
	operator--();
	return (old);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (b >= a)
		return (b);
	else
		return (a);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (b >= a)
		return (b);
	else
		return (a);
}

