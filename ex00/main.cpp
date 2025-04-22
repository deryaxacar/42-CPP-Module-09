#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        cerr << "Error: could not open file." << endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;

        if (!btc.loadDatabase("data.csv"))
            throw std::runtime_error("Error: failed to load database.");

        btc.processInputFile(av[1]);
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
