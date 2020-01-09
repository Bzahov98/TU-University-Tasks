cmake_minimum_required(VERSION 3.15)
project(FirstExam)

set(CMAKE_CXX_STANDARD 14)

add_library(FirstExam library.cpp library.h CalendarTask/Calendar.cpp Tasks/firstLab.cpp)