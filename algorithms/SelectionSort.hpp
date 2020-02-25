#ifndef ALGORITHMS_PRACTICE_SELECTIONSORT_HPP
#define ALGORITHMS_PRACTICE_SELECTIONSORT_HPP

#include "algorithm"

namespace algos {

template <class TIter>
void selection_sort(TIter b, TIter e) {
    // [b, i) [i e)
    // [sorted) [unsorted)
    for (TIter i = b; i < e; ++i) {
        iter_swap(i, std::min_element(i, e));
    }
}

}   // algos

#endif //ALGORITHMS_PRACTICE_SELECTIONSORT_HPP
