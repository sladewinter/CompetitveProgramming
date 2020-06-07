//UVa - 11264 - Coin Collector

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int T, n, C[1000];
	scanf( "%d", &T );
	while( T-- )
	{
		int X{0}, coins{0};

		scanf( "%d", &n );
		scanf( "%d", &C[0] );

		for( int i{1}; i < n; ++i )
		{
			scanf( "%d", &C[i] );

			//Current sum should be strictly lesser than 
			//next coin, else next coin will just eat it up
			if( X + C[i-1] < C[i] )
			{
				X += C[i-1];
				++coins;
			}
		}
		//Since current sum definitely lesser than last coin,
		//add the last coin too
		printf( "%d\n", ++coins );
	}
}  