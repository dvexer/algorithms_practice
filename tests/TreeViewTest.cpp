#include <gtest/gtest.h>
#include <vector>
#include "algorithms/TreeView.hpp"


TEST(TreeViewTest, singleNodeTest) {
    Node<int> node(1);
    std::vector<int> v{1};
    EXPECT_EQ(algos::left_view(&node), v);
    EXPECT_EQ(algos::right_view(&node), v);
    EXPECT_EQ(algos::left_right_view(&node), v);
}

TEST(TreeViewTest, threeNodeTest) {
    Node<int> node(1);
    Node<int> lnode(2);
    Node<int> rnode(3);
    node.left = &lnode;
    node.right = &rnode;

    std::vector<int> lv{1, 2};
    EXPECT_EQ(algos::left_view(&node),lv);
    std::vector<int> rv{1, 3};
    EXPECT_EQ(algos::right_view(&node),rv);
    std::vector<int> lrv{2, 1, 3};
    EXPECT_EQ(algos::left_right_view(&node),lrv);
}

TEST(TreeViewTest, fourNodeTest) {
    Node<int> node(1);
    Node<int> lnode(2);
    Node<int> rnode(3);
    Node<int> llnode(4);
    node.left = &lnode;
    lnode.left = &llnode;
    node.right = &rnode;

    std::vector<int> lv{1, 2, 4};
    EXPECT_EQ(algos::left_view(&node),lv);
    std::vector<int> rv{1, 3, 4};
    EXPECT_EQ(algos::right_view(&node),rv);
    std::vector<int> lrv{4, 2, 1, 3};
    EXPECT_EQ(algos::left_right_view(&node),lrv);

}

TEST(TreeViewTest, sixNodeTest) {
    Node<int> node(1);
    Node<int> lnode(2);
    Node<int> rnode(3);
    Node<int> llnode(4);
    Node<int> rrnode(5);
    Node<int> rrrnode(6);
    node.left = &lnode;
    lnode.left = &llnode;
    node.right = &rnode;
    rnode.right = &rrnode;
    rrnode.right = &rrrnode;

    std::vector<int> lv{1, 2, 4, 6};
    EXPECT_EQ(algos::left_view(&node), lv);
    std::vector<int> rv{1, 3, 5, 6};
    EXPECT_EQ(algos::right_view(&node), rv);
    std::vector<int> lrv{4, 2, 1, 3, 5, 6};
    EXPECT_EQ(algos::left_right_view(&node), lrv);

}

TEST(TreeViewTest, sevenNodeTest) {
    Node<int> node(1);
    Node<int> lnode(2);
    Node<int> rnode(3);
    Node<int> llnode(4);
    Node<int> rrnode(5);
    Node<int> rrrnode(6);
    Node<int> rrlnode(7);   // shouldn't be in views

    node.left = &lnode;
    lnode.left = &llnode;
    node.right = &rnode;
    rnode.right = &rrnode;
    rrnode.right = &rrrnode;
    rrnode.left = &rrlnode;

    std::vector<int> lv{4, 2, 1, 3, 5, 6};
    EXPECT_EQ(algos::left_right_view(&node), lv);
    std::vector<int> rv{4, 2, 1, 3, 5, 6};
    EXPECT_EQ(algos::left_right_view(&node), rv);
    std::vector<int> lrv{4, 2, 1, 3, 5, 6};
    EXPECT_EQ(algos::left_right_view(&node), lrv);
}
