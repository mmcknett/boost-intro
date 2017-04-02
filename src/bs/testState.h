#pragma once

#include <vector>

struct testState
{
    enum functionCall
    {
        sort,
        logStart,
        logEnd,
    };

    std::vector<functionCall> functionsCalled;
};
