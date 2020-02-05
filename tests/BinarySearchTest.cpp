#include <gtest/gtest.h>
#include <vector>
#include "algorithms/BinarySearch.hpp"

TEST(BinarySearchTest, emptyInputTest) {
    const std::vector<int> v;
    const auto binarySearchResult = algos::binary_search(v.begin(), v.end(), 0);
    const auto lowerBoundResult = algos::binary_search(v.begin(), v.end(), 0);
    const auto upperBoundResult = algos::binary_search(v.begin(), v.end(), 0);
    EXPECT_EQ(binarySearchResult, v.end());
    EXPECT_EQ(lowerBoundResult, v.end());
    EXPECT_EQ(upperBoundResult, v.end());
}

TEST(BinarySearchTest, simpleInputTest) {
    const std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int elemToSearch = 7;
    const auto result = algos::binary_search(v.begin(), v.end(), elemToSearch);
    EXPECT_EQ(*result, elemToSearch);
}

TEST(BinarySearchTest, simpleInputNoFoundElementTest) {
    const std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int elemToSearch = 0;
    const auto result = algos::binary_search(v.begin(), v.end(), elemToSearch);
    EXPECT_EQ(result, v.end());
}

TEST(BinarySearchTest, simpleLowerBoundTest) {
    const std::vector<int> v{1, 2, 3, 3, 3, 3, 8, 9};
    const int elemToSearch = 3;
    const auto actualResult = algos::lower_bound(v.begin(), v.end(), elemToSearch);
    const auto expectedResult = std::lower_bound(v.begin(), v.end(), elemToSearch);
    EXPECT_EQ(actualResult, expectedResult);
}

TEST(BinarySearchTest, simpleUpperBoundTest) {
    const std::vector<int> v{1, 2, 3, 3, 3, 3, 8, 9};
    const int elemToSearch = 3;
    const auto actualResult = algos::upper_bound(v.begin(), v.end(), elemToSearch);
    const auto expectedResult = std::upper_bound(v.begin(), v.end(), elemToSearch);
    EXPECT_EQ(actualResult, expectedResult);
}
