cmake_minimum_required(VERSION 3.19)
project(Threads)

set(CMAKE_CXX_STANDARD 20)

add_executable(Threads main.cpp room.cpp person.cpp person.h room.h hotel.cpp hotel.h)