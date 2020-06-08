//UVa - 314 - Robot

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using iii = tuple<int, int, int>;

int grid[50][50];
int M, N;
bool canMove(int x, int y)
{
	if( x <= 0 || y <= 0 || x >= M || y >= N || grid[x-1][y-1] 
		       || grid[x-1][y] || grid[x][y-1] || grid[x][y] )
		return false;
	return true;
}

int main()
{
	constexpr int INF{ 1 << 30 };
	int dx[4]{ -1, 0, 1,  0};
	int dy[4]{  0, 1, 0, -1};

	int B1, B2, E1, E2;
	char dir[6];
	vvvi dist;
	while( scanf( "%d %d", &M, &N ), M || N )
	{
		for( int i{0}; i < M; ++i )
			for( int j{0}; j < N; ++j )
				scanf( "%d", &grid[i][j] );

		scanf( "%d %d %d %d %s", &B1, &B2, &E1, &E2, dir );
		int d;

		if( B1 == E1 && B2 == E2 )
		{
			printf( "%d\n", 0 );
			continue;
		}

		switch( dir[0] )
		{
			case 'n': d = 0; break;
			case 'e': d = 1; break;
			case 's': d = 2; break;
			case 'w': d = 3; break;
		}
		dist.assign( M, vvi(N, vi(4, INF)) );
		dist[B1][B2][d] = 0;
		queue<iii> que;
		que.push({B1, B2, d});

		int x, y;
		bool reached{ false };
		while( !que.empty() && !reached )
		{
			tie(x, y, d) = que.front();
			que.pop();

			//Turn right and left
			for( int i{1}; i <= 3; i += 2 )
				if( dist[x][y][(d+i) % 4] == INF )
				{
					dist[x][y][(d+i) % 4] = dist[x][y][d] + 1;
					que.push({x,y,(d+i) % 4});
				}

			//Move 1, 2 or 3 steps
			for( int i{1}; i <= 3; ++i )
			{
				int x1{ x + i * dx[d] };
				int y1{ y + i * dy[d] };
				if( canMove(x1, y1) )
				{
					if( dist[x1][y1][d] == INF )
					{
						dist[x1][y1][d] = dist[x][y][d] + 1;
						if( x1 == E1 && y1 == E2 )
						{
							reached = true;
							printf( "%d\n", dist[x1][y1][d] );
							break;
						}
						que.push({x1,y1,d});
					}
				}
				else
					break;				
			}
		}
		if(!reached) printf( "%d\n", -1 );
	}
}  