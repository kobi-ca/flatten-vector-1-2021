cmake_minimum_required(VERSION 3.15)
project(flatten_vector CXX)
set (CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(flatten-vector flatten-vector.cpp)
target_link_libraries(flatten-vector PRIVATE ${CONAN_LIBS})
