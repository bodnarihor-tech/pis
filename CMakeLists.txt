cmake_minimum_required(VERSION 3.20)
project(LibraryManagement)

set(CMAKE_CXX_STANDARD 20)

add_executable(LibraryManagement
        main.cpp
        BaseEntity.cpp
        LibraryItem.cpp
        Book.cpp
        LibraryManager.cpp
        LibraryManager.cpp
        LibraryManager.h
)