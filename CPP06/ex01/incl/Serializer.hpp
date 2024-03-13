#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
# include "Data.hpp"
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include <cerrno>
# include <stdint.h>

class Data;

class Serializer
{
	public:
		~Serializer();
		Serializer(const Serializer &old);
		Serializer& operator=(const Serializer& old);
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
};

#endif
