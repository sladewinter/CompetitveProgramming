//UVa - 10773 - Back to Intermediate Math

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int tc;                  //Test cases
	scanf( "%d", &tc );

	int caseNo{ 0 };
	while( tc-- )
	{
		int d, v, u;        //Problem parameters

		scanf( "%d %d %d", &d, &v, &u );

		printf( "Case %d: ", ++caseNo );

		if( !u || !v || u <= v )
		{
			printf( "can't determine\n" );
			continue;
		}

		printf( "%.3lf\n", (d / sqrt(u*u - v*v))
					   	     - ((double)d / u) );
	}
} 