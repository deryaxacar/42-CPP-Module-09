#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dbFile)
{
    loadDatabase(dbFile);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr))
        {
            std::stringstream ss(valueStr);
            float value;
            ss >> value;
            _data[date] = value;
        }
    }
}

float BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    if (it != _data.end() && it->first == date)
        return it->second;

    if (it == _data.begin())
        throw std::runtime_error("Error: date too early.");

    --it;
    return it->second;
}
