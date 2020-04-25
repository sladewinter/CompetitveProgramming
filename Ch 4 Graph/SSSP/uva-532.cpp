//BFS - Implicit 3D graph - Flood fill variant
//UVa - 532 - Dungeon Master

#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;
using iiii = tuple<int, int, int, int>;
char grid[30][30][30];
int c_grid[30][30][30];

int main()
{
	//freopen( "input", "r", stdin );
	int L, R, C;                                  //No. of levels, rows, columns
	int st_x, st_y, st_z, end_x, end_y, end_z;    //Source and Destination
	int dl[6]{ 1, -1, 0,  0, 0,  0 };
	int dr[6]{ 0,  0, 1, -1, 0,  0 };
	int dc[6]{ 0,  0, 0,  0, 1, -1 };
	queue<iiii> q;
	while( scanf( "%d %d %d\n", &L, &R, &C ), L || R || C )
	{
		memset( c_grid, -1, sizeof( c_grid ) );
		for( int i{ 0 }; i < L; ++i )
			for( int j{ 0 }; j < R; ++j )
			{
				for( int k{ 0 }; k < C; ++k )
				{
					scanf( "%c", &grid[i][j][k] );
					if( grid[i][j][k] == 'S' )
                    {
						st_x = i;
                        st_y = j;
                        st_z = k;
                    }
					if( grid[i][j][k] == 'E' )
                    {
						end_x = i;
                        end_y = j;
                        end_z = k;
                    }
				}
                scanf( "\r\n" );
			}
		while( !q.empty() )
			q.pop();
		q.push({ st_x, st_y, st_z, 0 });

		int x, y, z, color;
		while( !q.empty() )                       //BFS traversal and coloring
		{
			tie( x, y, z, color ) = q.front();
			q.pop();

			if( x < 0 || x >= L || y <  0 || y >= R
		              || z <  0 || z >= C
		              || c_grid[x][y][z]  != -1
				      ||   grid[x][y][z]  == '#' )
				continue;

			c_grid[x][y][z] = color;

			if( x == end_x && y == end_y && z == end_z )
				break;

			for( int i{0}; i < 6; ++i )
				  q.push( {x + dl[i], y + dr[i], z + dc[i], color + 1} );
		}

		if( c_grid[end_x][end_y][end_z] == -1 )
			printf( "Trapped!\n" );
		else
			printf( "Escaped in %d minute(s).\n", c_grid[end_x][end_y][end_z] );
	}
    return 0;
}

