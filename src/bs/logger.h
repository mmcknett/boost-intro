#pragma once

#include <vector>

template<typename T>
class logger
{
public:
    virtual ~logger() { }
    virtual void logStart(const std::vector<T>& vec) = 0;
    virtual void logStop(const std::vector<T>& vec) = 0;
};
