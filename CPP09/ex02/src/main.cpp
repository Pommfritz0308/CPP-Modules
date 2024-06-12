#include "PmergeMeVector.hpp"
#include "PmergeMeDeque.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: ./rpn <sequence of positive integers>" << std::endl;
        return 1;
    }
    try
    {
        PmergeMeVector p(argv + 1);
        std::cout << RBOLD("Before: ") << p.getV();
        p.setStart();
        p.FJ(p.getSize());
        p.setEnd();
        std::cout << GBOLD("After: ") << p.getV();
        p.printDuration();

        std::cout << std::endl;

        // PmergeMeDeque p2(argv + 1);
        // std::cout << RBOLD("Before: ") << p2.getD();
        // p2.setStart();
        // p2.FJ(0, p2.getSize());
        // p2.setEnd();
        // std::cout << GBOLD("After: ") << p2.getD();
        // p2.printDuration();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}