# o2bench
Raw one-dimensional C-Array storage vs C++ STL containers (std::array and std::vector), before and after compiler
optimizations (-O2).
Additionally, cache alignment is implemented [in this file](https://github.com/tommygorham/o2bench/blob/main/arrays/i/stdarr_aligned.cpp), for 64 bit cache lines. 
This ensures the starting address is at the beginning of a cache line, and is done via `alignas(64)` 

# The Goal of this Benchmark 
To compare the compiler's ability to optimize memory access based on the data structure. 

# Compile

```
mkdir build
cd build 
cmake .. 
make 
```

# Run 

```
../run_tests.sh
```

## More Info 

The subfolder [arrays/i_x](https://github.com/tommygorham/o2bench/tree/main/arrays/i_x) is deprecated

In the past, it was used to measure how O2 behaves with a[i] = i*x read/write. 
In this folder, x is set to the appropriate value, depending on the type passed to value_t. 
E.g., 

```CPP 
using value_t = float; 
x = 3.0f;

using value_t = int; 
x = 3; 
```
