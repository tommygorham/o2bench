#include "writecsv.h" 
#include <iomanip> 

void writeToCSV(std::string file_path, std::string filename, std::string_view value_type, std::string_view index_type, std::size_t size, std::size_t bytes,  std::chrono::duration<double,std::milli> init, std::string_view am)  
{

	double t = init.count(); // to avoid displaying time in scientific notation 
    std::ofstream csv_output;
    std::ifstream input_file;
    input_file.open(file_path);      
    if(!input_file){
        csv_output.open(file_path);
        if (!csv_output.is_open()){
        std::cout << "issue with csvoutput"; 
        }
        csv_output << "Filename" << ',' << "Valuetype" << ','  << "Index Type"  << ','  << "Problem Size" << ',' << "Bytes" << ','  << "Allocation-time" << ',' <<  "Access Method" << '\n';
        csv_output << filename   << ',' <<  value_type << ','  << index_type    << ','  <<  size          << ',' <<  bytes  << ','  <<  std::fixed <<  std::setprecision(7) <<  t << ',' << am << std::endl;
        csv_output.close();
        input_file.close(); 
    }
    else {
        csv_output.open(file_path, std::ios_base::app);
        csv_output << filename << ',' << value_type  << ',' << index_type << ',' <<  size << ',' << bytes << ',' << std::fixed <<
		std::setprecision(7)   << t << ',' << am <<  std::endl;
        csv_output.close();
        input_file.close(); 
     }
}
