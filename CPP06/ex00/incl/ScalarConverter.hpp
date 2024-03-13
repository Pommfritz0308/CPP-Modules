#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
# include <string>
# include <cctype>
# include <iostream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include <cerrno>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define YBOLD(x) "\x1B[1m" + std::string(KYEL) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

typedef struct s_data
{
	std::string str;
	void (*f)(std::string);
}				t_data;

class ScalarConverter
{
	public:
		ScalarConverter(const ScalarConverter &old);
		ScalarConverter& operator=(const ScalarConverter& old);
		~ScalarConverter();

		static std::string getType(std::string str);
		static std::string checkSpecialCases(std::string str);
		static void toChar(std::string str);
		static void toInt(std::string str);
		static void toFloat(std::string str);
		static void toDouble(std::string str);
		static void convert(std::string str);

	private:
		ScalarConverter(); //private constructor = class not instanciable
};

#endif
