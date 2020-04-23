//Kruskal's MST demonstration with an Edge List representation
//UVa 908 - Re-connecting Computer Sites
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
  int N;
  viii EdgeList( 10000001 );
  bool first{ true };
  while( scanf( "%d", &N ) != EOF )
  {
    first ? first = false : printf( "\n" );
    int init{ 0 };
    int s, d, w;
    for( int i{ 0 }; i < N - 1; ++i )
    {
      scanf( "%d %d %d", &s, &d, &w );
      init += w;
    }

    int K;
    scanf( "%d", &K );
    for( int i{ 0 }; i < K; ++i )
    {
      scanf( "%d %d %d", &s, &d, &w );
      //Indices start from 1 in problem, from 0 in our solution
      --s; --d;
      EdgeList[i] = {w, s, d};         //Reorder to sort easily
    }

    int M;
    scanf( "%d", &M );
    for( int i{ K }; i < K + M; ++i )
    {
      scanf( "%d %d %d", &s, &d, &w );
      //Indices start from 1 in problem, from 0 in our solution
      --s; --d;
      EdgeList[i] = {w, s, d};        //Reorder to sort easily
    }

    int E{ K + M };
    sort( EdgeList.begin(), EdgeList.begin() + E );

    int final{ 0 };
    UnionFind UF{ N };
    int noEdges{ 0 };
    for( int i{ 0 }; i < E; ++i )
    {
      tie( w, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        continue;
      final += w;
      UF.unionSet( s, d );
      ++noEdges;
      if( noEdges == N - 1 )
        break;
    }

    printf( "%d\n%d\n", init, final );
  }
  return 0;
}
