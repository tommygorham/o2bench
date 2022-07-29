#include <iostream> 
#include <array> 
int main()
{ 
	std::array<std::size_t, 10> a4; 
    std::cout << "bytes before:" << sizeof(a4[0]) << std::endl; 

	for(int i = 0; i < 10; ++i) 
	{ 
		a4[i] = i; 
	} 
	
	std::cout << "bytes after:" << sizeof(a4[0]) << std::endl; 

	return 0; 
} 


