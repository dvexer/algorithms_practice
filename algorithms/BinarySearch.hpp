#ifndef ALGORITHMS_PRACTICE_BINARYSEARCH_HPP
#define ALGORITHMS_PRACTICE_BINARYSEARCH_HPP

#include <algorithm>

namespace algos {

template <class TIter, class T>
TIter binary_search(TIter b, TIter e, const T& key) {
    assert(std::is_sorted(b, e));
    TIter notFound = e;

    while (b < e) {
        TIter m = b + (e - b)/2;
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

}   // algos

#endif //ALGORITHMS_PRACTICE_BINARYSEARCH_HPP
