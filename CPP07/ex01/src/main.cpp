#include "iter.hpp"

void print_str(std::string &s)
{
	std::cout << s << std::endl;
}

void print_int(int &i)
{
    std::cout << i << std::endl;
}

int main( void )
{
    std::string a[] = {"hello world!", "this is a test",
        "this is a test", "this is a test", "this is a test"};
    int b[] = {1, 2, 3, 4, 5};
    std::cout << GBOLD("Printing strings") << std::endl;
    iter(a, 5, print_str);
    std::cout << GBOLD("Printing integers") << std::endl;
    iter(b, 5, print_int);
    return 0;
}