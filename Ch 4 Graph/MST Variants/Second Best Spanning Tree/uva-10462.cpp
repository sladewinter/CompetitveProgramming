//UVa - 10462 - Is There A Second Way Left?
//Second Best Spanning Tree

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
using vi = vector<int>;
using iii = tuple<int, int, int>;
using viii = vector<iii>;

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

viii EdgeList;
vi MST;
int v, e;
int spanning( int ignore )
{
	UnionFind UF( v );
	int u1, u2, len;
	int sum{ 0 };
	int noEdges{ 0 };
	for( int i{0}; i < e; ++i )
	{
		if( i == ignore )
			continue;

		tie(len, u1, u2) = EdgeList[i];
		if( UF.findSet(u1) == UF.findSet(u2) )		
			continue;

		if( ignore == -1 )
			MST.push_back(i);

		sum += len;
		UF.unionSet(u1, u2);
		++noEdges;
		if( noEdges == v - 1 )
			break;
	}
	return (noEdges == v - 1) ? sum : -1;
}

int main() 
{
	int t, start, end, cost;
	int caseNo{ 0 };
	constexpr int INF{ 1 << 30 };
	scanf( "%d", &t );
	while( t-- )
	{
		scanf( "%d %d", &v, &e );

		EdgeList.assign( e, iii() );
		MST.clear();
		for( int i{0}; i < e; ++i )
		{
			scanf( "%d %d %d", &start, &end, &cost );
			EdgeList[i] = {cost, --start, --end};
		}

		sort( EdgeList.begin(), EdgeList.end() );
		printf( "Case #%d : ", ++caseNo );

		if( spanning(-1) == -1 )
		{
			printf( "No way\n" );
			continue;
		}

		int second{ INF };
		for( auto &i : MST )
		{
			int best{ spanning(i) };
			if( best == -1 )
				continue;
			second = min(second, best);
		}
		if( second == INF )
			printf( "No second way\n" );
		else
			printf( "%d\n", second );
	}
	return 0;
}                           
