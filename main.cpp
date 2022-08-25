#include "compresor.hpp"


int main(void)
{
	
  std::string line;
  std::string binary;
  std::ifstream myfile ("Makefile");
  if (myfile.is_open())
  {
    while (getline(myfile, line))
	{
		line += '\n';
	    binary += toBinary(line);
	}

	std::cout << binary << "\n\n";
	binary = compres(binary);
	std::cout << binary;
    myfile.close();
  }
  else std::cout << "Unable to read form file"; 

	return EXIT_SUCCESS;
}