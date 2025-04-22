#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
    : vectorContainer(other.vectorContainer), dequeContainer(other.dequeContainer) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vectorContainer = other.vectorContainer;
        dequeContainer = other.dequeContainer;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInput(int ac, char **av)
{
    for (int i = 1; i < ac; ++i)
    {
        string arg = av[i];
        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!isdigit(arg[j]))
            {
                throw std::runtime_error("Error: Invalid input (" + arg + ")");
            }
        }

        int num = std::atoi(arg.c_str());

        if (num <= 0)
        {
            throw std::runtime_error("Error: Input must be positive integers only.");
        }

        vectorContainer.push_back(num);
        dequeContainer.push_back(num);
    }
}

void PmergeMe::insertionSortVector(vector<int> &vec)
{
    for (size_t i = 1; i < vec.size(); ++i)
    {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::insertionSortDeque(deque<int> &deq)
{
    for (size_t i = 1; i < deq.size(); ++i)
    {
        int key = deq[i];
        int j = i - 1;

        while (j >= 0 && deq[j] > key)
        {
            deq[j + 1] = deq[j];
            --j;
        }

        deq[j + 1] = key;
    }
}

void PmergeMe::mergeInsertionSortVector(vector<int> &vec)
{
    if (vec.size() < 10)
    {
        insertionSortVector(vec);
        return;
    }

    vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
    vector<int> right(vec.begin() + vec.size() / 2, vec.end());

    mergeInsertionSortVector(left);
    mergeInsertionSortVector(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), vec.begin());
}

void PmergeMe::mergeInsertionSortDeque(deque<int> &deq)
{
    if (deq.size() < 10)
    {
        insertionSortDeque(deq);
        return;
    }

    deque<int> left(deq.begin(), deq.begin() + deq.size() / 2);
    deque<int> right(deq.begin() + deq.size() / 2, deq.end());

    mergeInsertionSortDeque(left);
    mergeInsertionSortDeque(right);

    std::merge(left.begin(), left.end(), right.begin(), right.end(), deq.begin());
}

void PmergeMe::printVec()
{
    size_t size = vectorContainer.size();

    if (size <= 10)
    {
        for (size_t i = 0; i < size; i++)
            cout << vectorContainer[i] << " ";
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
            cout << vectorContainer[i] << " ";
        cout << "[...] ";
    }
    cout << endl;
}

void PmergeMe::printDeq()
{
    size_t size = dequeContainer.size();

    if (size <= 10)
    {
        for (size_t i = 0; i < size; i++)
            cout << dequeContainer[i] << " ";
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
            cout << dequeContainer[i] << " ";

        cout << "[...] ";
    }

    cout << endl;
}

void PmergeMe::sortAndMeasure()
{
    cout << "Before (Vec): ";
    printVec();

    cout << "Before (Deq): ";
    printDeq();

    clock_t start, end;
    double vectorTime, dequeTime;

    start = clock();
    mergeInsertionSortVector(vectorContainer);
    end = clock();

    vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    start = clock();
    mergeInsertionSortDeque(dequeContainer);
    end = clock();

    dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

    cout << "After (Vec): ";
    printVec();

    cout << "After (Deq): ";
    printDeq();

    cout << std::fixed << std::setprecision(5);

    cout << "Time to process a range of " << vectorContainer.size()
         << " elements with std::vector : " << vectorTime << " us" << endl;

    cout << "Time to process a range of " << dequeContainer.size()
         << " elements with std::deque : " << dequeTime << " us" << endl;
}