//
// Created by mahee on 2021-10-25.
//

#ifndef LIGHTNING_MATH_H
#define LIGHTNING_MATH_H
#include "Lightning.h"

/*
 * Todo: Algorithms to be implemented:
 *          Median algorithm (could also be in statistics, but will implement here and use in stats later)
 *          Fourier series
 *          Matrix multiplication
 *          Matrix addition
 *          Adaptive integration
 */
class Lightning::Math
{
public:
/*
 * finds and returns the median of some iterable object. begin and end are both iterators
 */

    template<typename T>
    decltype(auto) find_median_sorted(T begin, int len){
        auto begin_ = std::addressof(begin);

        return 1;
    }

template<typename T>
decltype(auto) find_median(T begin, bool sorted){

    if( !sorted ){
        return find_median_sorted(begin  );
    }

    // slower because sorting is needed
    return find_median_sorted(begin);

//    for (auto i : temp_) std::cout << i << " ";
}
};

#endif //LIGHTNING_MATH_H
