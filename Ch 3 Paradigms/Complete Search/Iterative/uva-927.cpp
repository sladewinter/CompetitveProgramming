//UVa - 927 - Integer Sequences from Addition of Terms
//Iterative Complete Search with pruning

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int C, i, d, k;               //Problem parameters
	int c[21];                   //Polynomial coefficients
	scanf("%d", &C);
	while( C-- )
	{
		scanf("%d", &i);             //i=polynomial degree
		for( int j{0}; j <= i; ++j )
			scanf("%d", &c[j]);      //Coefficients   

		scanf( "%d\n%d", &d, &k ); 

		int pos{ 0 };           //Get position of polynomial
		int cum{ 0 };          //Cumulate till we cross k

		while( cum + ( d * ++pos ) < k )   //Iteratively search position
			cum += d * pos;               //Prune once we found it

		long long sum{0};

		for( int j{0}; j <= i; ++j )      //Compute reqd. polynomial
			sum += c[j] * pow( pos, j );

		printf( "%lld\n", sum );
	}
}