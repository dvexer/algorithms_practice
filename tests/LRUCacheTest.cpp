#include <gtest/gtest.h>
#include <string>
#include "data_structures/LRUCache.hpp"


TEST(LRUCacheTest, zeroCapacityCacheTest) {
    LRUCache<int, std::string> cache(0);
    cache.put(0, "zero");
    const auto val = cache.get(0);
    EXPECT_FALSE(val.has_value());
}

TEST(LRUCacheTest, singleElemCacheTest) {
    LRUCache<int, std::string> cache(1);
    cache.put(0, "zero");
    const auto val = cache.get(0);
    ASSERT_TRUE(val.has_value());
    EXPECT_EQ("zero", val.value());
}

TEST(LRUCacheTest, simpleCacheTest) {
    LRUCache<int, std::string> cache(3);
    cache.put(0, "zero");
    cache.put(1, "one");
    cache.put(2, "two");
    const auto val = cache.get(2);
    ASSERT_TRUE(val.has_value());
    EXPECT_EQ("two", val.value());
}

TEST(LRUCacheTest, extraElemCacheTest1) {
    LRUCache<int, std::string> cache(3);
    cache.put(0, "zero");
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    const auto val = cache.get(3);
    ASSERT_TRUE(val.has_value());
    EXPECT_EQ("three", val.value());
}

TEST(LRUCacheTest, extraElemCacheTest2) {
    LRUCache<int, std::string> cache(3);
    cache.put(0, "zero");
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    const auto val = cache.get(0);
    EXPECT_FALSE(val.has_value());
}

TEST(LRUCacheTest, updateElemOrderCacheTest) {
    LRUCache<int, std::string> cache(4);
    cache.put(0, "zero");
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(3, "three");
    const auto val = cache.get(0);
    ASSERT_TRUE(val.has_value());
    EXPECT_EQ("zero", cache.top().value());
}

TEST(LRUCacheTest, updateElemCacheTest) {
    LRUCache<int, std::string> cache(3);
    cache.put(0, "zero");
    cache.put(1, "one");
    cache.put(2, "two");
    cache.put(2, "TWO");
    const auto val = cache.get(2);
    ASSERT_TRUE(val.has_value());
    EXPECT_EQ("TWO", val.value());
}

TEST(LRUCacheTest, complexCacheTest) {
    const auto capacity = 30;
    const auto total_elems = 50;

    LRUCache<int, std::string> cache(capacity);
    for (int i = 0; i < total_elems; ++i) {
        cache.put(i, std::to_string(i));
    }
    const auto erased_val = cache.get(total_elems - capacity - 1);
    EXPECT_FALSE(erased_val.has_value());

    const auto oldest_val = cache.get(total_elems - capacity);
    ASSERT_TRUE(oldest_val.has_value());
    EXPECT_EQ(std::to_string(total_elems - capacity), oldest_val.value());
    EXPECT_EQ(std::to_string(total_elems - capacity), cache.top().value());

    const auto newest_val = cache.get(total_elems - 1);
    ASSERT_TRUE(newest_val.has_value());
    EXPECT_EQ(std::to_string(total_elems - 1), newest_val.value());
    EXPECT_EQ(std::to_string(total_elems - 1), cache.top().value());
}
