// program description: Time the initialization of a raw, 1MB stack-allocated integer array using a computation i*3  
#include <iostream>      // well, I/O of course  
using std::cout; 
using std::endl;
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

#define DEFAULT_INPUT "./stack_int_array" // can use argv[0] for this too 

int main(int argc, char* argv[])
{
        // set type for container here   
		using value_t = int; // looking to compare int, float, double, etc... for various container implementations     
		using index_t = int;  
		// problem size 
		constexpr index_t size = 25;  // NOTE: do not exceed val from ulimit -a | grep stack   		
		std::string filename = DEFAULT_INPUT;  
		std::string_view dt = typeid(value_t).name(); // store datatype that was used for results  
	    value_t x{}; // value to fill arr 
		// validating uniform types were configured  
		auto t =  typeid(value_t).name(); 
		if ( t == typeid(int).name() ) 
		{ 
		    static_assert(std::is_same<decltype(x), int>::value, "x must be int"); 
			x = 3; 
			cout << "Integer Array is being initialized on the stack, indexing with 4-byte int... " << endl; 
	    }
        else 
		{ 
			cout << "\nType conflict in Array Initialization... Ensure size/index i of array are same type" << endl; 
			return 1; 
        } 

		// declare an array on the stack  
		value_t a[size];  

		// initialize and time 
		auto s1 = std::chrono::high_resolution_clock::now(); 
        for(index_t i = 0; i < size; ++i) 
        { 
            a[i] =  i*x;
        } 
        auto s2 = std::chrono::high_resolution_clock::now(); 
	    std::chrono::duration<double, std::milli> init = s2-s1; 
       	cout << "\nMemory Access time a[i]*x:  " << std::fixed << setprecision(7) << init.count() << endl; 
              
        // correctness check   
	    value_t last_element = a[size-1]; // last element in the array 
		value_t last_index = size-1;      // the last element's index  
		if(last_element == 3*last_index)  // since initialized with 3 
		{ 
			cout << "\na[i]*x calculations performed correctly." << endl; 
		}
		else 
		{ 
			cout << "\nError in Initialization with a[i]*x" << endl; 
			return 1; 
		} 

        // prepare profiling results   
		// double t = init.count(); 
		// cout << std::fixed << setprecision(7) << t; 
		std::size_t bytes =  sizeof(a); 
        std::size_t elements = bytes / sizeof(value_t); 
        assert(elements == size); 
        assert(bytes == size*sizeof(value_t)); 
        std::string_view declaration = type_name<decltype(a)>(); 
    
        // write profiling results 
        writeToTerminal(declaration, dt, bytes, elements, init);   
        if (argc == 2)  {
        std::string file_path(argv[1]);
        writeToCSV(file_path, filename, dt, size, bytes, init); 
        }   
		
        // show array elements if needed     
        if (size <= 25) 
        { 
            printData(a); 
        }
        return 0; 
}