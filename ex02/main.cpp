#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        cerr << "Error: Please provide a sequence of numbers." << endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.processInput(ac, av);
        sorter.sortAndMeasure();
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
