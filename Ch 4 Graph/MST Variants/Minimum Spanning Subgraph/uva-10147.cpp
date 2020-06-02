//Kruskal's MST demonstration with an Edge List representation
//UVa 10147 - Highways - Minimum Spanning Subgraph variant
//Union-Find Implementation

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using dd = pair<double, double>;
using dii = tuple<double, int, int>;
using vdii = vector<dii>;
using ii = pair<int, int>;

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

double dist( dd p1, dd p2 )              //Euclidean distance
{
  return sqrt( pow( p1.first - p2.first , 2 )
           +   pow( p1.second - p2.second , 2 ) );
}

int main()
{
  vdii EdgeList( 562501 );
  vector<dd> towns( 751 );
  int TC;
  scanf( "%d", &TC );
  while( TC-- )
  {
    int N;
    scanf( "%d", &N );
    for( int i{ 0 }; i < N; ++i )
      scanf( "%lf %lf", &towns[i].first, &towns[i].second );

    int E{ 0 };
    for( int i{0}; i < N - 1; ++i )
      for( int j{ i + 1 }; j < N; ++j )
        EdgeList[ E++ ] = { dist( towns[i], towns[j] ), i, j };

    sort( EdgeList.begin(), EdgeList.begin() + E );

    UnionFind UF{ N };
    int M, s, d;
    scanf( "%d", &M );
    for( int i{ 0 }; i < M; ++i )
    {
      scanf( "%d %d", &s, &d );
      UF.unionSet( --s, --d );         //Problem indices start at 1
    }

    int noEdges{ 0 };                     //Early stopping
    double w;
    for( int i{ 0 }; i < E; ++i )
    {
      tie( w, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        continue;
      UF.unionSet( s, d );
      printf( "%d %d\n", s + 1, d + 1 );
      ++noEdges;
      if( noEdges == N - 1 )             //Early stopping
        break;
    }
    if( !noEdges )
      printf( "No new highways need\n" );

    if( TC )
      printf( "\n" );
  }
  return 0;
}
