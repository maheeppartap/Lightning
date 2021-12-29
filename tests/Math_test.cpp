
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"
#include "../src/Math.h"
#include <complex>
#include <cmath>
#include <limits>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <complex>
#define ULP_N 4
/*
 * include all test functions for the Math class here in this library
 */

TEST_CASE("MEDIAN TEST"){
    auto* x = new Lightning::Math();
    SUBCASE("median works on std::array<int>"){
    std::array<int, 10> a = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::array<int, 4> b = {1, 4, 5, 6};

    CHECK(x->find_median(&a[0], &a[8], true) == 1.0);
    CHECK(x->find_median(&b[0], &b[4], true) == 4.0);
    }
    free(x);
}

bool AreDoubleSame(auto dFirstVal, auto dSecondVal)
{
    return std::fabs(dFirstVal - dSecondVal) < std::numeric_limits<double>::epsilon();
}
bool nearlyequal(std::complex<double> a, std::complex<double> b) {

    return abs(a - b) < DBL_EPSILON;
}

// todo
//TEST_CASE("DISCRETE FOURIER TRANSFORM"){
//    auto* x = new Lightning::Math();
//    SUBCASE("DFT on custom struct array"){
//        typedef std::complex<double> cx;
//
////        cx a[] = { cx(0,0), cx(1,1), cx(3,3), cx(4,4),
////                   cx(4, 4), cx(3, 3), cx(1,1), cx(0,0) };
////        cx b[8];
////        x->fft(a, b, 3);
////        cx rslt[8] = {cx(16, 16), cx(-4.82843,-11.6569), cx(0,0), cx(-0.343146,0.828427), cx(0,0)
////                      , cx(0.828427,-0.343146), cx(0,0), cx(-11.6569,-4.82843) };
//
//
////        CHECK(abs(b[0] - rslt[0]) < DBL_EPSILON);
////        CHECK(nearlyequal(b[1], rslt[1]) == true);
//
//    }
//}