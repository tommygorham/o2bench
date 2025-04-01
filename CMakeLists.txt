cmake_minimum_required(VERSION 3.16) 
project(o2bench)

# -I include location of header files
include_directories(include) 

# Apply standard settings, require C++17 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define common source files
set(COMMON_SOURCES src/terminal.cpp src/writecsv.cpp)

# Function to add executables with specific optimization level
function(add_optimized_executables OPT_FLAG SUFFIX)
    # Create a scope for these flags
    add_compile_options(${OPT_FLAG})
    
    # Add executables with appropriate suffixes
    add_executable(stack_arr_i_${SUFFIX}.exe arrays/i/stackarr.cpp ${COMMON_SOURCES})
    add_executable(stdarr_i_${SUFFIX}.exe arrays/i/stdarr.cpp ${COMMON_SOURCES})
    add_executable(std_vec_i_${SUFFIX}.exe arrays/i/stdvec.cpp ${COMMON_SOURCES})
    add_executable(stdarr_aligned_i_${SUFFIX}.exe arrays/i/stdarr_aligned.cpp ${COMMON_SOURCES})
    
    # Reset compile options for the next set
    remove_definitions(${OPT_FLAG})
endfunction()

# First compile debug (-O0) versions
add_optimized_executables("-O0" "debug")

# Then compile optimized (-O2) versions
add_optimized_executables("-O2" "opt")

# Add Wall for all targets (common to both sets)
add_compile_options(-Wall)
