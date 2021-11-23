
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest/doctest.h"
#include "../src/Math.h"
/*
 * include all test functions for the Math class here in this library
 */
template<typename T>
class test_list{
private:
    T data;
public:
    test_list* next;

    auto operator ++ (){
        return next;
    }

    T getData() const {
        return data;
    }

    void setData(T x) {
        test_list::data = x;
    }

    test_list() = default;

};

TEST_CASE("TEST_MATH_COMPILE"){
    auto* x = new Lightning::Math();
    std::array<int, 10> a = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::array<int, 4> b = {1, 4, 5, 6};


    CHECK(x->find_median(&a[0], &a[8], true) == 1);
    CHECK(x->find_median(&b[0], &b[4], true) == 4);
//    CHECK(x->find_median(std::addressof(b[0]), std::addressof(b[9]), true) == 1);
    free(x);
}