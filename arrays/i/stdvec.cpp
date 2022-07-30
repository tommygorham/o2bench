// program description: Time the memory access of a 1KB or 1MB heap-allocated std::vector (1D array) with i to index 
#include <iostream>       
using std::cout; 
using std::endl;
#include <vector>        // data structure used  
using std::vector; 
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

#define DEFAULT_INPUT "./cppstdvectr" // can use argv[0] for this too 
#define ACCESSMETHOD "using reserve(size) emplace_back i"  

int main(int argc, char* argv[])
{
        // set type for container here   
	using value_t = int; // looking to compare int, float, double, etc... for various container implementations     
	using index_t = std::size_t;  
	// problem size 
	constexpr index_t size = 250;  // NOTE: do not exceed val from ulimit -a | grep stack   		
	std::string filename = DEFAULT_INPUT;  
	std::string_view vt = typeid(value_t).name(); // store the datatype used to make array for results  
	std::string_view it = typeid(index_t).name(); // store the index type used to index the array while < size
	
	// declare vector
        vector<value_t> v1;  
        v1.reserve(size); // telling it to go ahead and give me this much memory 
	// initialize and time 
	auto s1 = std::chrono::high_resolution_clock::now(); 
        for(index_t i = 0; i < size; ++i) 
        { 
            v1.emplace_back(i); // faster and less copies than push_back 
        } 
        auto s2 = std::chrono::high_resolution_clock::now(); 
	std::chrono::duration<double, std::milli> init = s2-s1; 
       	cout << "\nMemory Access time a[i]:  " << std::fixed << setprecision(7) << init.count() << endl; 
              
        // correctness check   
	value_t last_element = v1[size-1]; // last element in the array 
	value_t last_index = size-1;      // the last element's index  
	if(last_element == last_index)  // since initialized with 3 
	{ 
	     cout << "\na[i] access performed correctly." << endl; 
	}
	else 
	{ 
	     cout << "\nError in Initialization with a[i]" << endl; 
	     return 1; 
	} 

        // prepare profiling results  
	std::size_t bytes =  sizeof(v1) + (sizeof(value_t) * v1.size());  
        std::size_t elements = v1.size(); 
	cout << "\nbytes: " << bytes << " calculated via sizeof(v1) + (sizeof(value_t) * v1.size())"  << endl; 
	cout << "\nsizeof(v1) " << sizeof(v1) << endl; //size of vector structure itself  
	cout << "\ncapacity: " << v1.capacity() << endl;
	std::string_view declaration = type_name<decltype(v1)>(); 
	std::string_view am = ACCESSMETHOD; 
        
	// write profiling results 
        writeToTerminal(declaration, vt, it, bytes, elements, init, am);    
        if (argc == 2)  {
        std::string file_path(argv[1]);
        writeToCSV(file_path, filename, vt, it, size, bytes,  init, am); 
        } 
		
        // show array elements if needed     
        if (size <= 25) 
        { 
            printData(v1); 
        }
        return 0; 
}
