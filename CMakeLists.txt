cmake_minimum_required(VERSION 3.16) # should work with other versions too 
project(o2bench)

include_directories(include) # header files  

# compile with no optimization flags 
#set(CMAKE_CXX_FLAGS " -Wall -std=c++17 ")

# compile with gcc level2 optimization  
set(CMAKE_CXX_FLAGS " -Wall -std=c++17 -O2 ") # can also append -march=native 

### 1D Container test 1:  init array with traditional for loop using a[i] = i   
add_executable(run_stack_arr.exe arrays/i/stackarr.cpp src/terminal.cpp src/writecsv.cpp)
add_executable(run_std_arr.exe arrays/i/stdarr.cpp src/terminal.cpp src/writecsv.cpp) 
add_executable(run_std_vec.exe arrays/i/stdvec.cpp src/terminal.cpp src/writecsv.cpp)

### 1D container test 2:  init array with traditional for loop using a[i] = i * x  
#add_executable(run_stack_arr.exe arrays/i_x/stackarr.cpp src/terminal.cpp src/writecsv.cpp)
#add_executable(run_std_arr.exe arrays/i_x/stdarr.cpp src/terminal.cpp src/writecsv.cpp) 
#add_executable(run_std_vec.exe arrays/i_x/stdvec.cpp src/terminal.cpp src/writecsv.cpp)
