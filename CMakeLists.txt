cmake_minimum_required(VERSION 3.23)
project (cpp_labs)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_labs main.cpp)

add_executable(lab1 lab1/lab1.cpp lab1/funcs.cpp lab1/funcs.h)
add_executable(lab2 lab2/stack.cpp lab2/stack.h lab2/lab2.cpp)
add_executable(lab3 lab3/complex.h lab3/complex.cpp lab3/set.h lab3/set.cpp lab3/lab3.cpp)
add_executable(lab4 lab4/superclass.h lab4/eqTriangle.h lab4/eqTriangle.cpp lab4/parallelogram.h lab4/parallelogram.cpp
        lab4/lab4.cpp)
add_executable(lab5 lab5/stack.h lab5/lab5.cpp)
add_executable(lab6 lab6/MyFuncs.h lab6/lab6.cpp)
add_executable(lab7 lab7/CircularBuffer.h lab7/lab7.cpp)