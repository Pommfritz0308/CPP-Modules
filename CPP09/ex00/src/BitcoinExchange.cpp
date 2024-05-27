#include "BitcoinExchange.hpp"

// BitcoinExchange::BitcoinExchange()
// {
//     std::cout << "BitcoinExchange default constructor called" << std::endl;
// }

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
// {

// }

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
// {

// }

// BitcoinExchange::~BitcoinExchange()
// {
//     std::cout << "BitcoinExchange destructor called" << std::endl;
// }

void BitcoinExchange::loadDatabase(void)
{
    std::cout << "Opening database " << std::endl;
    std::ifstream db("data.csv");
    if (!db)
    {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::string line;
    //skip first line
    std::getline(db, line);
    while (std::getline(db, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::getline(iss, date, ',');
        size_t dateValue = DateToSizeT(date);
        std::string price;
        std::getline(iss, price);
        std::stringstream ss(price);
        double priceValue;
        ss >> priceValue;
        if (ss.fail() || !ss.eof())
        {
            throw std::runtime_error("Error: invalid price format.");
        }
        prices[dateValue] = priceValue;
    }
}

void BitcoinExchange::loadInput(const std::string& filename)
{
    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        throw std::runtime_error("Error: could not open input file.");
    }
    std::string line;
    //skip first line
    std::getline(infile, line);
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::getline(iss, date, '|');
        size_t dateValue = DateToSizeT(date);
        std::string price;
        std::getline(iss, price);
        std::stringstream ss(price);
        double priceValue;
        ss >> priceValue;
        if (ss.fail() || !ss.eof())
        {
            throw std::runtime_error("Error: invalid price format.");
        }
        input[dateValue] = priceValue;
    }
    for (std::map<size_t, double>::iterator it = input.begin(); it != input.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

// void BitcoinExchange::comparePrices()
// {
// }

size_t BitcoinExchange::DateToSizeT(const std::string& date)
{
    struct tm tm;
    char last;
    size_t dateValue;
    if (std::sscanf(date.c_str(), "%d-%d-%d%c", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &last) == 3)
    {
        tm.tm_year -= 1900;
        tm.tm_mon -= 1;
        tm.tm_mday -= 1;
        if (std::mktime(&tm) == -1)
        {
            std::cout << "date: " << date << std::endl;
            throw std::runtime_error("Error: invalid date format.");
        }
    }
    else
    {
        std::cout << "date: " << date << std::endl;
        throw std::runtime_error("Error: invalid date format.");
    }
    dateValue = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + (tm.tm_mday + 1);
    return (dateValue);
}