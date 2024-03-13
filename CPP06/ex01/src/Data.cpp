#include "Data.hpp"

Data::Data()
{
	std::cout << "Default data constructor called" << std::endl;
}

Data::Data(const Data &old) : type(old.type)
{
	std::cout << "Copy data constructor called" << std::endl;
}

Data& Data::operator=(const Data& old)
{
	if (this != &old)
	{
		type = old.type;
	}
	return *this;
}

Data::~Data()
{
	std::cout << "Data destructor called" << std::endl;
}