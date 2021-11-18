cmake_minimum_required(VERSION 3.20)
project(Lightning)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

#add_library(Lightning src/.)
#set_target_properties(Lightning PROPERTIES LINKER_LANGUAGE CXX)
