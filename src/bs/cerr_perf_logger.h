#pragma once

#include <chrono>
#include <iostream>
#include "logger.h"


template<typename T>
class cerr_perf_logger : public logger<T>
{
public:
    virtual ~cerr_perf_logger() { }
    virtual void logStart(const std::vector<T>& vec) override;
    virtual void logStop(const std::vector<T>& vec) override;

private:
    std::chrono::high_resolution_clock::time_point _startTime;
};


template<typename T>
void cerr_perf_logger<T>::logStart(const std::vector<T>& vec)
{
    using namespace std::chrono;
    _startTime = high_resolution_clock::now();
    std::cerr << "Sort started."
              << std::endl;
}

template<typename T>
void cerr_perf_logger<T>::logStop(const std::vector<T>& vec)
{
    using namespace std::chrono;

    high_resolution_clock::time_point endTime = high_resolution_clock::now();
    high_resolution_clock::duration highResDuration = endTime - _startTime;
    duration<double, std::ratio<1, 1000>> elapsedTime = highResDuration;

    std::cerr << "Sort ended. [ElapsedTime: "
              << elapsedTime.count()
              << " ms]"
              << std::endl;
}
