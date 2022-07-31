#include <iostream> 
#include <typeinfo> 
#include <iomanip> 
//#include <array> 

int main()
{

    // print formatting
    #define COUT(x) std::cout << std::setw(12) << #x << " = " << sizeof(x) << " bytes  TYPE: " << typeid(x).name() << "\n" 
    std::cout << std::left; 

	// Example: 8 bytes * 4 bytes = 8 bytes 
	constexpr std::size_t y = 10; 
	constexpr int x = 5; 
	auto z = x*y; 

	COUT(x); 
    COUT(y);
	COUT(z);  // implicit cast to larger type happens 
	
	double q  = 3.0f; // passing float to a double implicitly casts  
    double r = 3;     
	COUT(q); 
	COUT(r); 
   
	return 0; 

} 
