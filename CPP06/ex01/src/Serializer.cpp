#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer()
{
	std::cout << "Default serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &old)
{
	std::cout << "Copy serializer constructor called" << std::endl;
	*this = old;
}

Serializer& Serializer::operator=(const Serializer& old)
{
	if (this != &old)
	{
		(void)old;
	}
	return *this;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}