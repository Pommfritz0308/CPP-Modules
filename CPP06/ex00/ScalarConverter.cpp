#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &old)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = old;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& old)
{
	std::cout << "Assignation operator called" << std::endl;
	(void)old;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

std::string ScalarConverter::checkChar(std::string str)
{
	if (str.length() == 1 && isprint(str[0]) && isalpha(str[0]))
	{
		std::cout << str[0] << std::endl;
		std::cout << static_cast<int>(str[0]) << std::endl;
	}
}

std::string ScalarConverter::checkNumb(std::string str)
{
	
}

void ScalarConverter::checkType(std::string str)
{

}
void ScalarConverter::convert(std::string str)
{
	if (str.empty())
	{
		std::cout << RBOLD("Error: <Expected a string literal>\n");
		return;
	}
	
}
