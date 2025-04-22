#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : btcRates(other.btcRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->btcRates = other.btcRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    std::istringstream ss(date);
    char dash1, dash2;

    if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
        return false;

    if (year < 2009 || year > 2025)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (year == 2009 && month == 1 && day == 1)
        return false;

    int daysInMonth[] = {
        31,
        (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28,
        31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

int BitcoinExchange::isValidValue(const std::string &value)
{
    double num;
    if (!(std::istringstream(value) >> num))
        return -1;
    if (num < 0)
        return 0;
    if (num > 1000)
        return 1;
    return 2;
}
bool BitcoinExchange::loadDatabase(const string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        cerr << "Error: Could not open database file." << endl;
        return false;
    }

    for (string line; std::getline(file, line);)
    {
        std::istringstream ss(line);
        string date;
        double price;

        if (std::getline(ss, date, ',') && (ss >> price))
            btcRates[date] = price;
    }

    file.close();
    return true;
}

double BitcoinExchange::getBitcoinRate(const string &date)
{
    map<string, double>::iterator it = btcRates.lower_bound(date);

    if (it == btcRates.end())
        --it;
    else if (it->first != date && it != btcRates.begin())
        --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        cerr << "Error: Could not open input file." << endl;
        return;
    }

    string line;
    bool fLineCheck = false;

    while (std::getline(file, line))
    {
        if (!fLineCheck)
        {
            fLineCheck = true;
            if (line != "date | value")
            {
                cerr << "Error: Input file format is incorrect. First line must be 'date | value'." << endl;
                return;
            }
            continue;
        }

        std::istringstream ss(line);
        string date, valueStr;
        double value;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            trimspace(date);
            trimspace(valueStr);

            if (!isValidDate(date))
            {
                cerr << "Error: bad input => " << date << endl;
                continue;
            }

            int valueCheck = isValidValue(valueStr);
            if (valueCheck == -1)
            {
                cerr << "Error: bad input => " << line << endl;
                continue;
            }

            if (valueCheck == 0)
            {
                cerr << "Error: not a positive number." << endl;
                continue;
            }

            if (valueCheck == 1)
            {
                cerr << "Error: too large a number." << endl;
                continue;
            }

            value = std::atof(valueStr.c_str());

            double rate = getBitcoinRate(date);

            double res = value * rate;

            cout << date << " => " << value << " = " << res << endl;
        }
        else
            cerr << "Error: bad input => " << line << endl;
    }
    file.close();
}

void BitcoinExchange::trimspace(string &str)
{
    size_t start = str.find_first_not_of(" ");

    size_t end = str.find_last_not_of(" ");

    if (start == std::string::npos || end == std::string::npos)
    {
        str.clear();
    }
    else
    {
        str = str.substr(start, end - start + 1);
    }
}
