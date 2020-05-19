//UVa - 10038 - Jolly Jumpers

#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main() 
{
	bitset<3001> bits;
	int n, prev_num, next_num;

	while( scanf( "%d", &n ) != EOF )
	{
		bits = 0;                   
		scanf( "%d", &prev_num );

		for( int i{ 1 }; i < n; ++i )
		{
			scanf( "%d", &next_num );
			int diff{ abs( next_num - prev_num ) };

			if( diff >= n || diff == 0 || bits[diff] )
				bits[0] = 1;                            //Error flag

			bits[diff] = 1;
			prev_num = next_num;
		}

		bits[0] ? printf( "Not jolly\n" )
				: printf( "Jolly\n" );
	}
	return 0;
}													  