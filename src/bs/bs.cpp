#include "bubble_sort.h"
#include "cerr_perf_logger.h"
#include "sorter_logging_decorator.h"

std::vector<int> readStdInForInts();
void sort(std::vector<int>& inputToSort);
void printToStdOut(const std::vector<int>& ints);

int main()
{
    std::vector<int> inputToSort = readStdInForInts();
    sort(inputToSort);
    printToStdOut(inputToSort);

    return 0;
}

std::vector<int> readStdInForInts()
{
    std::vector<int> inputToSort;

    int lastInt;
    while(std::cin >> lastInt)
    {
        inputToSort.push_back(lastInt);
    }

    return inputToSort;
}

void sort(std::vector<int>& inputToSort)
{
    bubble_sort coreSorter;
    cerr_perf_logger<int> logger;
    sorter_logging_decorator<int, bubble_sort, cerr_perf_logger<int>> sorter(
        std::move(coreSorter),
        std::move(logger));

    sorter.sort(inputToSort);
}

void printToStdOut(const std::vector<int>& ints)
{
    for(int i : ints)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}
