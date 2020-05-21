//UVa 10004 - Bicoloring
//Bipartite Graph Check using modified DFS

#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

constexpr int INF{ 1 << 30 };
vvi AdjList;
vi colors;

bool bipartite( int u )                 //Modified DFS
{
  for( auto &v : AdjList[u] )
  {
    if( colors[v] == INF )
    {
      colors[v] = 1 - colors[u];
      if( !bipartite( v ) )
        return false;
    }
    else if( colors[v] == colors[u] )
      return false;
  }
  return true;
}


int main()
{
  int n, l, temp1, temp2;

  while( scanf( "%d", &n ), n )
  {
    AdjList.assign( n, vi() );
    scanf( "%d", &l );
    while( l-- )
    {
      scanf( "%d %d", &temp1, &temp2 );
      AdjList[ temp1 ].push_back( temp2 );
      AdjList[ temp2 ].push_back( temp1 );
    }

    colors.assign( n, INF );
    colors[0] = 0;                       //Assign color 0 to source

    if( bipartite( 0 ) )                //Modified DFS
      printf( "BICOLORABLE.\n" );
    else
      printf( "NOT BICOLORABLE.\n" );

  }
  return 0;
}