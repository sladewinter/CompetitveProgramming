//Kruskal's MST demonstration with an Edge List representation
//UVa 1234 - RACING - Maximum Spanning Tree Variant

/* Explanation - We have to place a camera in every possible cycle,
   so that total cost is minimum. This can be achieved by placing
   a camera in least cost edge of every cycle. To do this, we will
   try forming a maximum spanning tree, whenever an edge forms a
   cycle while doing so, that is least cost edge of a cycle   */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;
using viii = vector<iii>;
using vi = vector<int>;

class UnionFind
{
private:
  vi parent, rank;
public:
  UnionFind( int n )                     //N = No. of vertices
  {
    parent.assign( n, 0 );               //Set representative
    for( int i{0}; i < n; ++i )
      parent[i] = i;

    rank.assign( n, 0 );                 //For Union by Rank
  }

  int find( int u )
  {
    return ( parent[u] == u )
           ? u
           : ( parent[u] = find( parent[u] ) ); //Path compression
  }

  void unionSet( int u, int v )
  {
    int pu = find( u );                   //Parent of u
    int pv = find( v );                   //Parent of v
    if( pu == pv )                        //Already same set
      return;
    if( rank[pu] > rank[pv] )
      swap( pu, pv );                    //Keep pu shorter
    parent[pu] = pv;                     //Union by rank
    if( rank[pu] == rank[pv] )
      ++rank[pv];                        //Increase rank of pv
  }
};

int main()
{
  viii EdgeList( 100001 );
  int TC;
  scanf( "%d", &TC );
  while( TC-- )
  {
    int n, m;
    scanf( "%d %d", &n, &m );
    int s, d, w;
    for( int i{ 0 }; i < m; ++i )
    {
      scanf( "%d %d %d", &s, &d, &w );
      --s; --d;                   //Problem indices start from 1
      EdgeList[i] = {w, s, d};   //Reorder to sort easily
    }

    //Sort by non-increasing costs
    sort( EdgeList.begin(), EdgeList.begin() + m );
    reverse( EdgeList.begin(), EdgeList.begin() + m );

    int ans{ 0 };
    UnionFind UF{ n };

    //Don't break even after MST is complete, since any edge in
    //a connected undirected simple graph which is not in MST
    //forms a new cycle. And we need cam in every cycle.
    for( int i{ 0 }; i < m; ++i )
    {
      tie( w, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        ans += w;                         //Add a camera here
      else
        UF.unionSet( s, d );             //Add edge to MST
    }

    printf( "%d\n", ans );
  }
  return 0;
}
