#include "Array.hpp"

int main( void )
{
    Array<int> numbers(5);
    Array<std::string> strings(5);
    Array<double> doubles(5);

    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        numbers[i] = i;
        doubles[i] = i + 0.5;
        std::ostringstream oss;
        oss << "Index: " << i;
        strings[i] = oss.str();
    }
    try
    {
        for (unsigned int i = 0; i < numbers.size(); i++)
        {
            std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
            std::cout << "doubles[" << i << "] = " << doubles[i] << std::endl;
            std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
        }
        std::cout << "numbers[5] = " << numbers[5] << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}