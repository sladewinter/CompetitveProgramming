//Kruskal's MST demonstration with an Edge List representation
//UVa 1174 - IP-TV
//Union-Find Implementation

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
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
  UnionFind( int M )                     //N = No. of vertices
  {
    parent.assign( M + 1, 0 );           //Set representative
    for( int i{1}; i <= M; ++i )
      parent[i] = i;

    rank.assign( M + 1, 0 );                 //For Union by Rank
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
  viii EdgeList( 50001 );
  unordered_map<string, int> str2int;
  int TC, M, N, cost, cityInd;
  string city1, city2;
  scanf( "%d", &TC );
  while( TC-- )
  {
    scanf("%d\n%d", &M, &N );

    cityInd = 0;
    str2int.clear();
    for( int i{ 0 }; i < N; ++i )
    {
      cin >> city1 >> city2 >> cost;
      if( !str2int[ city1 ] )
        str2int[ city1 ] = ++cityInd;

      if( !str2int[ city2 ] )
        str2int[ city2 ] = ++cityInd;

      EdgeList[i] = {cost, str2int[ city1 ], str2int[ city2 ] };
    }

    sort( EdgeList.begin(), EdgeList.begin() + N );

    int MST{ 0 };
    UnionFind UF{ M };
    int noEdges{ 0 };
    int s, d;
    for( int i{ 0 }; i < N; ++i )
    {
      tie( cost, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        continue;
      MST += cost;
      UF.unionSet( s, d );
      ++noEdges;
      if( noEdges == M - 1 )
        break;
    }
    printf( "%d\n", MST );
    if( TC )
      printf( "\n" );
  }
  return 0;
}
