//UVa - 534 - Frogger
//MiniMax

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>

using namespace std;
using vi = vector<int>;
using di = pair<double, int>;
using vdi = vector<di>;
using vvdi = vector<vdi>;
using dii = tuple<double, int, int>;
using vdii = vector<dii>;

constexpr double INF{ 1e9 };

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

vvdi AdjMatrix;
double global;
int n;
bitset<200> visited;
void MiniMax( int u, double curr )
{
	if( u == 1 )
	{
		global = min(curr, global);
		return;
	}
	for( auto &v : AdjMatrix[u] )
	{
		if( !visited.test( v.second ) )
		{
			visited.set( v.second );
			MiniMax( v.second, max( curr, v.first ) );
			visited.reset( v.second );
		}
	}
}

int main()
{
  vdii EdgeList;
  int caseNo{ 0 };
  co loc[200];
  while( scanf( "%d", &n ), n )
  {
    for( int i{0}; i < n; ++i )
    	scanf( "%d %d", &loc[i].x, &loc[i].y );

    EdgeList.clear();
    for( int i{0}; i < n - 1; ++i )
    	for( int j{i + 1}; j < n; ++j )
    		EdgeList.emplace_back(dist(loc[i], loc[j]), 
    			                                 i, j);

    sort( EdgeList.begin(), EdgeList.end() );

    AdjMatrix.assign(n, vdi());
    UnionFind UF( n );
    int noEdges{ 0 };                 //Early stopping
    int s, d;
    double w;
    for( auto &edge : EdgeList )
    {
      tie( w, s, d ) = edge;
      if( UF.findSet( s ) == UF.findSet( d ) )  
        continue;
      UF.unionSet( s, d );
      ++noEdges;
      AdjMatrix[s].emplace_back(w, d);
      AdjMatrix[d].emplace_back(w, s);

      if( noEdges == n - 1 )
      	break;
    }
    
    global = INF;
    visited = 0;
    MiniMax(0, 0);
    printf( "Scenario #%d\nFrog Distance = %.3lf\n\n",
                                   ++caseNo, global );
  }
  return 0;
}
