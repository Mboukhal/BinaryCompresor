#include "compresor.hpp"
 
std::string toBinary(std::string const &str)
{
    std::string binary;

	for (int i = 0; i < (int)str.size(); i++)
        binary += std::bitset<8>(str[i]).to_string();
    return binary;
}

std::string compres(std::string const &str)
{
	int one = 1, zero = 1, last = str[0] - '0';
	std::string comp;
	comp += str[0];
	comp += " \n";
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] == '0')
		{
			if (last == 1)
			{
				comp += zero + '0';
				zero = 1;
				last = 0;
			}
			else
				zero++;
		}
		else if (str[i] == '1')
		{
			if (last == 0)
			{
				comp += one + '0';
				one = 1;
				last = 1;
			}
			else
				one++;
		}
	}
	int strsize = (int)str.size();
	int compsize = (int)comp.size();
	std::cout << "size of str: " << strsize
			  << " size of comp: " << compsize
			  << " comprese porsontage: " << 100 - ((compsize * 100) / strsize)
			  << "%"
			  << std::endl; 
	return comp;
}

