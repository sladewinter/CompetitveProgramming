//UVa - 10264 - The Most Potent Corner
//Bitmask manipulation

#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
	int N;
	int corner[16384];
	int potency[16384];
	while( scanf( "%d", &N ) != EOF )
	{
		int corners( 1 << N );

		for( int i{0}; i < corners; ++i )
			scanf( "%d", &corner[i] );

		memset( potency, 0, sizeof(potency) );

		for( int i{0}; i < corners; ++i )
			for( int j{0}; j < N; ++j )
				potency[i] += corner[i^(1 << j)];

		int sum{ 0 };
		for( int i{0}; i < corners; ++i )
			for( int j{0}; j < N; ++j )
			{
				sum = max(sum, potency[i] + potency[i^(1 << j)]);
			}

		printf( "%d\n", sum );
	}
	return 0;
}                           
