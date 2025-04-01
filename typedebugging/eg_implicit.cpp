#include <iostream>
using std::cout; 
using std::endl; 
#include <array> // std::array 

int main()
{
    // Example: implicit casting of array elements   
    std::array<std::size_t, 10> a;     
    for (double i = 0; i < 10; ++i)        
    {
        a[i] = 4294967297; 
    }
    std::cout << "\n" <<  a[3] << endl;     
    auto x = a[3];  // x implicitly casted to type std::size_t  
    cout << "\nx is of type: " << typeid(x).name() << endl; 
    cout << "\nx has: " << sizeof(x) << " bytes" << endl; 

    return 0; 
} 
