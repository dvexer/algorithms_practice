#include <gtest/gtest.h>
#include "algorithms/DepthFirstSearch.hpp."

TEST(DepthFirstSearchTest, emptyInputTest) {
    Node<int>* n = nullptr;
    Node<int>* result = dfs_r(n, 1);
    EXPECT_EQ(result, nullptr);
    EXPECT_EQ(result, dfs(n, 1));
}

TEST(DepthFirstSearchTest, firstNodeTest) {
    Node<int> n(1);
    Node<int> l(2);
    Node<int> r(3);
    n.left = &l;
    n.right = &r;
    Node<int>* result = dfs_r(&n, 1);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(&n, result);
    EXPECT_EQ(result, dfs(&n, 1));
}

TEST(DepthFirstSearchTest, leftNodeTest) {
    Node<int> n(1);
    Node<int> l(2);
    Node<int> r(3);
    n.left = &l;
    n.right = &r;
    Node<int>* result = dfs_r(&n, 2);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(&l, result);
    EXPECT_EQ(result, dfs(&n, 2));
}

TEST(DepthFirstSearchTest, rightNodeTest) {
    Node<int> n(1);
    Node<int> l(2);
    Node<int> r(3);
    n.left = &l;
    n.right = &r;
    Node<int>* result = dfs_r(&n, 3);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(&r, result);
    EXPECT_EQ(result, dfs(&n, 3));
}

TEST(DepthFirstSearchTest, noNodeTest) {
    Node<int> n(1);
    Node<int> l(2);
    Node<int> r(3);
    n.left = &l;
    n.right = &r;
    Node<int>* result = dfs_r(&n, 5);
    EXPECT_EQ(result, nullptr);
    EXPECT_EQ(result, dfs(&n, 5));
}
