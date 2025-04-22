#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cerr;
using std::cout;
using std::deque;
using std::endl;
using std::string;
using std::vector;

class PmergeMe
{
private:
    vector<int> vectorContainer;
    deque<int> dequeContainer;

    void insertionSortVector(vector<int> &vec);
    void insertionSortDeque(deque<int> &deq);

    void mergeInsertionSortVector(vector<int> &vec);
    void mergeInsertionSortDeque(deque<int> &deq);

    void printVec();
    void printDeq();

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void processInput(int argc, char **argv);

    void sortAndMeasure();
};
