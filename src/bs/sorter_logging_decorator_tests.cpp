#define BOOST_TEST_MODULE Sorter Logger Decorator Unit Tests
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "fakeLogger.h"
#include "fakeSorter.h"
#include "sorter_logging_decorator.h"
#include "testState.h"

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
