cmake_minimum_required(VERSION 3.23)
project (cpp_labs)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_labs main.cpp)

add_executable(lab1 lab1/lab1.cpp lab1/funcs.cpp lab1/funcs.h)
add_executable(lab2 lab2/stack.cpp lab2/stack.h lab2/lab2.cpp)