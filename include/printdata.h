#pragma once
template <typename T> 
void printData(const T &data){ 
	for(auto& i:data) 
		std::cout << i << std::endl; 
} 
