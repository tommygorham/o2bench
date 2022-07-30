# o2bench
Benchmarking C++ raw storage vs STL containers before and after compiler optimizations with -O2. 
In the future I plan to hardcode some intrinsics. 

## Directions 
```
vim CMakeLists.txt 
```
[Set Optimization level](https://github.com/tommygorham/o2bench/blob/main/CMakeLists.txt#:~:text=%23set(CMAKE_CXX_FLAGS,17%20%2DO2%20%22))



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

