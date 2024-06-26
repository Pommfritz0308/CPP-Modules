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
        std::cout << RBOLD("Before: ");
        for (int i = 1; argv[i]; i++)
        {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
        PmergeMeVector p(argv + 1, argc - 1);
        p.setStart();
        p.FJ();
        p.setEnd();
        std::cout << GBOLD("After: ") << p.getList();
        p.printDuration(argc - 1);
        std::cout << std::endl;

        std::cout << RBOLD("Before: ");
        for (int i = 1; argv[i]; i++)
        {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
        PmergeMeDeque p2(argv + 1, argc - 1);
        p2.setStart();
        p2.FJ();
        p2.setEnd();
        std::cout << GBOLD("After: ") << p2.getList();
        p2.printDuration(argc - 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}