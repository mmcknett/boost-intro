#define BOOST_TEST_MODULE Sorting Unit Tests
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "bubble_sort.h"

BOOST_AUTO_TEST_CASE(Sort_EmptyArray_ArrayIsEmpty)
{
  // Arrange
  std::vector<int> emptyVector;
  bubble_sort sorter;

  // Act
  sorter.sort(emptyVector);

  // Assert
  BOOST_TEST(0 == emptyVector.size());
}

BOOST_AUTO_TEST_CASE(Sort_OneElementArray_ArrayIsUnchanged)
{
  // Arrange
  const int expectedValue = -2;
  std::vector<int> testVec{expectedValue};
  bubble_sort sorter;

  // Act
  sorter.sort(testVec);

  // Assert
  BOOST_TEST(1 == testVec.size());
  BOOST_TEST(expectedValue == testVec[0]);
}

BOOST_AUTO_TEST_CASE(Sort_TwoElementsAlreadySorted_ArrayIsUnchanged)
{
  // Arrange
  const int first = -2;
  const int second = 10;
  std::vector<int> testVec{first, second};
  bubble_sort sorter;

  // Act
  sorter.sort(testVec);

  // Assert
  BOOST_TEST(2 == testVec.size());
  BOOST_TEST(first == testVec[0]);
  BOOST_TEST(second == testVec[1]);
}

BOOST_AUTO_TEST_CASE(Sort_TwoElementsUnsorted_ArrayIsUnchanged)
{
  // Arrange
  const int first = -2;
  const int second = 10;
  std::vector<int> testVec{second, first};
  bubble_sort sorter;

  // Act
  sorter.sort(testVec);

  // Assert
  BOOST_TEST(2 == testVec.size());
  BOOST_TEST(first == testVec[0]);
  BOOST_TEST(second == testVec[1]);
}

BOOST_AUTO_TEST_CASE(Sort_FiveElementsUnsorted_ArrayIsUnchanged)
{
  // Arrange
  const int i1 = -2;
  const int i2 = 10;
  const int i3 = 11;
  const int i4 = 15;
  const int i5 = 18;
  std::vector<int> testVec{i4, i5, i3, i2, i1};
  bubble_sort sorter;

  // Act
  sorter.sort(testVec);

  // Assert
  BOOST_TEST(5 == testVec.size());
  BOOST_TEST(i1 == testVec[0]);
  BOOST_TEST(i2 == testVec[1]);
  BOOST_TEST(i3 == testVec[2]);
  BOOST_TEST(i4 == testVec[3]);
  BOOST_TEST(i5 == testVec[4]);
}

BOOST_AUTO_TEST_CASE(Sort_FiveElementsAlreadySorted_ArrayIsUnchanged)
{
  // Arrange
  const int i1 = -2;
  const int i2 = 10;
  const int i3 = 11;
  const int i4 = 15;
  const int i5 = 18;
  std::vector<int> testVec{i1, i2, i3, i4, i5};
  bubble_sort sorter;

  // Act
  sorter.sort(testVec);

  // Assert
  BOOST_TEST(5 == testVec.size());
  BOOST_TEST(i1 == testVec[0]);
  BOOST_TEST(i2 == testVec[1]);
  BOOST_TEST(i3 == testVec[2]);
  BOOST_TEST(i4 == testVec[3]);
  BOOST_TEST(i5 == testVec[4]);
}
