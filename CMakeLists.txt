cmake_minimum_required(VERSION 3.9)
project(CNOT)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -O1")

add_executable(CNOT main.cpp Ptr.cpp Ptr.h Memory.cpp Memory.h Operations.cpp Operations.h)