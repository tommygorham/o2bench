#!/bin/bash
# Run all executables and generate CSV files

echo "Running debug executables..."
./build/stack_arr_i_debug.exe results.csv
./build/stdarr_i_debug.exe results.csv
./build/std_vec_i_debug.exe results.csv
./build/stdarr_aligned_i_debug.exe results.csv

echo "Running optimized executables..."
./build/stack_arr_i_opt.exe results.csv
./build/stdarr_i_opt.exe results.csv
./build/std_vec_i_opt.exe results.csv
./build/stdarr_aligned_i_opt.exe results.csv

echo "All tests completed."
