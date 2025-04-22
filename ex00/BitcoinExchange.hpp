#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::map;
using std::string;

class BitcoinExchange
{
private:
    map<string, double> btcRates;

    bool isValidDate(const string &date);
    int isValidValue(const string &value);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    bool loadDatabase(const string &filename);
    double getBitcoinRate(const string &date);
    void processInputFile(const string &filename);
    void trimspace(std::string &str);
};
