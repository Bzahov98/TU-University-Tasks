cmake_minimum_required(VERSION 3.15)
project(ServerSocket)
#add_library(-pthread)
set(CMAKE_C_STANDARD 99)

add_executable(Client Client.c)
add_executable(Server Server.c)