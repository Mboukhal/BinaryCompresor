#include "compresor.hpp"
 
std::string toBinary( std::string const &str )
{
    std::string binary;

	for ( int i = 0; i < (int)str.size(); i++ )
        binary += std::bitset<8>( str[i] ).to_string();
    return binary;
}

std::string compres( std::string const &str )
{
	int one = 0, zero = 0;
	std::string comp;
	comp += str[0];
	comp += " \n";
	float strsize = (float)str.size();

	for ( int i = 0; i < (int)strsize; i++ ) {

		if ( str[i] == '0' ) {

			while ( str[i++] == '0' )
				zero++;
			if ( zero > 9 ){

				comp += '.';
				comp += std::to_string(zero).size();
				comp += std::to_string(zero);

			}
			else
				comp += zero + '0';
			zero = 0;
		}
		else if ( str[i] == '1' ) {

			while ( str[i++] == '1' )
				one++;
			if ( one > 9 ) {

				comp += '.';
				comp += std::to_string( one ).size();
				comp += std::to_string( one );
			}
			else
				comp += one + '0';
			one = 0;
		}
	}

	float compsize = (float)comp.size(), porsontage = (100 - ((compsize * 100) / strsize));

	std::cout << "\n\t\tsize of str: \t\t" << strsize
			  << "\n\t\tsize of comp: \t\t" << compsize;
	printf( "\n\t\tcomprese porsontage: \t%.2lf%%\n", porsontage );
	return comp;
}

