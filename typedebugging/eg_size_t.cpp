#include <iostream>
using std::cout; 
using std::endl; 
#include <array> // std::array 
#include <limits> // std::numeric_limits 

int main()
{
    // Example2:  on a 64-bit arch , your maximum size of size_t is 64 bits 
	constexpr std::size_t size = 70000;
	std::array<std::size_t, 10> a;
    cout << sizeof(a[0]) << "bytes at " << 0 << endl;
	a[0] = 3294967297;
	a[1] = 4294967297;
	a[2] = 4294967298;
	a[3] = 4294967299;
	for (int i = 0; i < 4; i++) 
    {
		cout << "Value of a at " << i <<  ": " << a[i] << endl;
	    cout << "a is size "
	         << sizeof(a[i]) << "bytes at " << i << endl;
    }

	cout << "\n\nsize_t: " << std::numeric_limits<std::size_t>::max() << endl;  
	return 0; 
} 
