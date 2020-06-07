//UVa - 10656 - Maximum Sum (II)

#include <iostream>

using namespace std;

int main()
{
	int N;
	while( scanf( "%d", &N ), N )
	{
		int sum{ 0 };
		int num{ 0 };
		bool first{ true };
		for( int i{ 0 }; i < N; ++i )
		{
			scanf( "%d", &num );
			sum += num;
			if( num )
			{
				(first) ? first = false : printf( " " );
				printf( "%d", num );
			}
		}
		if( !sum ) printf( "%d", 0 );
		printf( "\n" );
	}
}  