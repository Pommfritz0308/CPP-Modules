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

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::cout << "Opening database " << std::endl;
    std::ifstream db("data.csv");
    if (!db)
    {
        throw std::runtime_error("Error: could not open database file.");
    }
    std::ifstream input(filename.c_str());
    if (!input)
    {
        throw std::runtime_error("Error: could not open input file.");
    }
    std::map<double, double> prices; 
    std::string line;
    //skip first line
    std::getline(db, line);
    while (std::getline(db, line))
    {
        std::istringstream iss(line);
        std::string date;
        std::getline(iss, date, ',');
        isValidDate(date);
        std::stringstream ss(date);
        double dateValue;
        ss >> dateValue;
        if (ss.fail() || ss.get() != EOF)
        {
            throw std::runtime_error("Error: invalid date format.");
        }
        std::string price;
        std::getline(iss, price);
        double priceValue;
        ss >> priceValue;
        if (ss.fail() || ss.get() != EOF)
        {
            throw std::runtime_error("Error: invalid price format.");
        }
        prices[dateValue] = priceValue;
    }
}

void isValidDate(const std::string& date)
{
    struct tm tm;
    char last;
    if (std::sscanf(date.c_str(), "%d-%d-%d%c", &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &last) == 3)
    {
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
}