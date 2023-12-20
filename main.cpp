// #include "compresor.hpp"
#include <iostream>
#include <fstream>
#include <bitset>

// int main(void)
// {

// 	std::string line;
// 	std::string binary;
// 	char	c;
// 	std::ifstream myfile ( "utils.cpp" );


// 	if ( myfile.is_open() )
// 	{
// 		while ( myfile.get( c ) )
// 			binary += c;

// 		binary = toBinary( binary.c_str() );

// 		std::cout << binary;
// 		binary = compres( binary );
// 		// std::cout << binary;
// 		myfile.close();
// 	}
// 	else
// 		std::cout << "Unable to read form file"; 

// 	return EXIT_SUCCESS;
// }


void countBinaryString(const std::string& binaryString) {

		std::string newData = "";

		newData = binaryString[0];
		newData += '\n';

		int zeros = 0, ones = 0;
		for (char c : binaryString) {
				if (c == '0') {
						zeros++;
						
				} else if (c == '1') {
						ones++;
				}
		}

		// Print the results
		std::cout << "data: " << newData << std::endl;
		std::cout << "Number of 0s: " << zeros << std::endl;
		std::cout << "Number of 1s: " << ones << std::endl;
}

int main() {
    // Specify the file name
    const char* filename = "utils.cpp";

    // Open the file in binary mode
    std::ifstream file(filename, std::ios::binary);

    // Check if the file is opened successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1; // Exit with an error code
    }

		std::string binaryString;


    // Read and print binary values from the file
    char byte;
    while (file.read(&byte, sizeof(char))) {
        std::bitset<8> bits(byte);
				binaryString += bits.to_string();
    }

		// countBinaryString(binaryString);

		std::cout << binaryString << std::endl;

    // Close the file
    file.close();

    return 0; // Exit successfully
}



// ---- layer 1 ----
// 0
// 
// 213.1023423*120-234324/324532(5),