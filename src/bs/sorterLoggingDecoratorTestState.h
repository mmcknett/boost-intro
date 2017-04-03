#pragma once

#include <vector>

struct sorterLoggingDecoratorTestState
{
    enum functionCall
    {
        sort,
        logStart,
        logEnd,
    };

    std::vector<functionCall> functionsCalled;
};
