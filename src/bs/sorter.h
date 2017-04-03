#pragma once

#include <vector>

template<typename T>
class sorter
{
public:
    virtual ~sorter() { }
    virtual void sort(std::vector<T>& vec) = 0;
};
