//UVa - 382 - Perfection

#include <iostream>

using namespace std;

int main()
{
	printf( "PERFECTION OUTPUT\n" );
	int num;
	while( scanf( "%d", &num ), num )
	{
		int sum{ 1 };

		//Could do till sqrt(num) and take i & num/i
		for( int i{ 2 }; i <= num / 2; ++i )
			if( !(num % i) )
				sum += i;

		if( num > sum || num == 1 )
			printf( "%5d  DEFICIENT\n", num );
		else if( num < sum )
			printf( "%5d  ABUNDANT\n", num );
		else
			printf( "%5d  PERFECT\n", num );
	}
	printf( "END OF OUTPUT\n" );
} 