#include <iostream>
using std::cout; 
using std::endl; 
#include <array> 
// what was learned: on a 64-bit arch , your maximum size of size_t is 64 bits 
// 
int main()
{
	/* t1  
    constexpr std::size_t size = 70000;
    std::array<std::size_t, 10> a;     
	
	for (double i = 0; i < 10; ++i)        
	{
		a[i] = 4294967299;
	}
	std::cout << "\n" <<  a[3] << endl;     
	
	auto x = a[3]; 
	std::array<int, 10> b;      
	
	cout << "\nx is of type: " << typeid(x).name() << endl; 
    cout << "'n x has: " << sizeof(x) << " bytes" << endl; 
    */ 
    
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
	//cout << a.size(); 
	// cout << b.size(); 
	//auto aSize = std::size(a);     
	//auto bSize = std::size(b);
	return 0; 
} 
