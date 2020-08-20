#include "sumFileData.h"

int main(int ac, char **av) {
// Define a vector to store the strings received from input 
    // vector<string> strings_v; 
  
    // Define the filestream object used to read data from file 
    std::string f = av[1];
    // Get input stream and end of stream iterators 
    std::cout << sumFileData(f);
    // Get output stream iterators 
    // ostream_iterator<string> cout_it(cout, " "); 
  
    // // Copy elements from input to vector using copy function 
    // copy(fin_it, eos, back_inserter(strings_v)); 
  
    // // Sort the vector 
    // sort(strings_v.begin(), strings_v.end()); 
  
    // // Copy elements from vector to output 
    // copy(strings_v.begin(), strings_v.end(), cout_it); 
}