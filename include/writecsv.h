#pragma once 
#include <iostream> 
#include <string_view> // type_name() 
#include <fstream> // write to csv 
#include <string> //filename, args  
#include <chrono> 

void writeToCSV(std::string file_path, std::string filename, std::string_view value_type, std::string_view index_type, std::size_t size, std::size_t bytes, std::chrono::duration<double,std::milli> init, std::string_view am);   
