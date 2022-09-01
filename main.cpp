#include "compresor.hpp"


int main(void)
{

	std::string line;
	std::string binary;
	char	c;
	std::ifstream myfile ( "utils.cpp" );


	if ( myfile.is_open() )
	{
		while ( myfile.get( c ) )
			binary += c;

		binary = toBinary( binary.c_str() );

		std::cout << binary;
		binary = compres( binary );
		// std::cout << binary;
		myfile.close();
	}
	else
		std::cout << "Unable to read form file"; 

	return EXIT_SUCCESS;
}