//BFS - Implicit graph - Flood fill variant
//UVa - 10653 - Bombs! NO they are Mines!!

#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;
using iii = tuple<int, int, int>;
int grid[1000][1000];

int main()
{
	//freopen( "input", "r", stdin );
	int R, C;                                   //Total no. of rows, columns
	int end_x, end_y;                          //Destination
	int row, col, rows, cols;                 //For bomb locations
	int st_x, st_y;                          //Source
	int dr[4]{  1, 0, -1, 0};
	int dc[4]{  0, 1,  0,-1};
	queue<iii> q;
	while( scanf( "%d %d", &R, &C ), R || C )
	{
		memset( grid, 0, sizeof( grid ) );
		scanf( "%d", &rows );
		while( rows-- )
		{
			scanf( "%d %d", &row, &cols );
			while( cols-- )
			{
				scanf( "%d", &col );
				grid[row][col] = -1;
			}
		}
		scanf( "%d %d\n%d %d", &st_x, &st_y, &end_x, &end_y );
		while( !q.empty() )
			q.pop();
		q.push({ st_x, st_y, 1 });   //Starting with 1, so subtract 1 later
		int x, y, color;
		while( !q.empty() )                     //BFS traversal and coloring
		{
			tie( x, y, color ) = q.front();
			q.pop();

			if( x < 0 || x >= R || y < 0 || y >=C || grid[x][y] != 0 
			 				      || grid[x][y] == -1 )
				continue;

			grid[x][y] = color;

			if( x == end_x && y == end_y )
 				break;

			for( int i{0}; i < 4; ++i )
				  q.push( {x + dr[i], y + dc[i], color + 1} );
		}
		printf( "%d\n", grid[end_x][end_y] - 1 );    //Subtract 1 and print
	}
    return 0;
}

