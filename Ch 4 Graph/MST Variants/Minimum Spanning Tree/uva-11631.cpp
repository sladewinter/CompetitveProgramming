//Kruskal's MST demonstration with an Edge List representation
//UVa 11631 - Dark roads - Input also in Edge List format
//Union-Find Implementation

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
  UnionFind( int N )                     //N = No. of vertices
  {
    parent.assign( N, 0 );               //Set representative
    for( int i{0}; i < N; ++i )
      parent[i] = i;

    rank.assign( N, 0 );                 //For Union by Rank
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
  int m, n;
  viii EdgeList( 200001 );
  while( scanf( "%d %d", &m, &n ), m || n )
  {
    int initial_cost{ 0 };
    int s, d, w;
    for( int i{ 0 }; i < n; ++i )
    {
      scanf( "%d %d %d", &s, &d, &w );
      initial_cost += w;
      EdgeList[i] = {w, s, d};         //Reorder to sort easily
    }

    sort( EdgeList.begin(), EdgeList.begin() + n );

    int mst{ 0 };
    UnionFind UF{ m };
    int noEdges{ 0 };
    for( int i{ 0 }; i < n; ++i )
    {
      tie( w, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        continue;
      mst += w;
      UF.unionSet( s, d );
      ++noEdges;
      if( noEdges == n - 1 )
        break;
    }
    printf( "%d\n", initial_cost - mst );
  }
  return 0;
}
