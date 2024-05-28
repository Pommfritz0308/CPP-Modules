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

void BitcoinExchange::compareInput(const std::string& filename)
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
        size_t dateValue;
        try {
            dateValue = DateToSizeT(date);
        } catch (const std::runtime_error& e) {
            std::cout << "Error: invalid date format in input => " << date << std::endl;
            continue;
        }
        std::string value;
        std::getline(iss, value);
        if (value == "")
            std::cout << "Error: bad input => " << date << std::endl;
        else {
            std::stringstream ss(value);
            double exchangeValue;
            ss >> exchangeValue;
            if (std::numeric_limits<int>::max() < exchangeValue)
                std::cout << "Error: too large a number." << std::endl;
            else if (exchangeValue < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << date << "=> " << exchangeValue << " = " << prices.lower_bound(dateValue)->second * exchangeValue << std::endl;
        }
    }
}

// void BitcoinExchange::comparePrices()
// {
// }

size_t BitcoinExchange::DateToSizeT(const std::string& date)
{
    struct tm tm;
    std::memset(&tm, 0, sizeof(tm)); // Initialize all fields to zero
    char last;
    size_t dateValue;
    if (std::sscanf(date.c_str(), "%d-%d-%d %c", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &last) == 3 ||
        std::sscanf(date.c_str(), "%d-%d-%d%c", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &last) == 3)
    {
        // Check if month and day are within valid ranges
        if (tm.tm_mon < 1 || tm.tm_mon > 12 || tm.tm_mday < 1 || tm.tm_mday > 31)
        {
            throw std::runtime_error("Error: invalid date format.");
        }

        tm.tm_year -= 1900;
        tm.tm_mon -= 1;
        tm.tm_mday -= 1;
        if (std::mktime(&tm) == -1)
        {
            throw std::runtime_error("Error: invalid date format.");
        }
    }
    else
    {
        throw std::runtime_error("Error: invalid date format.");
    }
    dateValue = (tm.tm_year + 1900) * 10000 + (tm.tm_mon + 1) * 100 + (tm.tm_mday + 1);
    return (dateValue);
}