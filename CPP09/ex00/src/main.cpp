#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    if (argc > 2 || argc == 1)
    {
        std::cerr << "Usage: ./bitcoin [input file]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.loadDatabase(argv[1]);
}