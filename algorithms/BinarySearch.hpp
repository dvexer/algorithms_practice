#ifndef ALGORITHMS_PRACTICE_BINARYSEARCH_HPP
#define ALGORITHMS_PRACTICE_BINARYSEARCH_HPP

#include <algorithm>

namespace algos {

template <class TIter, class T>
TIter binary_search(TIter b, TIter e, const T& key) {
    assert(std::is_sorted(b, e));
    const TIter notFound = e;
    while (b < e) {
        const TIter m = b + (e - b)/2;
        // [b, m) U [m] U (m, e)
        if (key < *m) {
            e = m;  // [b, m)
        } else if (key > *m) {
            b = m + 1; // (m, e)
        } else {
            return m;
        }
    }
    return notFound;
}

template <class TIter, class T>
    TIter lower_bound(TIter b, TIter e, const T& key) {
    assert(std::is_sorted(b, e));
    while(b < e) {
        // [b, m) U [m] U (m, e)
        const TIter m = b + (e-b)/2;
        if(key > *m) {
            b = m + 1; // (m, e)
        } else {
            e = m; // [b, m)
        }
    }
    return b;
}

template <class TIter, class T>
TIter upper_bound(TIter b, TIter e, const T& key) {
    assert(std::is_sorted(b, e));
    while(b < e) {
        // [b, m) U [m] U (m, e)
        const TIter m = b + (e-b)/2;
        if(key < *m) {
            e = m;
        } else {
            b = m + 1; // (m, e)
        }
    }
    return b;
}

}   // algos

#endif //ALGORITHMS_PRACTICE_BINARYSEARCH_HPP
