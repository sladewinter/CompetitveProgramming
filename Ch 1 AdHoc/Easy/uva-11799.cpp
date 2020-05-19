//UVa - 11799 - Horror Dash
#include <iostream>
using namespace std;
int main() 
{
	int T, N, c;                     //Problem parameters
	int caseNo{ 0 };
	scanf( "%d", &T );
	while( T-- )
	{
		int maxi{ 0 };              //Maximum speed
		scanf( "%d", &N );
		while( N-- )
		{
			scanf( "%d", &c );
			maxi = max( maxi, c );
		}
		printf( "Case %d: %d\n", ++caseNo, maxi );
	}
	return 0;
}													  