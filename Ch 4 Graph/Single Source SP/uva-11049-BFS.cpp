//UVa - 11049 - Basic wall maze

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <queue>

using namespace std;

struct ii
{
	int x, y;
};

ii parent[6][6];
void backtrack( int u, int v ) 
{
	int x{ parent[u][v].x };
	int y{ parent[u][v].y };

	if( u == x && v == y )
		return;

	backtrack( x, y );

	if( u == x )
		( v < y ) ? printf( "N" ) : printf( "S" );
	else
		( u < x ) ? printf( "W" ) : printf( "E" );
}

int main()
{
	int dx[4]{ -1, 1, 0,  0 };
	int dy[4]{  0, 0, 1, -1 };
	bool con[36][36];
	bool visited[6][6];

	int sx, sy, ex, ey;
	while( scanf( "%d %d", &sx, &sy ), sx || sy )
	{
		scanf( "%d %d", &ex, &ey );
		--sx; --sy; --ex; --ey;
		queue<ii> que;
		memset( con, 0, sizeof(con) );
		memset( visited, 0, sizeof(visited) );
		int wx1, wy1, wx2, wy2;
		for( int i{0}; i < 3; ++i )
		{
			scanf( "%d %d %d %d", &wx1, &wy1, &wx2, &wy2 );
			if( wx1 == wx2 )
				for( int j{wy1}; j < wy2; ++j )
				{
					if(!wx1) continue;
					con[(wx1-1)*6 + j][wx1*6 + j] = 1; 
					con[wx1*6 + j][(wx1-1)*6 + j] = 1; 
				}

			else if( wy1 == wy2 )
				for( int j{wx1}; j < wx2; ++j )
				{
					if(!wy1) continue;
					con[j*6 + wy1-1][j*6 + wy1] = 1; 
					con[j*6 + wy1][j*6 + wy1-1] = 1; 
				}
		}
		//BFS
		visited[sx][sy] = true;
		
		for( int i{0}; i < 6; ++i )
			for( int j{0}; j < 6; ++j )
				parent[i][j] = {i, j};

		que.push({sx,sy});
		ii u;
		int x, y;
		bool reached{false};
		while( !que.empty() && !reached )
		{
			u =  que.front();
			que.pop();
			for( int i{0}; i < 4; ++i )
			{
				x = u.x + dx[i];
				y = u.y + dy[i];
				if( visited[x][y] || con[u.x*6 + u.y][x*6 + y] 
						 || x < 0 || x > 5 || y < 0 || y > 5 ) 
					
							continue;

				visited[x][y] = true;
				parent[x][y] = {u.x, u.y};
				if( x == ex && y == ey )
				{
					reached = true;
					break;
				}
				que.push({x, y});
			}
		}

		//Backtrack
		backtrack(ex, ey);
		printf( "\n" );
	}
}  