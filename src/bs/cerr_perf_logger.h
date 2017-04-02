#pragma once

#include <iostream>
#include "logger.h"

template<typename T>
class cerr_perf_logger : public logger<T>
{
public:
    virtual ~cerr_perf_logger() { }
    virtual void logStart(const std::vector<T>& vec) override;
    virtual void logStop(const std::vector<T>& vec) override;
};


template<typename T>
void cerr_perf_logger<T>::logStart(const std::vector<T>& vec)
{
    std::cerr << "Testing Start" << std::endl;
}

template<typename T>
void cerr_perf_logger<T>::logStop(const std::vector<T>& vec)
{
    std::cerr << "Testing End" << std::endl;
}
