#include <gtest/gtest.h>
#include <vector>
#include "algorithms/SelectionSort.hpp"

TEST(SelectionSortTest, emptyInputTest) {
    std::vector<int> inputVector;
    const std::vector<int> expectedSortedVector;
    algos::selection_sort(inputVector.begin(), inputVector.end());
    EXPECT_EQ(expectedSortedVector, inputVector);
}

TEST(SelectionSortTest, simpleInputTest) {
    std::vector<int> inputVector{2, 0, 1, 5, 3, 4};
    const std::vector<int> expectedSortedVector{0, 1, 2, 3, 4, 5};
    algos::selection_sort(inputVector.begin(), inputVector.end());
    EXPECT_EQ(expectedSortedVector, inputVector);
}
