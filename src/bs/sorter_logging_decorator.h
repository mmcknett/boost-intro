#pragma once

#include "logger.h"
#include "sorter.h"

template<typename T, class TSorter, class TLogger>
class sorter_logging_decorator : public sorter<T>
{
public:
    sorter_logging_decorator(
        TSorter&& wrappedSorter,
        TLogger&& logger);
    virtual void sort(std::vector<T>& vec) override;

private:
    TSorter _wrappedSorter;
    TLogger _logger;
};

template<typename T, class TSorter, class TLogger>
sorter_logging_decorator<T, TSorter, TLogger>::sorter_logging_decorator(
    TSorter&& wrappedSorter,
    TLogger&& logger)
    : _wrappedSorter(wrappedSorter)
    , _logger(logger)
{
}

template<typename T, class TSorter, class TLogger>
void sorter_logging_decorator<T, TSorter, TLogger>::sort(
    std::vector<T>& vec)
{
    _logger.logStart(vec);
    _wrappedSorter.sort(vec);
    _logger.logStop(vec);
}
