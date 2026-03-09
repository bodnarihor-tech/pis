cmake_minimum_required(VERSION 3.30)
project(LibraryManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Це змушує компілятор шукати звичайний main
add_executable(LibraryManagement main.cpp)