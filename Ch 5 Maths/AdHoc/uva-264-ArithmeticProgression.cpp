//UVa - 264 - Count on Cantor
//Arithmetic Progression and then Simulation

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	while( scanf( "%d", &N ) != EOF )
	{
		//Term in AP just before our target term
		int n{ (int)(sqrt(8*N - 7) - 1) / 2 };

		//Sum till this term
		int reached{ (n * (n + 1)) / 2 };

		++reached;            //Increase one term
		++n;
		
		int x, y;   
		if( n % 2 )                    //Odd term
		{
			x = n;
			y = 1;
		}
		else
		{
			x = 1;
			y = n;
		}

		while( reached < N )      //Just simulation
		{
			if( x < y )
			{
				while( y > 1 && reached < N )
				{
					--y;
					++x;
					++reached;
				}
			}

			else
			{
				while( x > 1 && reached < N )
				{
					--x;
					++y;
					++reached;
				}
			}
		}

		printf( "TERM %d IS %d/%d\n", N, x, y );
	}
} 