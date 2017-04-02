#define BOOST_TEST_MODULE Sorter Logger Decorator Unit Tests
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "sorter_logging_decorator.h"

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

std::vector<int> GetAnyVector()
{
    return std::vector<int> { 3, 6, 1, -3 };
}

BOOST_AUTO_TEST_CASE(Sort_AnyArray_LogStartWithArrayFollowedByLogStopWithArray)
{
    // Arrange
    testState state;
    sorter_logging_decorator<int, fakeSorter, fakeLogger> decorator(
        (fakeSorter(state)),
        (fakeLogger(state)));
    std::vector<testState::functionCall> expectedCalls {
        testState::logStart,
        testState::sort,
        testState::logEnd
    };
    auto anyVector = GetAnyVector();

    // Act
    decorator.sort(anyVector);

    // Assert
    BOOST_TEST(expectedCalls == state.functionsCalled);
}
