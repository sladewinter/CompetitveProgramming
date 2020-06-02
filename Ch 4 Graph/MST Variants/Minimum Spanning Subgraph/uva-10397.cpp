//UVa - 10397 - Connect the Campus
//Minimum Spanning Subgraph

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;
using vi = vector<int>;
using vdii = vector< tuple<double, int, int> >;

class UnionFind
{
	vi parent, rank;

public:
	UnionFind( int n )
	{
		parent.assign(n, 0);
		rank.assign(n, 0);
		for( int i{0}; i < n; ++i)
			parent[i] = i;
	}
	int findSet(int u)
	{
		return (u == parent[u]) ? u
			: parent[u] = findSet(parent[u]);
	}
	void unionSet(int u, int v)
	{
		int p_u{ findSet(u) };
		int p_v{ findSet(v) };
		if( p_u == p_v ) return;

		if( rank[p_u] > rank[p_v] ) 
			swap(p_u, p_v);

		if( rank[p_u] == rank[p_v] )
			++rank[p_v];
		parent[p_u] = p_v;
	}
};

struct co                            //Coordinates
{
	int x, y;
};

double dist( co p1, co p2 )      //Euclidean distance
{
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() 
{
	int N, M;
	co loc[750];
	vdii EdgeList;

	while( scanf( "%d", &N ) != EOF )
	{
		for( int i{0}; i < N; ++i )
			scanf( "%d %d", &loc[i].x, &loc[i].y );

		EdgeList.clear();
		for( int u{0}; u < N - 1; ++u )
			for( int v{u + 1}; v < N; ++v )
				EdgeList.emplace_back(dist(loc[u], loc[v]),
													 u, v);
		
		sort( EdgeList.begin(), EdgeList.end() );

		UnionFind UF( N );
		scanf( "%d", &M );
		int u, v;
		while( M-- )
		{
			scanf( "%d %d", &u, &v );
			--u; --v;
			UF.unionSet(u, v);
		}

		double sum{ 0 };
		double len;
		for( auto &edge : EdgeList )
		{
			tie(len, u, v) = edge;
			if( UF.findSet(u) == UF.findSet(v) )		
				continue;
			sum += len;
			UF.unionSet(u, v);
		}
		printf( "%.2lf\n", sum );
	}
	return 0;
}                           
