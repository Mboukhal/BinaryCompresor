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
	int one = 0, zero = 0;
	std::string comp;
	comp += str[0];
	comp += " \n";
	float strsize = (float)str.size();
	for (int i = 0; i < (int)strsize; i++)
	{
		if (str[i] == '0')
		{
			while (str[i++] == '0')
				zero++;
			if (zero > 9)
			{
				comp += '.';
				comp += std::to_string(zero);
				comp += '.';

			}
			else
				comp += zero + '0';
				zero = 0;
				// last = 0;
		}
		else if (str[i] == '1')
		{
			while (str[i++] == '1')
				one++;
			if (one > 9)
			{
				comp += '.';
				comp += std::to_string(one);
				comp += '.';
			}
			else
				comp += one + '0';
			one = 0;
		}
		std::cout <<'[' << i << ']'<< std::endl;
	}
	float compsize = (float)comp.size();
	std::cout << "size of str: " << strsize
			  << " size of comp: " << compsize
			  << " comprese porsontage: " << (100 - ((compsize * 100) / strsize))
			  << "%"
			  << std::endl; 
	return comp;
}

