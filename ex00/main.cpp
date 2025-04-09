#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

bool isValidDate(const std::string &date)
{
    return date.size() == 10 && date[4] == '-' && date[7] == '-';
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange exchange("data.csv");
        std::ifstream input(argv[1]);
        if (!input.is_open())
        {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }

        std::string line;
        std::getline(input, line);

        while (std::getline(input, line))
        {
            std::istringstream iss(line);
            std::string date, valueStr;

            if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr))
            {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }

            date = date.substr(0, date.find_last_not_of(" \t\r\n") + 1);
            valueStr = valueStr.substr(valueStr.find_first_not_of(" \t\r\n"));

            if (!isValidDate(date))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }

            try
            {
                std::stringstream ss(valueStr);
                float value;
                ss >> value;

                if (value < 0)
                    throw std::runtime_error("Error: not a positive number.");
                if (value > 1000)
                    throw std::runtime_error("Error: too large a number.");

                float rate = exchange.getRate(date);
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
