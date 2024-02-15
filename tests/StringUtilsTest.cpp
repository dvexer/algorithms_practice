#include <gtest/gtest.h>
#include "algorithms/StringUtils.hpp"
#include "algorithms/StringUtils.cpp"   // TODO: remove this hack


TEST(StringUtilsTest, emptyStringTest) {
    std::string s;
    algos::ReverseWordsOrder(s);
    EXPECT_EQ(s, "");
}

TEST(StringUtilsTest, spacesTest) {
    std::string s = "   ";
    algos::ReverseWordsOrder(s);
    EXPECT_EQ(s, "");
}

TEST(StringUtilsTest, singleWordTest) {
    std::string s = "Aloha";
    algos::ReverseWordsOrder(s);
    EXPECT_EQ(s, "Aloha");
}

TEST(StringUtilsTest, twoWordsStringTest) {
    std::string s = "hello world";
    algos::ReverseWordsOrder(s);
    EXPECT_EQ(s, "world hello");
}

TEST(StringUtilsTest, threeWordsStringTest) {
    std::string s = "life is good";
    algos::ReverseWordsOrder(s);
    EXPECT_EQ(s, "good is life");
}

TEST(StringUtilsTest, extraSpacesTest) {
    std::string s = "   life is  good ";
    algos::ReverseWordsOrder(s);
    EXPECT_EQ(s, "good is life");
}
