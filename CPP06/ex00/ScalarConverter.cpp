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

void ScalarConverter::checkChar(std::string str)
{
	const char *arr = str.c_str(); //conversion to char
	std::cout << "Literal recognized: char\n";
	if (isprint(str[0]))
		std::cout << "char: " << arr[0] << std::endl;
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(arr[0]) << std::endl; // static cast
	std::cout << "float: " << static_cast<float>(arr[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(arr[0]) << std::endl;
}

int	strisdigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (0);
	}
	return (1);
}
void ScalarConverter::checkNumb(std::string str)
{
		if (str.find('f') == str.length() - 1)
		{	
			std::cout << "Literal recognized: float\n";
			float f = strtof(str.c_str(), NULL); //conversion to float
			if (std::isnan(f) || std::isinf(f) || -std::isinf(f)) //check for nanf and inff
			{
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
			else
			{
				if (isprint(f))
					std::cout << "char: " << static_cast<char>(f) << std::endl; // static cast
				else
					std::cout << "char: Non displayable\n";
				std::cout << "int: " << static_cast<int>(f) << std::endl;
				std::cout << "float: " << f << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(f) << std::endl;
			}
		}
		else
		{
			std::cout << "Literal recognized: double\n";
			double d = strtod(str.c_str(), NULL); //conversion to double
			if (std::isnan(d) || std::isinf(d) || -std::isinf(d)) // check for nan and inf
			{
				std::cout << "char: impossible\n";
				std::cout << "int: impossible\n";
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(d) << std::endl;
			}
			else
			{
				if (isprint(d))
					std::cout << "char: " << static_cast<char>(d) << std::endl; // static cast
				else
					std::cout << "char: Non displayable\n";
				std::cout << "int: " << d << std::endl;
				std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(d) << std::endl;
			}
		}
}

void ScalarConverter::convert(std::string str)
{
	if (str.empty())
	{
		std::cout << RBOLD("Error: <Expected a string literal>\n");
		return;
	}
	if (!isdigit(str[0]) && str.length() == 1)
		checkChar(str);
	else if (isdigit(str[0]) || str[0] == '-' || str[0] == '+' || str[0] == '.')
		checkNumb(str);
	else
		std::cout << RBOLD("Error: <Invalid input>\n");
}
