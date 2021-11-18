//
// Created by mahee on 2021-10-25.
//

#ifndef LIGHTNING_MATH_H
#define LIGHTNING_MATH_H
#include "Lightning.h"
#include <iterator>
#include <cassert>

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

    template<typename S>
    decltype(auto) find_median_sorted(S begin, S end){
        while(begin != end){
            std::cout << *begin;
            begin++;
        }
        std::cout << *begin << std::endl;
        return 1;
    }

    template<typename S>
    int find_len(S s, S s1) {
        auto len = 0;
        while(s != s1){
            len++;
            s++;
        }
        return len;
    }

    template<typename S, typename F = std::less<void>>
    decltype(auto) find_median_unsorted(S begin,
                                        S end,
                                        F comparison = {}){
        std::cout << "Starting test\n";
        std::sort(begin, end, comparison);

        auto len = this->find_len(begin, end);
        auto temp = begin;
        while(temp != end){
            temp++;
            std::cout << *begin++;
        }

        return (len % 2) == 0 ? ((*begin + ((len - 1) / 2)) + ( *begin + (len/2)))/2 : *begin + (len / 2);
    }

    template<typename T, typename F = std::less<void>>
    decltype(auto) find_median(T begin,
                               T end,
                               bool sorted = false,
                               F comparison = {}){
        assert(begin != nullptr);
        assert(end != nullptr);
//        return comparison(begin, end);
        return sorted ? find_median_sorted(begin, end) : find_median_unsorted(begin, end, comparison);
    }
};

#endif //LIGHTNING_MATH_H
