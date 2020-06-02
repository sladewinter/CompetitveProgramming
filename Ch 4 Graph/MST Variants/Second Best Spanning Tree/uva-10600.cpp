//Kruskal's MST demonstration with an Edge List representation
//UVa 10600 - ACM Contest and Blackout - Second best Spanning Tree
//Union-Find Implementation

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using iii = tuple<int, int, int>;

iii EdgeList[ 5001 ];
int N, M;

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

int SpanningWeight( int ignore )
{
  UnionFind UF{ N };
  int noEdges{ 0 };
  int w, s, d;
  int mst{ 0 };
  for( int i{ 0 }; i < M; ++i )
    if( i != ignore )
    {
      tie( w, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        continue;
      UF.unionSet( s, d );
      mst += w;
      ++noEdges;
      if( noEdges == N - 1 )             //Early stopping
        break;
    }
  if( noEdges < N - 1 )
    mst = 999999;
  return mst;
}

int main()
{
  int T;
  scanf( "%d", &T );
  while( T-- )
  {
    scanf( "%d %d", &N, &M );

    int A, B, C;
    for( int i{ 0 }; i < M; ++i )
    {
      scanf( "%d %d %d", &A, &B, &C );

      //In problem indices start at 1
      EdgeList[i] = { C, --A, --B };
    }

    sort( EdgeList, EdgeList + M );

    UnionFind UF{ N };
    int w, s, d;
    int noEdges{ 0 };                      //Early stopping
    int mst{ 0 };
    int sst{ 999999 };
    for( int i{ 0 }; i < M; ++i )
    {
      tie( w, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        continue;
      UF.unionSet( s, d );
      ++noEdges;
      mst += w;
      sst = min( sst, SpanningWeight( i ) );
      if( noEdges == N - 1 )                 //Early stopping
        break;
    }
    printf( "%d %d\n", mst, sst );
  }
  return 0;
}
