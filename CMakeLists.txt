cmake_minimum_required(VERSION 3.6)
project(HeterogeneousLinkedList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp List.h)
add_executable(HeterogeneousLinkedList ${SOURCE_FILES})