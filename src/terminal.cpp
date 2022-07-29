#include "terminal.h" 
#include <iostream> 

void writeToTerminal(std::string_view declaration, std::string_view value_type, std::string_view index_type, std::size_t
bytes, std::size_t elements, std::chrono::duration<double, std::milli> init, std::string_view am)  
{
	   double t = init.count(); 
	   std::cout << "\nDeclaration, " << declaration 
	             << "\nElement Type Stored: " << value_type 
				 << "\nindexed with " <<  index_type 
				 << "\nSize in Bytes: " << bytes 
				 << "\nNum Elements: " << elements
				 << "\nAccess Time(ms): " << t 
	             << "\nAccess Method: " << am 
				 << std::endl;  
} 
