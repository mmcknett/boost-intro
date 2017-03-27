#include "bubble_sort.h"
#include <iostream>
#include <vector>

int main()
{

    std::vector<int> inputToSort;

    int lastInt;
    while(std::cin >> lastInt)
    {
        inputToSort.push_back(lastInt);
    }

    bubble_sort sorter;
    sorter.sort(inputToSort);

    for(int i : inputToSort)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
