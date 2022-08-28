# o2bench
Raw one-dimensional C-Array storage vs 1D STL containers in C++ (std::array and std::vector), before and after compiler optimizations with g++ -O2.
Additionally, cache alignment is implemented [in this file](https://github.com/tommygorham/o2bench/blob/main/arrays/i/stdarr_aligned.cpp), for 64 bit cache lines. 
This ensures the starting address is at the beginning of a cache line, and is done via `alignas(64)` 

# The Goal of this Benchmark 
By examining the compiler's ability to optimize memory access, we will determine if a one-dimensional std::array or a raw C-Array is better for computational performance when defining a data structure. std::vector was added to see the performance difference of heap allocations before and after compiler optimizations are added. 

# Hypothesis 
The compiler should be able to optimize std::array as well or better than raw C-arrays. If this is the case, then std::array may be the best choice for defining something like a matrix class when the size is constexpr (or known at compile time). This is because 1D matrix storage is faster than 2D in most cases, and std::array is safer than using a raw array, due to things like bounds checking.  

# 1MB Array Access Results in milliseconds

More results can be viewed [here](https://github.com/tommygorham/o2bench/tree/main/arrays/results_csv)

<img src = "https://github.com/tommygorham/o2bench/blob/main/arrays/results_csv/results_quickview.png" />

# Directions 

### Configure

```
vim CMakeLists.txt 
```
[Set Optimization level in the CMakeLists.txt file and select the test to perform here as well. 

### Run 

```
mkdir build && cd build 
cmake .. -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc 
make 
./<exe>      or    ./<exe> <results.csv> 
```

## Files and Structure

1. [arrays](https://github.com/tommygorham/o2bench/tree/main/arrays): Contains the one-dimensional code where memory access is measured via initalization methods and different containers, such as: 

* A stack based array (C style) 
* std::array
* std::vector

The subfolder [arrays/i](https://github.com/tommygorham/o2bench/tree/main/arrays/i) measures how O2 behaves with simple a[i] read/write. 

The subfolder [arrays/i_x](https://github.com/tommygorham/o2bench/tree/main/arrays/i_x) measures how O2 behaves with a[i] = i*x read/write. 
In this folder, x is set to the appropriate value, depending on the type passed to value_t. 
E.g., 

```CPP 
using value_t = float; 
x = 3.0f;

using value_t = int; 
x = 3; 
```

2. [include](https://github.com/tommygorham/o2bench/tree/main/include): These are the header files used by the main programs in [arrays](https://github.com/tommygorham/o2bench/tree/main/arrays)

3. [results_csv](https://github.com/tommygorham/o2bench/tree/main/results_csv): Performane results on different machines before and after -O2 Optimization with different access methods (a[i] vs a[i] = i*x) 

The subfolder [results_csv/4core8thread](https://github.com/tommygorham/o2bench/tree/main/results_csv/4core8thread) is my measely laptop, whereas the subfolder [results_csv/fireflynode2](https://github.com/tommygorham/o2bench/tree/main/results_csv/fireflynode2) is a node of an 80 logical core cluster. 

4. [src](https://github.com/tommygorham/o2bench/tree/main/src):  The implementation of the header files that are not templated. 

5. [typedebuging](https://github.com/tommygorham/o2bench/tree/main/typedebugging): The programs in this folder exist as I was using them to double check myself  about sematics regarding types/bytes. None of these programs are used in the performance analysis, though they could be a good place to start by compiling with 
         ``` 
         g++ -Wall -std=c++17 
         ```

