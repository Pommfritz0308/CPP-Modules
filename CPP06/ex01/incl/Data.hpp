#ifndef DATA_HPP
#define DATA_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include <cerrno>

class Data
{
	public:
		Data();
		Data(const Data &old);
		Data& operator=(const Data& old);
		~Data();

	private:
		std::string type;
};

#endif
