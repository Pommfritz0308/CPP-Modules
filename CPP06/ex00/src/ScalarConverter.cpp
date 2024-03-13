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

std::string ScalarConverter::checkSpecialCases(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
	}
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
		return ("DOUBLE");
	else if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
		return ("FLOAT");
	return ("");
}

std::string ScalarConverter::getType(std::string str)
{
	int dot = 0;
	std::string type = checkSpecialCases(str);
	if (!type.empty())
			return (type);
	else if (str.length() == 1 && !isdigit(str[0]))
		type = "CHAR";
	else 
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if ((str[i] == '+' || str[i] == '-') && i == 0)
				continue;
			if (str[i] == '.')
				dot++;
			if (!isdigit(str[i]))
			{
				if (str[i] == 'f' && i== str.length() - 1)
					return ("FLOAT");
				else if (str[i] == '.' && dot < 2)
					continue;
				else
					return ("INVALID");
			}
		}
		if (dot == 1)
			type = "DOUBLE";
		else
			type = "INT";
	}
	return (type);
}

void ScalarConverter::toChar(std::string str)
{
	char c = str[0];
	if (isprint(c) == 0)
		std::cout << "char: not displayable\n";
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::toInt(std::string str)
{
	int i = atoi(str.c_str()); //conversion to int
	if (errno == ERANGE)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return;
	}
	else if (std::numeric_limits<char>::max() < i || std::numeric_limits<char>::min() > i)
		std::cout << "char: impossible\n";
	else if (isprint(i) == 0)
		std::cout << "char: not displayable\n";
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl; // static cast
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::toFloat(std::string str)
{
	float f = strtof(str.c_str(), NULL); //conversion to float
	if (errno == ERANGE || std::isnan(f) || std::isinf(f) || -std::isinf(f)) //check for nanf and inff
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
	}
	else
	{
		if (std::numeric_limits<char>::max() < f || std::numeric_limits<char>::min() > f)
			std::cout << "char: impossible\n";
		else if (isprint(f) == 0)
			std::cout << "char: not displayable\n";
		else
			std::cout << "char: " << static_cast<char>(f) << std::endl; // static cast
		if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::toDouble(std::string str)
{
	double d = strtod(str.c_str(), NULL); //conversion to double
	if (errno == ERANGE || std::isnan(d) || std::isinf(d) || -std::isinf(d)) // check for nan and inf
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	}
	else
	{
		if (std::numeric_limits<char>::max() < d || std::numeric_limits<char>::min() > d)
			std::cout << "char: impossible\n";
		else if (isprint(d) == 0)
			std::cout << "char: not displayable\n";
		else
			std::cout << "char: " << static_cast<char>(d) << std::endl; // static cast
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
			std::cout << "float: impossible\n";
		else
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
	}
}
void ScalarConverter::convert(std::string str)
{
	if (str.empty())
	{
		std::cout << RBOLD("Error: <Expected a string literal>\n");
		return;
	}
	std::string type = getType(str); // get type of input
	t_data data[] = {
		{ "CHAR", &ScalarConverter::toChar },
		{ "INT", &ScalarConverter::toInt },
		{ "FLOAT", &ScalarConverter::toFloat },
		{ "DOUBLE", &ScalarConverter::toDouble }}; // array of struct
	for (int i = 0; i < 4; i++)
	{
		if (type == data[i].str)
		{
			data[i].f(str); // call type function
			return;
		}
	}
	std::cout << RBOLD("Error: <Invalid input>\n");
	return;
}
