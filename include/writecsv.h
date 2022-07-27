#pragma once 
#include <iostream> 
#include <string_view> // type_name() 
#include <fstream> // write to csv 
#include <string> //filename, args  
#include <chrono> 

void writeToCSV(std::string file_path, std::string filename, std::string_view datatype, std::size_t size, std::size_t bytes, std::chrono::duration<double,std::milli> init); 

