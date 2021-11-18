
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
    std::array<int, 10> a = {5, 2, 3, 4, 5 ,6 ,7 ,8, 9, 7};
//    std::vector<int> b = {5, 2, 3, 4, 5 ,6 ,7 ,8, 9, 7};

    auto start = new test_list<char>;
    auto second = new test_list<char>;
    auto third = new test_list<char>;

//    start->setData('a');
//    start->next = second;
//    second->setData('b');
//    second->next = third;
//    third->setData('c');
//    third->next = nullptr;


    CHECK(x->find_median(&a[0], &a[9], false) == 1);
//    CHECK(x->find_median(std::addressof(b[0]), std::addressof(b[9]), true) == 1);
    free(x);
}