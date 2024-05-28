#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
# include <iostream>
# include <exception>
# include <algorithm>
# include <string>
# include <cctype>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>
# include <vector>
# include <fstream>
# include <sstream>
# include <ctime>
# include <map>
# include <cstdio>
# include <cstring>
# define RST  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define GBOLD(x) "\x1B[1m" + std::string(KGRN) + x + RST
# define RBOLD(x) "\x1B[1m" + std::string(KRED) + x + RST
# define YBOLD(x) "\x1B[1m" + std::string(KYEL) + x + RST
# define BOLD(x) "\x1B[1m" << x << RST

class BitcoinExchange
{
    public:

        // BitcoinExchange();
        // BitcoinExchange(const BitcoinExchange& src);
        // BitcoinExchange& operator=(const BitcoinExchange& src);
        // ~BitcoinExchange();
        void loadDatabase(void);
        void compareInput(const std::string& filename);
        std::map<size_t, double> getPrices() const;

    private:
        size_t DateToSizeT(const std::string& date);
        std::map<size_t, double> prices;
};

#endif