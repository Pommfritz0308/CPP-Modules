#include "easyfind.hpp"

int main (void)
{
    std::vector<int> container;
    for (int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }
    try{
        easyfind(container, 5);
        std::cout << GBOLD("Value found") << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << RBOLD("Value not found") << std::endl;
    }
    return (0);
}