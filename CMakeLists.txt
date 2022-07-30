cmake_minimum_required(VERSION 3.16) 
project(o2bench)

include_directories(include) 

#set(CMAKE_CXX_FLAGS " -Wall -std=c++17 ") 
set(CMAKE_CXX_FLAGS " -Wall -std=c++17 -O2 ") 

### test 1:  init array on stack, traditional for loop  
add_executable(run_stack_arr.exe arrays/stackarr.cpp src/terminal.cpp src/writecsv.cpp)
add_executable(run_std_arr.exe arrays/stdarr.cpp src/terminal.cpp src/writecsv.cpp) 
add_executable(run_std_vec.exe arrays/stdvec.cpp src/terminal.cpp src/writecsv.cpp)
