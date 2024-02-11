#ifndef ALGORITHMS_PRACTICE_DEPTHFIRSTSEARCH_HPP
#define ALGORITHMS_PRACTICE_DEPTHFIRSTSEARCH_HPP

#include "Node.hpp"
#include <stack>

template <typename T>
Node<T>* dfs_r(Node<T>* node, const T& elem) { // recursive depth first search
    if (nullptr == node) {
        return nullptr;
    }

    if (node->data == elem) {
        return node;
    }

    auto left = dfs_r(node->left, elem);
    if (left != nullptr) {
        return left;
    }

    auto right = dfs_r(node->right, elem);
    if (right != nullptr) {
        return right;
    }
    return nullptr;
}

template <typename T>
Node<T>* dfs(Node<T>* node, const T& elem) { // depth first search
    if (nullptr == node) {
        return nullptr;
    }

    std::stack<Node<T>*> s;
    s.push(node);
    while (!s.empty()) {
        node = s.top();
        s.pop();
        if (node->data == elem) {
            return node;
        }

        if (node->right != nullptr) {
            s.push(node->right);
        }
        if (node->left != nullptr) {
            s.push(node->left);
        }
    }
    return nullptr;
}

#endif //ALGORITHMS_PRACTICE_DEPTHFIRSTSEARCH_HPP
