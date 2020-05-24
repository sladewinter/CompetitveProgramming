//UVa - 10751 - Chessboard

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int tc;
	scanf( "%d", &tc );
	while( tc-- )
	{
		int size;
		scanf( "%d", &size );

		double length{ 0 };
		if( size == 2 )
			length = 4;
		else if( size > 2 )
		{
			int root2{ (size - 2) * (size - 2) };

			length += (size * size) - root2;
			length += root2 * sqrt(2);
		}
		printf( "%.3lf\n", length );
		if( tc )
			printf( "\n" );
	}
} 