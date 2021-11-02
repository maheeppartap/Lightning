
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"
#include "../src/Math.h"
/*
 * include all test functions for the Math class here in this library
 */
TEST_CASE("TEST_MATH_COMPILE"){
    auto* x = new Lightning::Math();
    std::array<int, 10> a = {5, 2, 3, 4, 5 ,6 ,7 ,8, 9, 7};
    CHECK(x->find_median(a[0], a[9], 10) == 1);
    free(x);
}