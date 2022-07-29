#include <iostream> 
#include <typeinfo> 
#include <array> 

int main()
{ 
	// 8 bytes * 4 bytes = 8 bytes example 
	constexpr std::size_t y = 10; 
	constexpr int x = 5; 
	auto z = x*y; 
	std::cout << "\nsizeof int x: "    << sizeof(x) 
	          << "\nsizeof size_t y: " << sizeof(y) 
			  << "\nz: " << z 
			  << "\nsizeof auto z: "   << sizeof(z) 
			  << std::endl;
	 std::cout << "\nz is of type:  " << typeid(z).name() << std::endl; 	
     double q  = 3.0f; 
     double r = 3; 
     std::cout << "\nq is of type:  " << typeid(q).name() << std::endl; 	
	 std::cout << "\nr is of type:  " << typeid(r).name() << std::endl; 	
     
	 std::array<int, 10> a2; 

	// int == i example  
	
	/*using type1 = int;
	using type2 = std::size_t; 
	std::cout << "\ntype1 has the type: " << typeid(type1).name() << std::endl; 
    std::cout << "\ntype2 has the type: " << typeid(type2).name() << std::endl; 
    auto x = typeid(type1).name();  
    std::cout << x; 
    std::cout << typeid(double).name(); 
    */ 
	return 0; 

} 
