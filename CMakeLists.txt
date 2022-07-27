cmake_minimum_required(VERSION 3.16) 
project(o2bench)

include_directories(include) 

set(CMAKE_CXX_FLAGS " -Wall -std=c++2a") 
#set(CMAKE_CXX_FLAGS " -Wall -std=c++17 -O2 ") 

### test 1:  init array on stack, traditional for loop  
add_executable(runint.exe arrays/stack_int.cpp src/terminal.cpp src/writecsv.cpp)
add_executable(runsizet.exe arrays/stack_sizet.cpp src/terminal.cpp src/writecsv.cpp) 
