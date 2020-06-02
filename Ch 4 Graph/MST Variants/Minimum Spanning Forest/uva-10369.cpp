//Kruskal's MST demonstration with an Edge List representation
//UVa 10369 - Arctic Network - Minimum Spanning Forest variant
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
  vdii EdgeList( 250001 );
  dd outposts[ 500 ];
  int N;
  scanf( "%d", &N );
  while( N-- )
  {
    int S, P;
    scanf( "%d %d", &S, &P );
    for( int i{ 0 }; i < P; ++i )
      scanf( "%lf %lf", &outposts[i].first, &outposts[i].second );

    int E{ 0 };
    for( int i{0}; i < P - 1; ++i )
      for( int j{ i + 1 }; j < P; ++j )
        EdgeList[ E++ ] = { dist( outposts[i], outposts[j] ), i, j };

    sort( EdgeList.begin(), EdgeList.begin() + E );

    UnionFind UF{ P };
    double w;
    int s,d;
    int noComponents{ P };                 //Early stopping
    for( int i{ 0 }; i < E; ++i )
    {
      tie( w, s, d ) = EdgeList[i];
      if( UF.find( s ) == UF.find( d ) )  //This edge forms cycle
        continue;
      UF.unionSet( s, d );
      --noComponents;
      if( noComponents == S )             //Early stopping
      {
        printf( "%.2lf\n", w );
        break;
      }
    }

  }
  return 0;
}
