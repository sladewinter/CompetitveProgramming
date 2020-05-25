//UVa - 10161 - Ant on a Chessboard
//Arithmetic Progression, and then simulation

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	while( scanf( "%d", &N ), N )
	{
		int n{ (int)(sqrt(N) - 1) / 2 };
		int x{ 0 };
		int y{ 2 * n };

		--N;

		//Reach nearest sum of 8 + 16 + 24 +...
		int reached{ 4 * n * (n + 1) };

		while( reached < N )           //Just simulation
		{
			++y; 
			++reached;

			for(; x < y && reached < N; ++x, ++reached);
			for(; y > 0 && reached < N; --y, ++reached);

			if( reached == N )
				break;

			++x;
			++reached;

			for(; y < x && reached < N; ++y, ++reached);
			for(; x > 0 && reached < N; --x, ++reached);
		}

		printf( "%d %d\n", ++x, ++y );
	}
} 