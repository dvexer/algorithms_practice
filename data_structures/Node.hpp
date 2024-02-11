#ifndef ALGORITHMS_PRACTICE_NODE_HPP
#define ALGORITHMS_PRACTICE_NODE_HPP

template <typename T>
struct Node {
    Node(const T data_)
    : left(nullptr)
    , right(nullptr)
    , parent(nullptr)
    , data(data_) {
    }

    Node* left;
    Node* right;
    Node* parent;
    T data;
};

#endif //ALGORITHMS_PRACTICE_NODE_HPP
