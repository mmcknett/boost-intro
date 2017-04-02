#pragma once

#include "logger.h"
#include "testState.h"

class fakeLogger : public logger<int>
{
public:
    fakeLogger(testState& state)
        : _state(state)
    {
    }

    ~fakeLogger() { }

    virtual void logStart(const std::vector<int>& /*vec*/) override
    {
        _state.functionsCalled.push_back(testState::logStart);
    }

    virtual void logStop(const std::vector<int>& /*vec*/) override
    {
        _state.functionsCalled.push_back(testState::logEnd);
    }

private:
    testState& _state;
};
