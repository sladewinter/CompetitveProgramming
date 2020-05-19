//UVa - 11498 - Division of Nlogonia
#include <iostream>
using namespace std;
int main() 
{
	int K, N, M, X, Y;
	while( scanf( "%d", &K ), K )
	{
		scanf( "%d %d", &N, &M );
		while( K-- )
		{
			scanf( "%d %d", &X, &Y );
			X -= N; 
			Y -= M;
			if( !X || !Y ) printf( "divisa\n" );
			else if( X > 0 && Y > 0 ) printf( "NE\n" );
			else if( X > 0 && Y < 0 ) printf( "SE\n" );
			else if( X < 0 && Y < 0 ) printf( "SO\n" );
			else if( X < 0 && Y > 0 ) printf( "NO\n" );
		}
	}
	
	return 0;
}													  