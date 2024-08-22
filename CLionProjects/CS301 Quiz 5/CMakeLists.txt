cmake_minimum_required(VERSION 3.24)
project(CS301_Quiz_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS301_Quiz_5
        ItemType.cpp
        ItemType.h
        main.cpp
        SortedList.cpp
        SortedList.h)
