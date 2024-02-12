#ifndef ALGORITHMS_PRACTICE_TREEVIEW_HPP
#define ALGORITHMS_PRACTICE_TREEVIEW_HPP

#include <vector>
#include <stack>
#include "data_structures/Node.hpp"


namespace details {

template <typename T>
std::vector<T> left_view_internal(Node<T>* node, int lvl, int& max_lvl) {
    std::vector<T> result;
    if (node == nullptr) {
        return result;
    }

    if (lvl > max_lvl)
    {
        max_lvl = lvl;
        result.push_back(node->data);
    }

    auto l_res = left_view_internal(node->left, lvl + 1, max_lvl);
    auto r_res = left_view_internal(node->right, lvl + 1, max_lvl);
    result.insert(result.end(), std::make_move_iterator(l_res.begin()), std::make_move_iterator(l_res.end()));
    result.insert(result.end(), std::make_move_iterator(r_res.begin()), std::make_move_iterator(r_res.end()));
    return result;
}

template <typename T>
std::vector<T> right_view_internal(Node<T>* node, int lvl, int& max_lvl) {
    std::vector<T> result;
    if (node == nullptr) {
        return result;
    }
    if (lvl > max_lvl)
    {
        max_lvl = lvl;
        result.push_back(node->data);
    }

    auto r_res = right_view_internal(node->right, lvl + 1, max_lvl);
    auto l_res = right_view_internal(node->left, lvl + 1, max_lvl);
    result.insert(result.end(), std::make_move_iterator(r_res.begin()), std::make_move_iterator(r_res.end()));
    result.insert(result.end(), std::make_move_iterator(l_res.begin()), std::make_move_iterator(l_res.end()));
    return result;
}

template <typename T>
std::vector<T> left_right_view_internal(Node<T>* node, int lvl, int& max_lvl) {
    std::vector<T> result;
    if (node == nullptr) {
        return result;
    }

    if (lvl > max_lvl)
    {
        max_lvl = lvl;
        result.push_back(node->data);
    }

    auto l_res = left_view_internal(node->left, lvl + 1, max_lvl);
    max_lvl = lvl;
    auto r_res = right_view_internal(node->right, lvl + 1, max_lvl);
    result.insert(result.end(), std::make_move_iterator(l_res.begin()), std::make_move_iterator(l_res.end()));
    std::reverse(result.begin(), result.end());
    result.insert(result.end(), std::make_move_iterator(r_res.begin()), std::make_move_iterator(r_res.end()));
    return result;
}

}   // details

namespace algos {

template <typename T>
std::vector<T> left_view(Node<T>* node) {
    int max_lvl = 0;
    return details::left_view_internal(node, 1, max_lvl);
}

template <typename T>
std::vector<T> right_view(Node<T>* node) {
    int max_lvl = 0;
    return details::right_view_internal(node, 1, max_lvl);
}

template <typename T>
std::vector<T> left_right_view(Node<T>* node) {
    int max_lvl = 0;
    return details::left_right_view_internal(node, 1, max_lvl);
}

}   // algos

#endif //ALGORITHMS_PRACTICE_TREEVIEW_HPP
