cmake_minimum_required(VERSION 3.15)
project(TaxiRouteSystem_CourseWork_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(TaxiRouteSystem_CourseWork_
        car_database.txt
        point_database.txt
        README.md
        route_database.txt
        test.cpp)
