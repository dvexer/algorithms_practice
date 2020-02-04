#include <gtest/gtest.h>
#include <vector>
#include "algorithms/BinarySearch.hpp"

using namespace algos;

TEST(BinarySearchTest, emptyInputTest)
{
    std::vector<int> v;
    const auto result = algos::binary_search(v.begin(), v.end(), 0);
    EXPECT_EQ(result, v.end());
}

TEST(BinarySearchTest, easyInputTest)
{
    const std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int elemToSearch = 7;
    const auto result = algos::binary_search(v.begin(), v.end(), elemToSearch);
    EXPECT_EQ(*result, elemToSearch);
}

TEST(BinarySearchTest, easyInputNoFoundElementTest)
{
    const std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    const int elemToSearch = 0;
    const auto result = algos::binary_search(v.begin(), v.end(), elemToSearch);
    EXPECT_EQ(result, v.end());
}
