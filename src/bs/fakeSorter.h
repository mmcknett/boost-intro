#pragma once

#include "sorter.h"
#include "testState.h"

class fakeSorter : public sorter<int>
{
public:
    fakeSorter(testState& state)
        : _state(state)
    {
    }

    ~fakeSorter() { }

    virtual void sort(std::vector<int>& /*vec*/) override
    {
        _state.functionsCalled.push_back(testState::sort);
    }

private:
    testState& _state;
};
