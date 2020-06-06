//UVa - 183 - Bit Maps

#include <iostream>
#include <cmath>

using namespace std;

char grid[200][200];
int c{ 0 };
void B2D( int sx, int sy, int ex, int ey )
{
	if( sx > ex || sy > ey )
		return;
	char bit{ grid[sx][sy] };
	bool same{ true };
	for( int i{sx}; i <= ex && same; ++i )
		for( int j{sy}; j <= ey && same; ++j )
			same = ( grid[i][j] == bit );

	if( c % 50 == 0)
		printf( "\n" );

	++c;
	if( same )
		printf( "%c", bit );
	else
	{
		printf( "%c", 'D' );
		B2D(sx, sy, ( sx + ex ) / 2, ( sy + ey ) / 2);
		B2D(sx, ( sy + ey ) / 2 + 1, ( sx + ex ) / 2, ey);
		B2D(( sx + ex ) / 2 + 1, sy, ex, ( sy + ey ) / 2);
		B2D(( sx + ex ) / 2 + 1, ( sy + ey ) / 2 + 1, ex, ey);
	}
}

void D2B( int sx, int sy, int ex, int ey )
{
	if( sx > ex || sy > ey )
		return;
	char ch{};
	do
	{
		scanf( "%c", &ch );
	}while( ch != '1' && ch != '0' && ch != 'D' );

	if( ch != 'D' )
	{
		for( int i{sx}; i <= ex; ++i )
			for( int j{sy}; j <= ey; ++j )
				grid[i][j] = ch;
	}
	else
	{
		D2B(sx, sy, ( sx + ex ) / 2, ( sy + ey ) / 2);
		D2B(sx, ( sy + ey ) / 2 + 1, ( sx + ex ) / 2, ey);
		D2B(( sx + ex ) / 2 + 1, sy, ex, ( sy + ey ) / 2);
		D2B(( sx + ex ) / 2 + 1, ( sy + ey ) / 2 + 1, ex, ey);
	}
}

int main()
{
	char form;
	int row, col;
	scanf( "%c", &form );
	while( form != '#' )
	{
		scanf( "%d", &row );
		scanf( "%d", &col );

		if( form == 'B' )
		{
			for( int i{ 0 }; i < row; ++i )
				for( int j{ 0 }; j < col; ++j )
				{
					do
					{
						scanf( "%c", &grid[i][j] );
					}while( grid[i][j] != '1' && grid[i][j] != '0');
				}
			scanf( "\n" );
			printf( "D%4d%4d", row, col );
			c = 0;
			B2D(0, 0, row-1, col-1);
			printf( "\n" );
		}
		if( form == 'D')
		{
		    printf( "B%4d%4d", row, col );
			D2B(0, 0, row-1, col-1);
			
			for( int i{ 0 }; i < row; ++i )
				for( int j{ 0 }; j < col; ++j )
				{
					if( (i * col + j)% 50 == 0 )
						printf( "\n" );

					printf( "%c", grid[i][j] );
				}
			printf( "\n" );
		}
		scanf( "%c", &form );

	}
	
}  