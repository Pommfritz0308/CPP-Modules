#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{

}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "BitcoinExchange destructor called" << std::endl;
}

