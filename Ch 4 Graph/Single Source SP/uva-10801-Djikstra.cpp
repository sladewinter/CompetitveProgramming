//UVa - 10801 - Lift Hopping

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main()
{
	constexpr int INF{ 1 << 30 };
	vvi lifts;
	vvi dist;
	int n, k;              //n = No of elevators, k = destination
	int T[5];
	bool visits[5][100];
	while( scanf( "%d %d", &n, &k ) != EOF )
	{
		for( int lift{0}; lift < n; ++lift )
			scanf( "%d", &T[lift] );

		memset( visits, 0, sizeof(visits) );
		lifts.assign(n, vi());

		string line;
		int floor;
		scanf( "\n" );
		for( int lift{0}; lift < n; ++lift )
		{
			getline(cin, line);
			stringstream os{ line };
			while( os >> floor )
			{
				visits[lift][floor] = 1;
				lifts[lift].push_back(floor);
			}
		}
		if( k == 0 )
		{
			printf( "%d\n", 0 );
			continue;
		}

		priority_queue<iii> pq;
		dist.assign(n, vi(100, INF));
		for( int lift{0}; lift < n; ++lift )
			if( visits[lift][0] )
				pq.push({0, lift, 0});

		int time, lift;
		while( !pq.empty() )
		{
			tie(time, lift, floor) = pq.top();
			pq.pop();
			time = -time;

			if( time > dist[lift][floor] )
				continue;

			for( auto &next : lifts[lift] )
			{
				if( next != floor )
				{
					int d{ abs(next - floor) * T[lift] };
					if( dist[lift][next] > time + d )
					{
						dist[lift][next] = time + d;
						pq.push({-dist[lift][next], lift, next});
					}
					//break;
				}
			}
			for( int other{0}; other < n; ++other )
				if( other != lift && visits[other][floor] )
					if( dist[other][floor] > time + 60 )
					{
						dist[other][floor] = time + 60;
						pq.push({-dist[other][floor], other, floor});
					}
		}
		time = INF;
		for( lift = 0; lift < n; ++lift )
			if( visits[lift][k] )
				time = min(time, dist[lift][k]);

		(time != INF ) ? printf( "%d\n", time )
					   : printf( "IMPOSSIBLE\n" );
	}
}  