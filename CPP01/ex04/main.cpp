#include <cctype>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Expected input: <filename> <original> <replacement>" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	std::string newFile = std::string(argv[1]) + ".replace";
	std::ofstream outFile(newFile.c_str());
	std::string buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	if (!std::string(argv[2]).empty())
	{	
		for (int i = 0; i + std::string(argv[2]).length() < buffer.length(); i++)
			{
				if (buffer.substr(i, std::string(argv[2]).length()) == argv[2])
				{
					outFile << argv[3];
					i += std::string(argv[2]).length() - 1;
					continue;
				}
				outFile << buffer[i];
			}
	}
	else
		outFile << buffer;
	outFile.close();
	file.close();
	return (0);
}
