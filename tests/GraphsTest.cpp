#include <gtest/gtest.h>
#include "algorithms/GraphsUtils.hpp"
#include "algorithms/GraphsUtils.cpp"

TEST(GrapghsTest, emptyTest) {
    std::vector<std::vector<uint32_t>> v;
    EXPECT_EQ(dijkstra(v, 0, 0), std::nullopt);
}

TEST(GrapghsTest, simpleTest) {
    std::vector<std::vector<uint32_t>> v{{1, 2, 300}, {1, 3, 100}};
    EXPECT_EQ(dijkstra(v, 1, 2), 300);
    EXPECT_EQ(dijkstra(v, 1, 3), 100);
}

TEST(GrapghsTest, regularTest) {
    std::vector<std::vector<uint32_t>> v{{1, 2, 300}, {1, 3, 100}, {3, 4, 400}};
    EXPECT_EQ(dijkstra(v, 1, 2), 300);
    EXPECT_EQ(dijkstra(v, 1, 3), 100);
    EXPECT_EQ(dijkstra(v, 1, 4), 500);
}

TEST(GrapghsTest, complexTest) {
    std::vector<std::vector<uint32_t>> v{{1, 2, 200}, {1, 3, 300},
                                         {2, 5, 10000}, {2, 6, 250},
                                         {3, 4, 400}, {3, 5, 500}, {3, 6, 600},
                                         {6, 7, 700}};
    EXPECT_EQ(dijkstra(v, 1, 2), 200);
    EXPECT_EQ(dijkstra(v, 1, 3), 300);
    EXPECT_EQ(dijkstra(v, 1, 4), 700);
    EXPECT_EQ(dijkstra(v, 1, 5), 800);
    EXPECT_EQ(dijkstra(v, 1, 6), 450);
    EXPECT_EQ(dijkstra(v, 1, 7), 1150);
}

TEST(GrapghsTest, noneExistingNodeTest) {
    std::vector<std::vector<uint32_t>> v{{1, 2, 300}, {1, 3, 100}};
    EXPECT_EQ(dijkstra(v, 1, 4), std::nullopt);
}

TEST(GrapghsTest, unreachableNodeTest) {
    std::vector<std::vector<uint32_t>> v{{1, 2, 300}, {1, 3, 100}, {4, 5, 400}};
    EXPECT_EQ(dijkstra(v, 1, 4), std::nullopt);
}

// ************************************ Adjacency dijkstra tests ************************************

TEST(GrapghsTest, emptyAdjTest) {
    std::array<std::array<uint32_t, 0>, 0> m{};
    EXPECT_EQ(dijkstra<0>(m, 0, 0), std::nullopt);
}

TEST(GrapghsTest, singleElemAdjTest) {
    std::array<std::array<uint32_t, 1>, 1> m{0};
    EXPECT_EQ(dijkstra<1>(m, 0, 0), 0);
}

TEST(GrapghsTest, simpleAdjTest) {
    std::array<std::array<uint32_t, 3>, 3> m = {0, 1, 2,
                                                1, 0, 3,
                                                2, 3, 0};
    EXPECT_EQ(dijkstra<3>(m, 0, 0), 0);
    EXPECT_EQ(dijkstra<3>(m, 0, 1), 1);
    EXPECT_EQ(dijkstra<3>(m, 1, 0), 1);
    EXPECT_EQ(dijkstra<3>(m, 0, 2), 2);
    EXPECT_EQ(dijkstra<3>(m, 1, 2), 3);
}

TEST(GrapghsTest, complexAdjTest) {
    std::array<std::array<uint32_t, 5>, 5> m = {0, 1,  2,  3,  0,
                                                1, 0,  12, 0,  0,
                                                2, 12, 0,  0,  0,
                                                3, 0,  0,  0,  34,
                                                0, 0,  0,  34,  0,};
    EXPECT_EQ(dijkstra<5>(m, 0, 1), 1);
    EXPECT_EQ(dijkstra<5>(m, 0, 2), 2);
    EXPECT_EQ(dijkstra<5>(m, 0, 3), 3);
    EXPECT_EQ(dijkstra<5>(m, 0, 4), 37);
    EXPECT_EQ(dijkstra<5>(m, 1, 0), 1);
    EXPECT_EQ(dijkstra<5>(m, 1, 2), 3);
    EXPECT_EQ(dijkstra<5>(m, 1, 3), 4);
    EXPECT_EQ(dijkstra<5>(m, 1, 4), 38);
    EXPECT_EQ(dijkstra<5>(m, 3, 0), 3);
    EXPECT_EQ(dijkstra<5>(m, 3, 1), 4);
    EXPECT_EQ(dijkstra<5>(m, 3, 4), 34);
    EXPECT_EQ(dijkstra<5>(m, 4, 0), 37);
    EXPECT_EQ(dijkstra<5>(m, 4, 1), 38);
    EXPECT_EQ(dijkstra<5>(m, 4, 2), 39);
    EXPECT_EQ(dijkstra<5>(m, 4, 3), 34);
}

TEST(GrapghsTest, noneExistingNodeAdjTest) {
    std::array<std::array<uint32_t, 3>, 3> m = {0, 1, 2,
                                                1, 0, 3,
                                                2, 3, 0};
    EXPECT_EQ(dijkstra<3>(m, 0, 5), std::nullopt);
}

TEST(GrapghsTest, unreachableNodeAdjTest) {
    std::array<std::array<uint32_t, 5>, 5> m = {0, 1,  2,  3,  0,
                                                1, 0,  12, 0,  0,
                                                2, 12, 0,  0,  0,
                                                3, 0,  0,  0,  0,
                                                0, 0,  0,  0,  0,};
    EXPECT_EQ(dijkstra<5>(m, 0, 4), std::nullopt);
    EXPECT_EQ(dijkstra<5>(m, 1, 4), std::nullopt);
    EXPECT_EQ(dijkstra<5>(m, 3, 4), std::nullopt);
    EXPECT_EQ(dijkstra<5>(m, 4, 0), std::nullopt);
    EXPECT_EQ(dijkstra<5>(m, 4, 1), std::nullopt);
    EXPECT_EQ(dijkstra<5>(m, 4, 2), std::nullopt);
    EXPECT_EQ(dijkstra<5>(m, 4, 3), std::nullopt);
}
