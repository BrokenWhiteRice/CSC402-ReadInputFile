cmake_minimum_required(VERSION 3.26)
project(csc402_pa2)

set(CMAKE_CXX_STANDARD 17)

add_executable(csc402_pa2 main.cpp
        Employee.cpp
        Employee.h
        MyQueue.cpp
        MyQueue.h
        MyStack.cpp
        MyStack.h)
