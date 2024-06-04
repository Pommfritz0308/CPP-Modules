#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: ./rpn <sequence of positive integers>" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe p(argv + 1);
        p.pairing(0, p.getSize());
        std::cout << p.getV();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}