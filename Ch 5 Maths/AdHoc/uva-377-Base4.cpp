//UVa - 377 - Cowculations
//Base 4 operations

#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

int main()
{
	int N;
	scanf( "%d\n", &N );
	printf( "COWCULATIONS OUTPUT\n" );
	while( N-- )
	{
		int num1[8]{};
		for( int i{3}; i < 8; ++i )
		{
			switch( getchar() )
			{
				case 'V': num1[i] = 0; break;
				case 'U': num1[i] = 1; break;
				case 'C': num1[i] = 2; break;
				case 'D': num1[i] = 3; break;
			}
		}
		scanf( "\n" );

		int num2[8]{};
		for( int i{3}; i < 8; ++i )
		{
			switch( getchar() )
			{
				case 'V': num2[i] = 0; break;
				case 'U': num2[i] = 1; break;
				case 'C': num2[i] = 2; break;
				case 'D': num2[i] = 3; break;
			}
		}
		scanf( "\n" );

		for( int i{0}; i < 3; ++i )
		{
			switch( getchar() )
			{
				case 'A':
				{
					int c{ 0 };
					int s{ 0 };
					for( int i{7}; i > 0 ; --i )
					{
						s = c + num1[i] + num2[i];
						num2[i] = s % 4;
						c =  s / 4;
					}
					break;
				}
				case 'R': 
					for( int i{7}; i > 0 ; --i )
						num2[i] = num2[i-1];
					num2[0] = 0;
					break;

				case 'L': 
					for( int i{0}; i < 7; ++i )
						num2[i] = num2[i+1];
					num2[7] = 0;
					break;

				case 'N': break;
			}
			scanf( "\n" );
		}

		int result[8]{};
		bool pos{true};
		for( int i{0}; i < 8; ++i )
		{
			switch( getchar() )
			{
				case 'V': result[i] = 0; break;
				case 'U': result[i] = 1; break;
				case 'C': result[i] = 2; break;
				case 'D': result[i] = 3; break;
			}
			if(pos)
				pos = ( result[i] == num2[i] );
		}
		scanf( "\n" );
		pos ? printf( "YES\n" ) : printf( "NO\n" );
	}
	printf( "END OF OUTPUT\n" ); 
	return 0;
}
