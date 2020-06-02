//UVa - 1216 - The Bug Sensor Problem
//Minimum Spanning Forest

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
	int w;
	co loc[100000];
	vdii EdgeList;

	scanf( "%d", &w );
	while( w-- )
	{
		int tr;
		scanf( "%d", &tr );

		int temp;
		int n{ 0 };
		while( scanf( "%d", &temp ), temp != -1 )
		{
			loc[n].x = temp;
			scanf( "%d", &loc[n++].y );
		}

		EdgeList.clear();
		for( int u{0}; u < n - 1; ++u )
			for( int v{u + 1}; v < n; ++v )
				EdgeList.emplace_back(dist(loc[u], loc[v]),
													 u, v);
		
		sort( EdgeList.begin(), EdgeList.end() );

		UnionFind UF( n );

		int u, v;
		int maxi{ 0 };
		double len;
		int noComponents{ n };
		for( auto &edge : EdgeList )
		{
			tie(len, u, v) = edge;
			if( UF.findSet(u) == UF.findSet(v) )		
				continue;
			maxi = max( maxi, (int)ceil(len) );
			UF.unionSet(u, v);
			--noComponents;
			if( noComponents == tr )
				break;
		}
		printf( "%d\n", maxi );
	}
	return 0;
}                           
