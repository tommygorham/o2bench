// program description: Time the initialization of a 1KB or 1MB stack-allocated integer array using the STL and i to index 
#include <iostream>      
using std::cout; 
using std::endl;
#include <array>         // data structure to be used 
using std::array; 
#include <iomanip>       // formatting runtimes, std::fixed, setprecision, etc 
using std::setprecision; 
#include <typeinfo>      // validating inputs with typeid 
#include <type_traits>   // c++11 static assert 
#include <chrono>        // timing a block of code's execution   
#include <cassert>       // checking correctness with assert() 
#include <string>        // for printing filename, other command-line args  
#include <string_view>   // c++17 read only string, better for performance
#include <fstream>       // necessary for write to csv 
#include "terminal.h"    // writeToTerminal( <params> )  
#include "printdata.h"   // show one-dimensional container's data of any type with printdata( <container> )
#include "type.h"        // templated typename function definition 
#include "writecsv.h"    // writeToCSV( <params> )  

#define DEFAULT_INPUT "./cppstdarray" // can use argv[0] for this too 
#define ACCESSMETHOD "a[i] = i" 

int main(int argc, char* argv[])
{
        // set type for container here   
	using value_t = int; // looking to compare int, float, double, etc... for various container implementations     
	using index_t = std::size_t;  
	// problem size 
	constexpr index_t size = 250000;  // NOTE: do not exceed val from ulimit -a | grep stack   		
	std::string filename = DEFAULT_INPUT;  
	std::string_view vt = typeid(value_t).name(); // store the datatype used to make array for results  
	std::string_view it = typeid(index_t).name(); // store the index type used to index the array while < size
		
        // declare an array on the stack  
	array<value_t, size> a1;  

	// initialize and time 
	auto s1 = std::chrono::high_resolution_clock::now(); 
        for(index_t i = 0; i < size; ++i) 
        { 
            a1[i] =  i;
        } 
        auto s2 = std::chrono::high_resolution_clock::now(); 
	std::chrono::duration<double, std::milli> init = s2-s1; 
       	cout << "\nMemory Access time a[i]:  " << std::fixed << setprecision(7) << init.count() << endl; 
              
        // correctness check   
	value_t last_element = a1[size-1]; // last element in the array 
	value_t last_index = size-1;      // the last element's index  
	if(last_element == last_index)  // since initialized with 3 
	{ 
	     cout << "\na1[i] access  performed correctly." << endl; 
	}
	else 
	{ 
	     cout << "\nError in Initialization with a1[i]" << endl; 
	     return 1; 
	} 

        // prepare profiling results   
	std::size_t bytes =  sizeof(a1); 
        std::size_t elements = bytes / sizeof(value_t); 
        assert(elements == size); 
        assert(bytes == size*sizeof(value_t)); 
	std::string_view declaration = type_name<decltype(a1)>(); 
	std::string_view am = ACCESSMETHOD; 
        // write profiling results 
        writeToTerminal(declaration, vt, it, bytes, elements, init, am);   
        if (argc == 2)  {
        std::string file_path(argv[1]);
        writeToCSV(file_path, filename, vt, it, size, bytes, init, am); 
        }   
		
        // show array elements if needed     
        if (size <= 25) 
        { 
            printData(a1); 
        }
        return 0; 
}
