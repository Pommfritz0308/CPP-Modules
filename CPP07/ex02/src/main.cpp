#include "Array.hpp"

int main( void )
{
    Array<int> numbers(5);
    Array<std::string> strings(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = i;
        strings[i] = "Test";
    }
    try
    {
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
            std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
        }
        std::cout << "numbers[5] = " << numbers[5] << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}