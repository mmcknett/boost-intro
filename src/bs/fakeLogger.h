#pragma once

#include "logger.h"
#include "sorterLoggingDecoratorTestState.h"

class fakeLogger : public logger<int>
{
public:
    fakeLogger(sorterLoggingDecoratorTestState& state)
        : _state(state)
    {
    }

    ~fakeLogger() { }

    virtual void logStart(const std::vector<int>& /*vec*/) override
    {
        _state.functionsCalled.push_back(sorterLoggingDecoratorTestState::logStart);
    }

    virtual void logStop(const std::vector<int>& /*vec*/) override
    {
        _state.functionsCalled.push_back(sorterLoggingDecoratorTestState::logEnd);
    }

private:
    sorterLoggingDecoratorTestState& _state;
};
