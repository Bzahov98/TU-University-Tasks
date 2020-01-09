cmake_minimum_required(VERSION 3.15)
project(TaxiRouteSystem)

set(CMAKE_CXX_STANDARD 14)


add_executable(TaxiRouteSystem main.cpp model/serializable/Serializable.cpp model/serializable/Serializable.h model/car/Car.cpp model/car/Car.h model/Route/Route.cpp model/Route/Route.h model/Taxi/Taxi.cpp model/Taxi/Taxi.h model/Point/Point.cpp model/Point/Point.h exceptions/InvalidInputException.cpp exceptions/InvalidInputException.h includes.h)