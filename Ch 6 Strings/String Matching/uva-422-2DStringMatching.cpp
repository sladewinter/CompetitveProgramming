//UVa - 422 - Word Search Wonder

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int dx[7]{ 1, 1, 0, -1, -1,  0,  1};
	int dy[7]{ 0, 1, 1,  1, -1, -1, -1};
	char grid[100][100];
	char word[100];
	int len;
	scanf( "%d\n", &len );
	for( int i{0}; i < len; ++i )
		scanf( "%s", grid[i] );

	while( scanf( "%s", word ), strncmp(word, "0", 1) )
	{
		bool found{ false };
		int wlen{ (int)strlen(word) };

		for( int sx{0}; sx < len && !found; ++sx )
			for( int sy{0}; sy < len && !found; ++sy )
				if( grid[sx][sy] == word[0] )
					for( int d{0}; d < 7 && !found; ++d )
					{
						int ex{ sx + dx[d]*(wlen-1) };
						int ey{ sy + dy[d]*(wlen-1) };
						
						if( ex < 0 || ey < 0 || ex >= len
							|| ey >= len 
							|| grid[ex][ey] != word[wlen-1])

							continue;
						found = true;
						for( int i{1}; i < wlen && found; ++i )
							found = ( word[i] == grid[sx+dx[d]*i][sy+dy[d]*i] );
						
						if( found )
							printf( "%d,%d %d,%d\n", ++sx, ++sy, ++ex, ++ey );
					}

		if( !found )
			printf( "Not found\n" );
	}
	return 0;
}  