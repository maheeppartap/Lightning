//
// Created by mahee on 2021-10-25.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"
#include "../src/Lightning.h"
#include "../src/Math.h"

TEST_CASE("TEST_MATH_COMPILE"){
    auto* x = new Lightning::Math();
    int a[] = {2, 3};
    CHECK(x->find_median(a[0], a[1]) == 1);
    free(x);
}