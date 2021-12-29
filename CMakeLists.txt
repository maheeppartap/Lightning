cmake_minimum_required(VERSION 3.20)
project(Lightning)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

add_executable(test_ tests/Math_test.cpp)
target_compile_features(test_ PRIVATE cxx_std_17)
target_link_libraries(test_ PRIVATE doctest::doctest)
#add_library(Lightning src/.)
#set_target_properties(Lightning PROPERTIES LINKER_LANGUAGE CXX)
