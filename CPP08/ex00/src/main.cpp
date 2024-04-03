#include "easyfind.hpp"

int main (void)
{
    std::vector<int> container;
    for (int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }
    int n = 5;
    try{
            easyfind(container, n);
            std::cout << GBOLD("Value ") << container[n] << GBOLD(" found") << std::endl;
            n = -1;
            easyfind(container, n);
            std::cout << GBOLD("Value ") << container[n] << GBOLD(" found") << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << RBOLD("Value ") << n << RBOLD(" not found") << std::endl;
    }
    return (0);
}