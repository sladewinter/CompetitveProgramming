//UVa - 11727 - Cost Cutting
#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
	int T, sal[3];
	int caseNo{ 0 };
	scanf( "%d", &T );
	while( T-- )
	{
		scanf( "%d %d %d", &sal[0], &sal[1], &sal[2] );
		sort( sal, sal + 3 );
		printf( "Case %d: %d\n", ++caseNo, sal[1] );
	}
	
	return 0;
}													  