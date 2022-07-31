cmake_minimum_required(VERSION 3.16) 
project(o2bench)

include_directories(include) 

#set(CMAKE_CXX_FLAGS " -Wall -std=c++17 ") 
set(CMAKE_CXX_FLAGS " -Wall -std=c++17 -O2 ") 

### test 1:  init array with traditional for loop using a[i] = i   
add_executable(run_stack_arr.exe arrays/i/stackarr.cpp src/terminal.cpp src/writecsv.cpp)
add_executable(run_std_arr.exe arrays/i/stdarr.cpp src/terminal.cpp src/writecsv.cpp) 
add_executable(run_std_vec.exe arrays/i/stdvec.cpp src/terminal.cpp src/writecsv.cpp)

### test 2:  init array with traditional for loop using a[i] = i * x  
#add_executable(run_stack_arr.exe arrays/i_x/stackarr.cpp src/terminal.cpp src/writecsv.cpp)
#add_executable(run_std_arr.exe arrays/i_x/stdarr.cpp src/terminal.cpp src/writecsv.cpp) 
#add_executable(run_std_vec.exe arrays/i_x/stdvec.cpp src/terminal.cpp src/writecsv.cpp)
