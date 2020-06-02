//UVa - 10842 - Traffic Flow
//Maximum Spanning Tree

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
using vi = vector<int>;
using viii = vector< tuple<int, int, int> >;

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

int main() 
{
	int N, n, m, u, v, c;
	viii EdgeList;
	int caseNo{ 0 };
	scanf( "%d", &N );
	while( N-- )
	{
		scanf( "%d %d", &n, &m );

		EdgeList.clear();
		while( m-- )
		{
			scanf( "%d %d %d", &u, &v, &c );
			if( u == v )
				continue;
			EdgeList.emplace_back(-c, u, v);
		}

		sort( EdgeList.begin(), EdgeList.end() );

		UnionFind UF( n );
		int noEdges{ 0 };
		int mini{ n > 1 ? 999999999 : 0 };
		for( auto &edge : EdgeList )
		{
			tie(c, u, v) = edge;
			if( UF.findSet(u) == UF.findSet(v) )		
				continue;
			mini = min( mini, -c );
			UF.unionSet(u, v);
			++noEdges;
			if( noEdges == n - 1 )
				break;
		}
		printf( "Case #%d: %d\n", ++caseNo, mini );
	}
	return 0;
}                           
