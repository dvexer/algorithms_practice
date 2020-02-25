#ifndef ALGORITHMS_PRACTICE_BUBBLESORT_HPP
#define ALGORITHMS_PRACTICE_BUBBLESORT_HPP

#include <algorithm>
#include <cassert>

namespace algos {

template <class TIter>
void bubble_sort(TIter b, TIter e) {
    for (TIter i = e; i != b; --i) {
        // [unsorted) [sorted)
        // [b, i)     [i, e)
        for (TIter j = b+1; j < i; ++j) {   // [b, i)
            // [b, j-1)[j-1][j] [j+1  i)
            auto prev = j-1;
            if(*j < *prev) {
                iter_swap(j, prev);
            }
        }
    }
}

}   // algos

#endif //ALGORITHMS_PRACTICE_BUBBLESORT_HPP
