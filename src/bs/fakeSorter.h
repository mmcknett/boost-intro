#pragma once

#include "sorter.h"
#include "sorterLoggingDecoratorTestState.h"

class fakeSorter : public sorter<int>
{
public:
    fakeSorter(sorterLoggingDecoratorTestState& state)
        : _state(state)
    {
    }

    ~fakeSorter() { }

    virtual void sort(std::vector<int>& /*vec*/) override
    {
        _state.functionsCalled.push_back(sorterLoggingDecoratorTestState::sort);
    }

private:
    sorterLoggingDecoratorTestState& _state;
};
