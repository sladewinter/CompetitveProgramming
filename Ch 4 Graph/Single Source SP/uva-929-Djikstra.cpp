//UVa - 929 - Number Maze

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using iii = tuple<int, int, int>;
using viii = vector<iii>;
using vviii = vector<viii>;
using vvviii = vector<vviii>;
int main()
{
	constexpr int INF{ 1 << 30 };
	vvviii Adjmatrix;
	vvi dist;
	int tc, N, M;
	int dx[4]{ -1,  0, 1, 0 };
	int dy[4]{  0, -1, 0, 1 };
	scanf( "%d", &tc );
	int source;
	while( tc-- )
	{
		scanf( "%d\n%d", &N, &M );
		Adjmatrix.assign( N, vviii(M, viii()) );
		int w;
		for( int i{0}; i < N; ++i )
			for( int j{0}; j < M; ++j )
			{
				scanf( "%d", &w );

				if( !i && !j ) source = w;

				for( int k{0}; k < 4; ++k )
				{
					int x{ i + dx[k] };
					int y{ j + dy[k] };
					if( x < 0 || y < 0 || x >= N || y >= M )
						continue;
					Adjmatrix[x][y].emplace_back(w, i, j);
				}
			}

		//Run Djikstra
		dist.assign( N, vi(M, INF) );
		dist[0][0] = source;
		priority_queue<iii> pq;
		pq.push({-source, 0, 0});

		int d, x, y;
		int i, j;
		while( !pq.empty() )
		{
			tie(d, x, y) = pq.top();
			pq.pop();
			d = -d;

			if( d > dist[x][y] )
					continue;

			for( auto &v : Adjmatrix[x][y] )
			{
				tie(w, i, j) = v;
				if( dist[x][y] + w < dist[i][j] )
				{
					dist[i][j] = dist[x][y] + w;
					pq.push({-dist[i][j], i, j});
				}
			}
		}
		printf( "%d\n", dist[N-1][M-1] );
	}
}  