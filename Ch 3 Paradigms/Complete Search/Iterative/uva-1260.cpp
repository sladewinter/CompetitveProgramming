//UVa - 1260 - Sales
//Iterative Complete Search

#include <iostream>
using namespace std;

int main()
{
	int T, A[1000], n;             //Problem paramters

	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d", &n );

		int sum{ 0 };
		for( int i{0}; i < n; ++i )
		{
			scanf( "%d", &A[i] );

			for( int j{0}; j < i; ++j )   //On the fly
				if( A[j] <= A[i] )
					sum += 1;
		}
		printf( "%d\n", sum );
	}
}