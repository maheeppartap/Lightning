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
private:
    const double PI = 3.1415926536;
public:
/*
 * finds and returns the median of some iterable object. begin and end are both iterators
 */

    template<typename S>
    decltype(auto) find_median_sorted(S begin, S end){
        auto len = this->find_len(begin, end);
        return (len % 2) == 0 ? (*(begin + ((len)/2) - 1) + *(begin + (len)/2)) / 2: *(begin + (len / 2) - 1);
    }

    template<typename S>
    uint32_t find_len(S s, S s1) {
        auto len = 0;
        while(s != s1){
            len++;
            s++;
        }
        return len;
    }

    template<typename S, typename F = std::less<void>>
    double find_median_unsorted(S begin,
                                        S end,
                                        F comparison = {}){
        std::sort(begin, end, comparison);
        auto len = this->find_len(begin, end);
        return (len % 2) == 0 ? (*(begin + ((len)/2) - 1) + *(begin + (len)/2))/2: *(begin + (len / 2) - 1);
    }

    template<typename T, typename F = std::less<void>>
    decltype(auto) find_median(T begin,
                               T end,
                               bool sorted = false,
                               F comparison = {}){
        assert(begin != nullptr);
        assert(end != nullptr);
        return sorted ? find_median_sorted(begin, end) : find_median_unsorted(begin, end, comparison);
    }

    unsigned int bitReverse(unsigned int x, int log2n) {
        int n = 0;
        int mask = 0x1;
        for (int i=0; i < log2n; i++) {
            n <<= 1;
            n |= (x & 1);
            x >>= 1;
        }
        return n;
    }

    template<class Iter_T>
    void fft(Iter_T a, Iter_T b, int log2n)
    {
        typedef typename __gnu_cxx::iterator_traits<Iter_T>::value_type complex;
        const complex J(0, 1);
        int n = 1 << log2n;
        for (unsigned int i=0; i < n; ++i) {
            b[bitReverse(i, log2n)] = a[i];
        }
        for (int s = 1; s <= log2n; ++s) {
            int m = 1 << s;
            int m2 = m >> 1;
            complex w(1, 0);
            complex wm = exp(-J * (PI / m2));
            for (int j=0; j < m2; ++j) {
                for (int k=j; k < n; k += m) {
                    complex t = w * b[k + m2];
                    complex u = b[k];
                    b[k] = u + t;
                    b[k + m2] = u - t;
                }
                w *= wm;
            }
        }
    }

};

#endif //LIGHTNING_MATH_H
