#pragma once

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data;
    void loadDatabase(const std::string &filename);

public:
    // Canonical Form
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    BitcoinExchange(const std::string &dbFile);
    float getRate(const std::string &date) const;
};