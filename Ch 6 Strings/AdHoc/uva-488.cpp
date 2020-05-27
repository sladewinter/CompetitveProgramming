//UVa - 488 - Triangle Wave
//Output Formatting

#include <iostream>
using namespace std;

int main()
{
	int tc;                     //No of test cases
	scanf( "%d", &tc );
	while( tc-- )
	{
		int amp, freq;         //Amplitude, Frequency

		scanf( "%d\n%d", &amp, &freq );
		string output{};

		for( int i{1}; i <= amp; ++i )
		{
			for( int j{1}; j <= i; ++j )
				output += i + '0'; 
			output += '\n';
		}
		for( int i{amp - 1}; i >= 1; --i )
		{
			for( int j{1}; j <= i; ++j )
				output += i + '0'; 
			output += '\n';
		}
		for( int k{0}; k < freq; ++k )
		{
			if(k)
				cout << '\n';
			cout << output;
		}
		if(tc)
			cout << '\n';
	}
} 
