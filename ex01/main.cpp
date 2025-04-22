#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        cerr << "Error: Please provide a single RPN expression." << endl;
        return 1;
    }

    RPN calculator;

    try
    {
        int result = calculator.evaluate(av[1]);

        cout << result << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
